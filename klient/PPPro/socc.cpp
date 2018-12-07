#include "socc.h"

socc::socc(QObject *parent): QObject(parent)
{

}

QString socc::Test(QString file_name, QString name)
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
    QByteArray help2;
    QFile Fi(file_name);
    qint32 size = Fi.size();
    QString help3 = QString::number(size);

    help.append(help3);
    help2.append(name);
    qDebug() << "File size:" << size;

    socket->write("a");
    socket->waitForBytesWritten(1000);

    socket->write(help2);
    socket->waitForBytesWritten(10000);

    socket->waitForReadyRead(3000);
    QString ss = socket->readAll();
    qDebug() << ss;
    if (ss.compare("n")== 0)
    {
        return "You can't change this file.";
    }

    socket->waitForReadyRead(3000);
    ss = socket->readAll();

    socket->write(help);
    socket->waitForBytesWritten(1000);

    socket->waitForReadyRead(3000);
    ss = socket->readAll();
    qDebug() << ss;

    QByteArray read;

    Fi.open(QIODevice::ReadOnly);
    while(1)
    {
        read.clear();
        read = Fi.read(1023);
        qDebug() << "Read size: " << read.size();
        if(read.size()==0)
        {
            break;
        }
        qDebug() << "Written : " << socket->write(read);
        socket->waitForBytesWritten();
        read.clear();

        socket->waitForReadyRead(3000);
        qDebug() << "Reading: " << socket->bytesAvailable() << " bytes";
        ss = socket->readAll();
        qDebug() << ss;
        ss.clear();
    }

    Fi.close();
    qDebug() << "Transfer completed";
    socket->disconnect();
    return "File sended.";
}

void socc::connected ()
{
    qDebug() << "Connected";
}

void socc::disconnected ()
{
    qDebug() << "Disconnected";
    return;
}

void socc::bytesWritten (qint64 bytes)
{
    qDebug() << "Wrote: " << bytes;
}

void socc::readyRead()
{
    qDebug() << "Reading...";
}

