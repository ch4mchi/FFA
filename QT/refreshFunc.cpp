#include "mainwindow.h"
#include "FunctionList.h"

void MainWindow::refreshFunc()
{
	ui->tableClient->setDisabled(true);
	ui->deauthAll->setDisabled(true);
	ui->deauthClnt->setDisabled(true);

	initTable();
}
