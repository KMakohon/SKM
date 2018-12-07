#include "socc2.h"

socc2::socc2(QObject *parent): QObject(parent)
{

}

void socc2:: writeFILE(QByteArray str)
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


QString socc2::Test()
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

    socket->write("b");
    socket->waitForBytesWritten(1000);

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
    return "List read.";
}

void socc2::connected ()
{
    qDebug() << "Connected";
}

void socc2::disconnected ()
{
    qDebug() << "Disconnected";
    return;
}

void socc2::bytesWritten (qint64 bytes)
{
    qDebug() << "Wrote: " << bytes;
}

void socc2::readyRead()
{
    qDebug() << "Reading...";
}

