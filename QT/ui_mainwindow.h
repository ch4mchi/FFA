/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon May 7 10:10:55 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btn1;
    QComboBox *comboBox;
    QPushButton *btn2;
    QTableWidget *tableAP;
    QTableWidget *tableClient;
    QPushButton *deauthClnt;
    QPushButton *deauthAll;
    QPushButton *refreshBtn;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *airmonStatus;
    QPushButton *airmonBtn;
    QLabel *label_4;
    QPushButton *airbaseBtn;
    QLineEdit *essidBox;
    QLabel *label_5;
    QPushButton *closeBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(859, 454);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        btn1 = new QPushButton(centralWidget);
        btn1->setObjectName(QString::fromUtf8("btn1"));
        btn1->setGeometry(QRect(550, 350, 93, 27));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(450, 350, 89, 31));
        btn2 = new QPushButton(centralWidget);
        btn2->setObjectName(QString::fromUtf8("btn2"));
        btn2->setGeometry(QRect(740, 330, 93, 27));
        tableAP = new QTableWidget(centralWidget);
        if (tableAP->columnCount() < 3)
            tableAP->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableAP->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableAP->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableAP->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableAP->setObjectName(QString::fromUtf8("tableAP"));
        tableAP->setEnabled(false);
        tableAP->setGeometry(QRect(20, 110, 371, 181));
        tableAP->setMaximumSize(QSize(12345, 16777215));
        tableClient = new QTableWidget(centralWidget);
        if (tableClient->columnCount() < 2)
            tableClient->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableClient->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableClient->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        tableClient->setObjectName(QString::fromUtf8("tableClient"));
        tableClient->setEnabled(false);
        tableClient->setGeometry(QRect(410, 110, 301, 181));
        tableClient->setMinimumSize(QSize(256, 0));
        tableClient->horizontalHeader()->setMinimumSectionSize(27);
        deauthClnt = new QPushButton(centralWidget);
        deauthClnt->setObjectName(QString::fromUtf8("deauthClnt"));
        deauthClnt->setEnabled(false);
        deauthClnt->setGeometry(QRect(730, 110, 111, 27));
        deauthAll = new QPushButton(centralWidget);
        deauthAll->setObjectName(QString::fromUtf8("deauthAll"));
        deauthAll->setEnabled(false);
        deauthAll->setGeometry(QRect(730, 170, 93, 27));
        refreshBtn = new QPushButton(centralWidget);
        refreshBtn->setObjectName(QString::fromUtf8("refreshBtn"));
        refreshBtn->setEnabled(false);
        refreshBtn->setGeometry(QRect(730, 230, 93, 27));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 80, 81, 17));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(520, 80, 101, 17));
        label_2->setFont(font);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(260, 10, 101, 21));
        QFont font1;
        font1.setPointSize(15);
        label_3->setFont(font1);
        airmonStatus = new QLabel(centralWidget);
        airmonStatus->setObjectName(QString::fromUtf8("airmonStatus"));
        airmonStatus->setGeometry(QRect(360, 10, 62, 21));
        QFont font2;
        font2.setPointSize(10);
        airmonStatus->setFont(font2);
        airmonBtn = new QPushButton(centralWidget);
        airmonBtn->setObjectName(QString::fromUtf8("airmonBtn"));
        airmonBtn->setGeometry(QRect(420, 10, 93, 27));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 350, 101, 17));
        label_4->setFont(font1);
        airbaseBtn = new QPushButton(centralWidget);
        airbaseBtn->setObjectName(QString::fromUtf8("airbaseBtn"));
        airbaseBtn->setGeometry(QRect(220, 350, 93, 27));
        essidBox = new QLineEdit(centralWidget);
        essidBox->setObjectName(QString::fromUtf8("essidBox"));
        essidBox->setGeometry(QRect(100, 350, 113, 21));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 320, 101, 21));
        label_5->setFont(font1);
        closeBtn = new QPushButton(centralWidget);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setGeometry(QRect(740, 370, 93, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 859, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        btn1->setText(QApplication::translate("MainWindow", "Show Info", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "ASDF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "SDFG", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "WEWB", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "QGEW", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Awkenv", 0, QApplication::UnicodeUTF8)
        );
        btn2->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableAP->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableAP->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "BSSID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableAP->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Channel", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableClient->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableClient->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "MAC Address", 0, QApplication::UnicodeUTF8));
        deauthClnt->setText(QApplication::translate("MainWindow", "Deauth Client", 0, QApplication::UnicodeUTF8));
        deauthAll->setText(QApplication::translate("MainWindow", "Deauth All", 0, QApplication::UnicodeUTF8));
        refreshBtn->setText(QApplication::translate("MainWindow", "Refresh", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "<AP List>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "<Client List>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:15pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:15pt;\">Airmon : </span></p></body></html>", 0, QApplication::UnicodeUTF8));
        airmonStatus->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:15pt; color:#ff0000;\">Off</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        airmonBtn->setText(QApplication::translate("MainWindow", "Turn On", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:15pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">ESSID : </span></p></body></html>", 0, QApplication::UnicodeUTF8));
        airbaseBtn->setText(QApplication::translate("MainWindow", "Turn On", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:15pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">Airbase</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        closeBtn->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
