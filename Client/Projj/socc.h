#ifndef SOCC_H
#define SOCC_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QAbstractSocket>
#include <string>
#include <iostream>

using namespace std;

class socc : public QObject
{
    Q_OBJECT
    public:
    explicit socc(QObject * parent = 0);
    void Test();
    //void Connect();

    signals:

    public slots:
    void connected ();
    void disconnected ();
    void bytesWritten (qint64 bytes);
    void readyRead();

private:
    QTcpSocket *socket;
};

#endif // SOCC_H

