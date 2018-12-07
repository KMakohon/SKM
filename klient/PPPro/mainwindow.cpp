#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "socc.h"
#include "socc2.h"
#include "socc3.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    socc socket1;
    QString var1, var2;
    var1 = ui->lineEdit->text();
    var2 = ui->lineEdit_2->text();
    var1 = var1 + ".txt";

    if (var1.length() > 14)
    {
        QMessageBox::information(0,"Error","File name is too long!");
    }
    else if(var2.length() ==0 && var1.length() == 4)
    {
        QMessageBox::information(0,"Error","Insert file name and path.");
    }
    else if(var1.length() == 4)
    {
        QMessageBox::information(0,"Error","Insert file name.");
    }
    else if(var2.length() == 0)
    {
        QMessageBox::information(0,"Error","Insert file path.");
    }
    else if(var2.length()>0 && var1.length() == 4)
    {
        QMessageBox::information(0,"Error","Insert file name.");
    }
    else
    {
        QString inf = socket1.Test(var2, var1);
        QMessageBox::information(0,"Info",inf);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    socc2 socket2;
    QString infos = socket2.Test();
    QFile Fill("/home/students/s434672/Desktop/data.txt");

    if(infos.compare("List read.") != 0)
    {
        QMessageBox::information(0,"Error",infos);
    }

    else
    {
        if(!Fill.open(QIODevice::ReadOnly))
        {
            QMessageBox::information(0,"Error",Fill.errorString());
        }
        else{
            QTextStream in(&Fill);
            ui->textBrowser->setText(in.readAll());
            Fill.close();
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    socc3 socket3;
    QString var3 = ui->lineEdit_3->text();
    if (var3.length() == 0)
    {
        QMessageBox::information(0,"Error","Insert file name.");
    }
    else
    {
        QString info = socket3.Test(var3);

        if (info.compare("File read.") != 0)
        {
            QMessageBox::information(0,"Error",info);
        }
        else
        {
            QFile Fill("/home/students/s434672/Desktop/data.txt");

            if(!Fill.open(QIODevice::ReadOnly))
            {
                QMessageBox::information(0,"info",Fill.errorString());
            }
            QTextStream in(&Fill);
            ui->textBrowser_2->setText(in.readAll());
        }
    }
}
