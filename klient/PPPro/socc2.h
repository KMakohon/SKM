#ifndef SOCC2_H
#define SOCC2_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QFile>
#include <QAbstractSocket>
#include <string>
#include <iostream>
#include <string>
#include <string.h>
#include <QDataStream>
#include <QString>


class socc2: public QObject
{
    Q_OBJECT
public:
    explicit socc2(QObject * parent = 0);
    QString Test();
    void writeFILE(QByteArray str);
    QString readFILE();

signals:

public slots:
    void connected ();
    void disconnected ();
    void bytesWritten (qint64 bytes);
    void readyRead();

private:
    QTcpSocket *socket;
};

#endif // SOCC2_H
