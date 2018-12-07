#include "socc3.h"

socc3::socc3(QObject *parent): QObject(parent)
{
}

void socc3:: writeFILE(QByteArray str)
{
    QString filename="/home/students/s434672/Desktop/data.txt";
    QFile file( filename );
    file.resize(0);
    if ( file.open(QIODevice::ReadWrite) )
    {
            QTextStream stream( &file );
            stream <<  str;
        }
    file.close();
}


QString socc3::Test(QString name)
{
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));

    qDebug() << "Connecting...";
    socket->connectToHost("pc14f", 5009);

    if(!(socket->waitForConnected(1000)))
    {
        qDebug() << "Error: " << socket->errorString();
        return socket->errorString();
    }

    QByteArray help;
    help.append(name);
    socket->write("c");
    socket->waitForBytesWritten(1000);
    socket->write(help);
    socket->waitForBytesWritten(1000);

    socket->waitForReadyRead(1000);
    qDebug() << "Reading: " << socket->bytesAvailable() << " bytes";

    help.clear();

    while (1)
    {
        socket->waitForReadyRead(1000);
        qDebug() << "Reading: " << socket->bytesAvailable() << " bytes";
        if (socket->bytesAvailable()== 0 )
        {
            qDebug() <<"Wyszłem";
            break;
        }
        help.append(socket->readAll());
    }
    writeFILE(help);
    socket->disconnect();
    return "File read.";
}

void socc3::connected ()
{
    qDebug() << "Connected";
}

void socc3::disconnected ()
{
    qDebug() << "Disconnected";
}

void socc3::bytesWritten (qint64 bytes)
{
    qDebug() << "Wrote: " << bytes;
}

void socc3::readyRead()
{
    qDebug() << "Reading...";
}


