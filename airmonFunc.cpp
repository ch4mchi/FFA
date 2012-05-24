#include "mainwindow.h"
#include "FunctionList.h"
#include <QProcess>
#include <QString>
#include <QCoreApplication>
#define APP_CURRENT_PATH QCoreApplication::applicationDirPath()
extern char **argv_main;
int cnt;
QTimer *timer;
void MainWindow::airmonFunc()
{
	static bool st = false;
	QProcess *airmon = new QProcess();
	QProcess *airodump = new QProcess();
        QProcess *killAirbase = new QProcess();
	QString currentPath = QCoreApplication::applicationDirPath();
	QString airmon_start = APP_CURRENT_PATH
				.append("/airmon-sh.sh");
	QString airmon_stop = APP_CURRENT_PATH
				.append("/airmon-ksh.sh");
	QString airodump_start = APP_CURRENT_PATH
				.append("/airodump-sh.sh");
        QString airbase_addr0 = APP_CURRENT_PATH
                                .append("/airbaseKill.sh").append(" ").append(ui->essidBox->text());
	QString path = argv_main[0];
	if(st)
	{
		ui->tableAP->setDisabled(true);
		ui->tableClient->setDisabled(true);
		ui->deauthAll->setDisabled(true);
		ui->deauthClnt->setDisabled(true);
		ui->refreshBtn->setDisabled(true);
                ui->essidBox->setDisabled(true);
                ui->airbaseBtn->setDisabled(true);
		ui->airmonBtn->setText("Turn On");
		ui->airmonStatus->setText("<font size=5 color=red>Off</font>");
		st = false;
		close_db();
		airodump->close();
		airmon->start(airmon_stop);
                killAirbase->start(airbase_addr0);
	}
	else
	{
		st = true;
		cnt = 0;
		timer = new QTimer();
		connect(timer, SIGNAL(timeout()),this, SLOT(onTimer()));
		ui->tableAP->setDisabled(true);
		ui->tableClient->setDisabled(true);
		ui->progressBar->setVisible(true);
		ui->airmonBtn->setText("Turn Off");
		ui->airmonBtn->setDisabled(true);
		ui->airmonStatus->setText("<font size=5 color=skyblue>Wait</font>");
		timer->start(0);
		//QMessageBox::warning(NULL,"adsf",airmon_start);
		airmon->start(airmon_start);
		sleep(3);
		airodump->start(airodump_start);
		connect_db("FFA_.db");
		initTable();
	}
}


void MainWindow::onTimer()
{
	cnt++;
	ui->progressBar->setValue(cnt/50);
	if(cnt==500000)
	{
		timer->stop();
		ui->progressBar->setVisible(false);
		ui->refreshBtn->setEnabled(true);
		ui->airmonBtn->setEnabled(true);
                ui->essidBox->setEnabled(true);
                ui->airbaseBtn->setEnabled(true);
		ui->airmonStatus->setText("<font size=5 color=green>On</font>");
	}
}
