#ifndef UI_PROJEKT_SIECI_H
#define UI_PROJEKT_SIECI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFrame *zad1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLineEdit *lineEdit_3;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QFrame *zad2;
    QGridLayout *gridLayout;
    QTreeWidget *treeWidget;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QFrame *zad3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLabel *label_5;
    QFrame *frame_7;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_3;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(945, 706);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(frame_2);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        zad1 = new QFrame(frame_2);
        zad1->setObjectName(QStringLiteral("zad1"));
        zad1->setFrameShape(QFrame::StyledPanel);
        zad1->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(zad1);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_6 = new QLabel(zad1);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_4->addWidget(label_6);

        lineEdit_3 = new QLineEdit(zad1);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        horizontalLayout_4->addWidget(lineEdit_3);


        verticalLayout->addWidget(zad1);

        frame_5 = new QFrame(frame_2);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_4 = new QLabel(frame_5);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        lineEdit = new QLineEdit(frame_5);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addWidget(frame_5);

        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        verticalLayout_3->addWidget(frame_2);

        zad2 = new QFrame(centralwidget);
        zad2->setObjectName(QStringLiteral("zad2"));
        zad2->setFrameShape(QFrame::StyledPanel);
        zad2->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(zad2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        treeWidget = new QTreeWidget(zad2);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        gridLayout->addWidget(treeWidget, 1, 0, 1, 1);

        frame_6 = new QFrame(zad2);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(frame_6);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        pushButton_2 = new QPushButton(frame_6);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        gridLayout->addWidget(frame_6, 0, 0, 1, 1);


        verticalLayout_3->addWidget(zad2);

        zad3 = new QFrame(centralwidget);
        zad3->setObjectName(QStringLiteral("zad3"));
        zad3->setFrameShape(QFrame::StyledPanel);
        zad3->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(zad3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(zad3);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_5 = new QLabel(zad3);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);

        frame_7 = new QFrame(zad3);
        frame_7->setObjectName(QStringLiteral("frame_7"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_7);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        lineEdit_2 = new QLineEdit(frame_7);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        verticalLayout_4->addWidget(lineEdit_2);

        pushButton_3 = new QPushButton(frame_7);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_4->addWidget(pushButton_3);

        textBrowser = new QTextBrowser(frame_7);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout_4->addWidget(textBrowser);


        verticalLayout_2->addWidget(frame_7);


        verticalLayout_3->addWidget(zad3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 945, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "1. Wyslij plik na serwer.", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Podaj pod jaka nazwa ma figurować plik na serwerze.", Q_NULLPTR));
        lineEdit_3->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "Podaj pełną ścieżke do pliku:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Wyślij", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Nazwa pliku", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", " 2. Przejżyj liste plików.", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Wyświetl", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "3. Odczyt pliku.", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Podaj nazwe piku:", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Wyświetl", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE



#endif // UI_PROJEKT_SIECI_H
