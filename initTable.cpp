#include "mainwindow.h"
#include "FunctionList.h"

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
