#include "mainwindow.h"
#include "FunctionList.h"

void MainWindow::deauthAllFunc()
{
	int ap = ui->tableAP->selectionModel()->currentIndex().row();
	QMessageBox::information(NULL, "Deauth All","Selected AP is: #"+QString::number(ap));
}
