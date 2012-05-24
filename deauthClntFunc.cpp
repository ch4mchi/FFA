#include "mainwindow.h"
#include "FunctionList.h"
#define APP_CURRENT_PATH QCoreApplication::applicationDirPath()

void MainWindow::deauthClntFunc()
{
	int ap = ui->tableAP->selectionModel()->currentIndex().row();
	int clnt = ui->tableClient->selectionModel()->currentIndex().row();
	QProcess *aireplay = new QProcess();
	QString aireplay_addr = APP_CURRENT_PATH
				.append("/aireplay-sh.sh").append(" ")
				.append(ui->tableAP->item(ap, 1)->text()).append(" ")
				.append(ui->tableClient->item(clnt, 1)->text());
        //QMessageBox::information(NULL, "Command is: ", aireplay_addr);
	aireplay->start(aireplay_addr);
}
