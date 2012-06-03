#include "mainwindow.h"
#include "FunctionList.h"

void MainWindow::airbaseFunc()
{
	static bool st = false;
	QProcess *airbase0 = new QProcess();
        QProcess *killAirbase = new QProcess();
        QProcess *airodump = new QProcess();
        QProcess *airmon = new QProcess();
        QProcess *killairodump = new QProcess();
        QProcess *killaireplay = new QProcess();
        QString aireplay_stop = APP_CURRENT_PATH.append("/aireplayKill.sh");
        QString airmon_start = APP_CURRENT_PATH.append("/airmon-sh.sh");
        QString airbase_Kill = APP_CURRENT_PATH.append("/airbaseKill.sh").append(" ").append(ui->essidBox->text());
        QString airbase_addr = APP_CURRENT_PATH.append("/airbase.sh").append(" ").append(ui->essidBox->text());
        QString airodump_start = APP_CURRENT_PATH.append("/airodump-sh.sh");
        QString airodump_stop = APP_CURRENT_PATH.append("/airodumpKill.sh");
	if(st)
	{
		ui->airbaseBtn->setText("Turn On");
                ui->btn1->setDisabled(true);
		ui->essidBox->setEnabled(true);
                ui->airmonBtn->setEnabled(true);
		st = false;
                killAirbase->start(airbase_Kill);
                sleep(5);
                airmon->start(airmon_start);
                sleep(5);
                airodump->start(airodump_start);
	}
	else
	{
		ui->airbaseBtn->setText("Turn Off");
                ui->btn1->setEnabled(true);
		ui->essidBox->setDisabled(true);
                ui->airmonBtn->setDisabled(true);
                st = true;
                airbase0->start(airbase_addr);
                killairodump->start(airodump_stop);
                killaireplay->start(aireplay_stop);
	}
}
