/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Jun 3 13:05:36 2012
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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QTableWidget *tableAP;
    QLabel *label_5;
    QPushButton *airbaseBtn;
    QLineEdit *essidBox;
    QLabel *label_4;
    QProgressBar *progressBar;
    QLabel *label_3;
    QLabel *airmonStatus;
    QPushButton *airmonBtn;
    QLabel *label_2;
    QPushButton *btn1;
    QTableWidget *tableClient;
    QPushButton *ssl;
    QPushButton *closeBtn;
    QPushButton *btn2;
    QPushButton *refreshBtn;
    QPushButton *deauthAll;
    QPushButton *deauthClnt;
    QWidget *tab_2;
    QLabel *label_6;
    QTextEdit *packetInfo;
    QPushButton *sslRefresh;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(859, 567);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 841, 491));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 100, 81, 17));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        tableAP = new QTableWidget(tab);
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
        tableAP->setGeometry(QRect(20, 130, 371, 181));
        tableAP->setMaximumSize(QSize(12345, 16777215));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 360, 191, 31));
        QFont font1;
        font1.setPointSize(15);
        label_5->setFont(font1);
        airbaseBtn = new QPushButton(tab);
        airbaseBtn->setObjectName(QString::fromUtf8("airbaseBtn"));
        airbaseBtn->setEnabled(false);
        airbaseBtn->setGeometry(QRect(210, 400, 93, 27));
        essidBox = new QLineEdit(tab);
        essidBox->setObjectName(QString::fromUtf8("essidBox"));
        essidBox->setEnabled(false);
        essidBox->setGeometry(QRect(90, 400, 113, 21));
        essidBox->setReadOnly(false);
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 400, 71, 17));
        label_4->setFont(font1);
        progressBar = new QProgressBar(tab);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(380, 60, 118, 23));
        progressBar->setMaximum(10000);
        progressBar->setValue(24);
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(260, 10, 141, 41));
        label_3->setFont(font1);
        airmonStatus = new QLabel(tab);
        airmonStatus->setObjectName(QString::fromUtf8("airmonStatus"));
        airmonStatus->setGeometry(QRect(380, 20, 62, 21));
        QFont font2;
        font2.setPointSize(10);
        airmonStatus->setFont(font2);
        airmonBtn = new QPushButton(tab);
        airmonBtn->setObjectName(QString::fromUtf8("airmonBtn"));
        airmonBtn->setGeometry(QRect(440, 20, 93, 27));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(510, 100, 101, 17));
        label_2->setFont(font);
        btn1 = new QPushButton(tab);
        btn1->setObjectName(QString::fromUtf8("btn1"));
        btn1->setEnabled(false);
        btn1->setGeometry(QRect(390, 360, 151, 27));
        tableClient = new QTableWidget(tab);
        if (tableClient->columnCount() < 2)
            tableClient->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableClient->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableClient->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        tableClient->setObjectName(QString::fromUtf8("tableClient"));
        tableClient->setEnabled(false);
        tableClient->setGeometry(QRect(400, 130, 301, 181));
        tableClient->setMinimumSize(QSize(256, 0));
        tableClient->horizontalHeader()->setMinimumSectionSize(27);
        ssl = new QPushButton(tab);
        ssl->setObjectName(QString::fromUtf8("ssl"));
        ssl->setEnabled(false);
        ssl->setGeometry(QRect(390, 400, 151, 27));
        closeBtn = new QPushButton(tab);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setGeometry(QRect(720, 400, 93, 27));
        btn2 = new QPushButton(tab);
        btn2->setObjectName(QString::fromUtf8("btn2"));
        btn2->setGeometry(QRect(720, 360, 93, 27));
        refreshBtn = new QPushButton(tab);
        refreshBtn->setObjectName(QString::fromUtf8("refreshBtn"));
        refreshBtn->setEnabled(false);
        refreshBtn->setGeometry(QRect(720, 270, 93, 27));
        deauthAll = new QPushButton(tab);
        deauthAll->setObjectName(QString::fromUtf8("deauthAll"));
        deauthAll->setEnabled(false);
        deauthAll->setGeometry(QRect(720, 210, 93, 27));
        deauthClnt = new QPushButton(tab);
        deauthClnt->setObjectName(QString::fromUtf8("deauthClnt"));
        deauthClnt->setEnabled(false);
        deauthClnt->setGeometry(QRect(720, 150, 111, 27));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(60, 30, 221, 31));
        QFont font3;
        font3.setPointSize(13);
        label_6->setFont(font3);
        packetInfo = new QTextEdit(tab_2);
        packetInfo->setObjectName(QString::fromUtf8("packetInfo"));
        packetInfo->setGeometry(QRect(110, 90, 611, 261));
        sslRefresh = new QPushButton(tab_2);
        sslRefresh->setObjectName(QString::fromUtf8("sslRefresh"));
        sslRefresh->setEnabled(false);
        sslRefresh->setGeometry(QRect(370, 390, 93, 27));
        tabWidget->addTab(tab_2, QString());
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

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "<AP List>", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableAP->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableAP->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "BSSID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableAP->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Channel", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:15pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Fake AP Generator</p></body></html>", 0, QApplication::UnicodeUTF8));
        airbaseBtn->setText(QApplication::translate("MainWindow", "Turn On", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:15pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Name : </span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:15pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Scanning : </p></body></html>", 0, QApplication::UnicodeUTF8));
        airmonStatus->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:15pt; color:#ff0000;\">Off</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        airmonBtn->setText(QApplication::translate("MainWindow", "Turn On", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "<Client List>", 0, QApplication::UnicodeUTF8));
        btn1->setText(QApplication::translate("MainWindow", "Packet Capture", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableClient->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableClient->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "MAC Address", 0, QApplication::UnicodeUTF8));
        ssl->setText(QApplication::translate("MainWindow", "SSL Strip", 0, QApplication::UnicodeUTF8));
        closeBtn->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
        btn2->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        refreshBtn->setText(QApplication::translate("MainWindow", "Refresh", 0, QApplication::UnicodeUTF8));
        deauthAll->setText(QApplication::translate("MainWindow", "Deauth All", 0, QApplication::UnicodeUTF8));
        deauthClnt->setText(QApplication::translate("MainWindow", "Deauth Client", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Main", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "<SSL-Stripped Packets>", 0, QApplication::UnicodeUTF8));
        sslRefresh->setText(QApplication::translate("MainWindow", "Refresh", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Packet", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
