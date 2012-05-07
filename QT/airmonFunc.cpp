#include "mainwindow.h"
#include "FunctionList.h"

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
