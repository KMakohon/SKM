#ifndef SOCC3_H
#define SOCC3_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QFile>
#include <QAbstractSocket>
#include <string>
#include <iostream>
#include <string>

using namespace std;

class socc3 : public QObject
{
    Q_OBJECT
public:
    explicit socc3(QObject * parent = 0);
    QString Test(QString name);
    void writeFILE(QByteArray str);

signals:

public slots:
    void connected ();
    void disconnected ();
    void bytesWritten (qint64 bytes);
    void readyRead();

private:
    QTcpSocket *socket;
};

#endif // SOCC3_H
