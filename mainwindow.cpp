#include "mainwindow.h"
#include "FunctionList.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	//UI connection
	QObject::connect(ui->btn1, SIGNAL(clicked()), this, SLOT(TotheBox()));
	QObject::connect(ui->btn2, SIGNAL(clicked()), this, SLOT(showBitchbox()));
	QObject::connect(ui->airmonBtn, SIGNAL(clicked()), this, SLOT(airmonFunc()));
	QObject::connect(ui->airbaseBtn, SIGNAL(clicked()), this, SLOT(airbaseFunc()));
	QObject::connect(ui->refreshBtn, SIGNAL(clicked()), this, SLOT(refreshFunc()));
	QObject::connect(ui->tableAP, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(selectAP()));
	QObject::connect(ui->tableClient, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(selectClnt()));
	QObject::connect(ui->deauthAll, SIGNAL(clicked()), this, SLOT(deauthAllFunc()));
	QObject::connect(ui->deauthClnt, SIGNAL(clicked()), this, SLOT(deauthClntFunc()));
	QObject::connect(ui->closeBtn, SIGNAL(clicked()), this, SLOT(close()));

	ui->comboBox->addItem(tr("asdf"));
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

void MainWindow::TotheBox()
{
	QMessageBox::information(NULL, "Text is: ", ui->comboBox->currentText());
}

void MainWindow::selectClnt()
{
	ui->deauthClnt->setEnabled(true);
}

void MainWindow::showBitchbox(){
	int ret;
	QMessageBox::warning(NULL,"WTF!!","Oh My F**king God...\nThis Term Project is Terrible!\n\nPlease help me T^T");
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
