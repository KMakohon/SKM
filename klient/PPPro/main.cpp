#include "mainwindow.h"
#include <QApplication>
#include <QPlainTextEdit>
#include <QFile>
#include <QtWidgets>

// DSIK 2018 Zofia Dobrowolska(klient)

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
