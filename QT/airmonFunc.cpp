#include "mainwindow.h"
#include "FunctionList.h"
#include <QProcess>
#include <QString>

extern char **argv_main;

void MainWindow::airmonFunc()
{
	static bool st = false;
	QProcess *airmon = new QProcess();
	QString airmon_start = "/home/letorika/Dev/FFA/QT/airmon-sh.sh";
	QString airmon_stop = "/home/letorika/Dev/FFA/QT/airmon-ksh.sh";
	QString path = argv_main[0];	

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

		QMessageBox::warning(NULL,"adsf",airmon_stop);
		airmon->start(airmon_stop);
	}
	else
	{
		ui->refreshBtn->setEnabled(true);
		ui->airmonBtn->setText("Turn Off");
		ui->airmonStatus->setText("<font size=5 color=green>On</font>");

		QMessageBox::warning(NULL,"adsf",airmon_start);
		airmon->start(airmon_start);
		initTable();

		st = true;
	}
}
