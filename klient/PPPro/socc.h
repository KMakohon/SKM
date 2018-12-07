#ifndef SOCC_H
#define SOCC_H

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


class socc: public QObject
{
    Q_OBJECT
public:
    explicit socc(QObject * parent = 0);
    QString Test(QString file_name, QString name);

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
