#include "mainwindow.h"
#include "FunctionList.h"

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
