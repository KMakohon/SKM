#include "socc.h"

socc::socc(QObject *parent): QObject(parent)
{
}


/*void socc::Connect()
{
    socket = new QTcpSocket(this);
    socket->connectToHost("pc25l", 5007);

    if(socket->waitForConnected(3000))
    {
        qDebug() << "Connected";

        socket->write("d");
        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);

        qDebug() << "Reading: " << socket->bytesAvailable();
        qDebug() << socket->readAll();
    }
    else
    {
        qDebug() << "Not Connected!";
    }

}
*/

void socc::Test()
{
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));

    qDebug() << "Connecting...";

    socket->connectToHost("pc25l", 5007);

    if(!(socket->waitForConnected(1000)))
    {
        qDebug() << "Error: " << socket->errorString();
    }
}

void socc::connected ()
{
    qDebug() << "Connected";
    socket->write("d");
    socket->waitForBytesWritten(1000);

    socket->waitForReadyRead(3000);

    qDebug() << "Reading: " << socket->bytesAvailable();
    qDebug() << socket->readAll();
}

void socc::disconnected ()
{
    qDebug() << "Disconnected";
}

void socc::bytesWritten (qint64 bytes)
{
    qDebug() << "Wrote: " << bytes;
}

void socc::readyRead()
{
    qDebug() << "Reading...";
    qDebug() << socket->readAll();
}


