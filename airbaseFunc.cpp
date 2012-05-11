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

		QProcess *airbase = new QProcess();
		QString airbase_addr = APP_CURRENT_PATH
					.append("/airbase-sh.sh").append(" ")
					.append(ui->essidBox->text());
		QMessageBox::information(NULL, "Command is: ", airbase_addr);
		airbase->start(airbase_addr);
	}
}
