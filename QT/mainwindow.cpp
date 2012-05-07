#include "mainwindow.h"

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

	ui->tableAP->setSortingEnabled(true);
	ui->tableAP->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableAP->horizontalHeader()->setStretchLastSection(true);
	ui->tableAP->verticalHeader()->hide();
	ui->tableAP->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableAP->setSelectionMode(QAbstractItemView::SingleSelection);
	ui->tableAP->horizontalHeader()->resizeSection(0, 120);
	ui->tableAP->horizontalHeader()->resizeSection(1, 160);
	ui->tableAP->horizontalHeader()->resizeSection(2, 40);

	ui->tableClient->setSortingEnabled(true);
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

void MainWindow::airmonFunc()
{
	static bool st = false;
	if(st)
	{
		ui->tableAP->setDisabled(true);
		ui->tableClient->setDisabled(true);
		ui->deauthAll->setDisabled(true);
		ui->deauthClnt->setDisabled(true);
		ui->refreshBtn->setDisabled(true);
		ui->airmonBtn->setText("Turn On");
		ui->airmonStatus->setText("<font size=5 color=red>Off</font>");
		st = false;
	}
	else
	{
		ui->refreshBtn->setEnabled(true);
		ui->airmonBtn->setText("Turn Off");
		ui->airmonStatus->setText("<font size=5 color=green>On</font>");

		initTable();

		st = true;
	}
}

void MainWindow::airbaseFunc()
{
	static bool st = false;
	if(st)
	{
		ui->airbaseBtn->setText("Turn On");
		ui->essidBox->setEnabled(true);
		st = false;
	}
	else
	{
		ui->airbaseBtn->setText("Turn Off");
		ui->essidBox->setDisabled(true);
		st = true;
		QMessageBox::information(NULL, "Airbase","Airbase Activated.\n\nESSID is: "+ui->essidBox->text());
	}
}

void MainWindow::refreshFunc()
{
	ui->tableClient->setDisabled(true);
	ui->deauthAll->setDisabled(true);
	ui->deauthClnt->setDisabled(true);

	initTable();
}

void MainWindow::selectAP()
{
	int i;
	int currentRow = ui->tableAP->selectionModel()->currentIndex().row();
	int currentColumn = ui->tableAP->selectionModel()->currentIndex().column();
	for (int i = ui->tableClient->rowCount()-1 ; i>=0 ; i--)
		ui->tableClient->removeRow(i);
	switch(currentRow)
	{
	case 0:
		for (i=0 ; i<3 ; i++)
		{
			ui->tableClient->insertRow(i);
			ui->tableClient->setItem(i, 0, new QTableWidgetItem("1st Elem"));
			ui->tableClient->setItem(i, 1, new QTableWidgetItem("("+QString::number(i)+", "+QString::number(1)+")"));
		}
		break;
	case 1:
		for (i=0 ; i<2 ; i++)
		{
			ui->tableClient->insertRow(i);
			ui->tableClient->setItem(i, 0, new QTableWidgetItem("2nd Elem"));
			ui->tableClient->setItem(i, 1, new QTableWidgetItem("("+QString::number(i)+", "+QString::number(1)+")"));
		}
		break;
	default:
		ui->tableClient->insertRow(0);
		ui->tableClient->setItem(0, 0, new QTableWidgetItem("Others =.="));
		ui->tableClient->setItem(0, 1, new QTableWidgetItem("AP Num: "+QString::number(currentRow)));
		break;
	}
	ui->deauthClnt->setDisabled(true);
	ui->deauthAll->setEnabled(true);
	ui->tableClient->setEnabled(true);
}

void MainWindow::initTable()
{
	static int numRef = 0;
	numRef ++;
	ui->tableAP->setEnabled(true);

	for (int i = ui->tableAP->rowCount()-1 ; i>=0 ; i--)
		ui->tableAP->removeRow(i);
	for (int i = ui->tableClient->rowCount()-1 ; i>=0 ; i--)
		ui->tableClient->removeRow(i);
	for (int i=0;i<5;i++)
	{
		ui->tableAP->insertRow(i);
		for (int j=0;j<3;j++)
		{
			ui->tableAP->setItem(i, j, new QTableWidgetItem("("+QString::number(i*numRef)+", "+QString::number(j*numRef)+")"));
		}
	}
	ui->tableClient->insertRow(0);
	ui->tableClient->setItem(0, 0, new QTableWidgetItem("(None)"));
	ui->tableClient->setItem(0, 1, new QTableWidgetItem("Select AP First!"));
}

void MainWindow::selectClnt()
{
	ui->deauthClnt->setEnabled(true);
}

void MainWindow::deauthAllFunc()
{
	int ap = ui->tableAP->selectionModel()->currentIndex().row();
	QMessageBox::information(NULL, "Deauth All","Selected AP is: #"+QString::number(ap));
}

void MainWindow::deauthClntFunc()
{
	int ap = ui->tableAP->selectionModel()->currentIndex().row();
	int clnt = ui->tableClient->selectionModel()->currentIndex().row();
	QMessageBox::information(NULL, "Deauth Client","Selected Client Information\n\nAP Name: "+ui->tableAP->item(ap,0)->text()+"\nClient Name: "+ui->tableClient->item(clnt,0)->text());
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
