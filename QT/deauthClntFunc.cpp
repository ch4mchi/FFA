#include "mainwindow.h"
#include "FunctionList.h"

void MainWindow::deauthClntFunc()
{
	int ap = ui->tableAP->selectionModel()->currentIndex().row();
	int clnt = ui->tableClient->selectionModel()->currentIndex().row();
	QMessageBox::information(NULL, "Deauth Client","Selected Client Information\n\nAP Name: "+ui->tableAP->item(ap,0)->text()+"\nClient Name: "+ui->tableClient->item(clnt,0)->text());
}
