#include "mainwindow.h"
#include "FunctionList.h"
#define APP_CURRENT_PATH QCoreApplication::applicationDirPath()

void MainWindow::deauthAllFunc()
{
	int i, numClnt = ui->tableClient->rowCount();
	int ap = ui->tableAP->selectionModel()->currentIndex().row();
	QProcess *aireplay[numClnt];
	for (i=0 ; i<numClnt ; i++)
	{
		aireplay[i] = new QProcess();
		QString aireplay_addr = APP_CURRENT_PATH
					.append("/aireplay-sh.sh").append(" ")
					.append(ui->tableAP->item(ap, 1)->text()).append(" ")
					.append(ui->tableClient->item(i, 1)->text());
                //QMessageBox::information(NULL, "Command is: ", aireplay_addr);
		aireplay[i]->start(aireplay_addr);
	}
}
