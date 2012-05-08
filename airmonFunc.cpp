#include "mainwindow.h"
#include "FunctionList.h"
#include <QProcess>
#include <QString>

extern char **argv_main;

void MainWindow::airmonFunc()
{
	static bool st = false;
	QProcess *airmon = new QProcess();
	QProcess *airodump = new QProcess();
	QString airmon_start = "/home/letorika/Dev/FFA/QT/airmon-sh.sh";
	QString airmon_stop = "/home/letorika/Dev/FFA/QT/airmon-ksh.sh";
	QString airodump_start = "/home/letorika/Dev/FFA/QT/airodump-sh.sh";
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
		close_db();
		QMessageBox::warning(NULL,"adsf",airmon_stop);
		airodump->close();
		airmon->start("airmon stop mon0");
	}
	else
	{
		ui->refreshBtn->setEnabled(true);
		ui->airmonBtn->setText("Turn Off");
		ui->airmonStatus->setText("<font size=5 color=green>On</font>");

		QMessageBox::warning(NULL,"adsf",airmon_start);
		airmon->start("airmon start wlan0");
		sleep(3);
		airodump->start(airodump_start);
		connect_db("FFA_.db");
		initTable();
		st = true;
	}
}
