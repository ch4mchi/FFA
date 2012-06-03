#include "mainwindow.h"
//#include "sslwindow.h"
#include "FunctionList.h"
#include <QProcess>
#include <QString>
#include <QTextStream>
#include <QFile>
#include <QCoreApplication>
#define APP_CURRENT_PATH QCoreApplication::applicationDirPath()
MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	//UI connection
        QObject::connect(ui->btn1, SIGNAL(clicked()), this, SLOT(captureFunc()));
	QObject::connect(ui->btn2, SIGNAL(clicked()), this, SLOT(showBitchbox()));
	QObject::connect(ui->airmonBtn, SIGNAL(clicked()), this, SLOT(airmonFunc()));
	QObject::connect(ui->airbaseBtn, SIGNAL(clicked()), this, SLOT(airbaseFunc()));
	QObject::connect(ui->refreshBtn, SIGNAL(clicked()), this, SLOT(refreshFunc()));
	QObject::connect(ui->tableAP, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(selectAP()));
	QObject::connect(ui->tableClient, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(selectClnt()));
	QObject::connect(ui->deauthAll, SIGNAL(clicked()), this, SLOT(deauthAllFunc()));
	QObject::connect(ui->deauthClnt, SIGNAL(clicked()), this, SLOT(deauthClntFunc()));
	QObject::connect(ui->closeBtn, SIGNAL(clicked()), this, SLOT(close()));
	QObject::connect(ui->ssl, SIGNAL(clicked()), this, SLOT(openSSLWindow()));
	QObject::connect(ui->sslRefresh, SIGNAL(clicked()), this, SLOT(openSSLWindow()));

	ui->progressBar->setVisible(false);

	//ui->tableAP->setSortingEnabled(true);
	ui->tableAP->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableAP->horizontalHeader()->setStretchLastSection(true);
	ui->tableAP->verticalHeader()->hide();
	ui->tableAP->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableAP->setSelectionMode(QAbstractItemView::SingleSelection);
	ui->tableAP->horizontalHeader()->resizeSection(0, 120);
	ui->tableAP->horizontalHeader()->resizeSection(1, 160);
	ui->tableAP->horizontalHeader()->resizeSection(2, 40);

	//ui->tableClient->setSortingEnabled(true);
	ui->tableClient->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableClient->horizontalHeader()->setStretchLastSection(true);
	ui->tableClient->verticalHeader()->hide();
	ui->tableClient->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableClient->setSelectionMode(QAbstractItemView::SingleSelection);
	ui->tableClient->horizontalHeader()->resizeSection(0, 100);
	ui->tableClient->horizontalHeader()->resizeSection(1, 140);
}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::selectClnt()
{
	ui->deauthClnt->setEnabled(true);
}

void MainWindow::showBitchbox(){
	int ret;
        QMessageBox::information(NULL,"About","Wireless Phishing Attack Scenario\n\nAutomation Tool");
}

void MainWindow::openSSLWindow()
{
    QString line;
    QFile *file = new QFile;
    QString filename = "/pentest/web/sslstrip/sslstrip.log";
    if(!file->exists(filename))
	QMessageBox::information(NULL,"Error!","SSL-Stripped log file does not exist!");
    else
    {
	ui->packetInfo->setText("");
	file->setFileName(filename);
	file->open(QIODevice::ReadOnly);

	QTextStream read(file);
	while(!read.atEnd())
	    ui->packetInfo->append(read.readLine());
	//ui->packetInfo->setCursor(ui->packetInfo->textCursor().atStart());

	file->close();
	ui->tabWidget->setCurrentIndex(1);
    }
}

void MainWindow::closeEvent(QCloseEvent *e){
	QProcess *deleteDB = new QProcess();
        QProcess *killAirbase = new QProcess();
        QString airbase_addr0 = APP_CURRENT_PATH.append("/airbaseKill.sh").append(" ").append(ui->essidBox->text());
	QString currentPath = QCoreApplication::applicationDirPath();
	QString scriptPath = currentPath.append("/deletedb.sh");
	deleteDB->start(scriptPath);
        killAirbase->start(airbase_addr0);
        //QMessageBox::warning(NULL,"FFA","terminated");
}
void MainWindow::changeEvent(QEvent *e)
{
	QMainWindow::changeEvent(e);
	switch (e->type()) {
	case QEvent::LanguageChange:
		ui->retranslateUi(this);
		break;
	default:
		break;
	}
}
