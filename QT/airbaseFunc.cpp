#include "mainwindow.h"
#include "FunctionList.h"

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
