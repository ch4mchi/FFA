#include "mainwindow.h"
#include "FunctionList.h"
#include <QProcess>
#include <QString>
#include <QCoreApplication>
#define APP_CURRENT_PATH QCoreApplication::applicationDirPath()
extern char **argv_main;

void MainWindow::airmonFunc()
{
	static bool st = false;
	QProcess *airmon = new QProcess();
	QProcess *airodump = new QProcess();
	QString currentPath = QCoreApplication::applicationDirPath();
	QString airmon_start = APP_CURRENT_PATH
				.append("/airmon-sh.sh");
	QString airmon_stop = APP_CURRENT_PATH
				.append("/airmon-ksh.sh");
	QString airodump_start = APP_CURRENT_PATH
				.append("/airodump-sh.sh");
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
		QMessageBox::warning(NULL,"asdf",airmon_stop);
		airodump->close();
		airmon->start(airmon_stop);
	}
	else
	{
		ui->refreshBtn->setEnabled(true);
		ui->airmonBtn->setText("Turn Off");
		ui->airmonStatus->setText("<font size=5 color=green>On</font>");

		QMessageBox::warning(NULL,"adsf",airmon_start);
		airmon->start(airmon_start);
		sleep(3);
		airodump->start(airodump_start);
		connect_db("FFA_.db");
		initTable();
		st = true;
	}
}
