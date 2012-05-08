#include "mainwindow.h"
#include "FunctionList.h"
#include <QString>

void MainWindow::selectAP()
{
	struct FFA_AP_info selected_ap;
	struct FFA_client_info *client_tuples;
	int row_num;
	int i;	
	int currentRow = ui->tableAP->selectionModel()->currentIndex().row();
	int currentColumn = ui->tableAP->selectionModel()->currentIndex().column();
	QString g_essid = ui->tableAP->item(currentRow, 0)->text();
	QString g_bssid = ui->tableAP->item(currentRow, 1)->text();
	QString g_c = ui->tableAP->item(currentRow, 2)->text();

	sprintf(selected_ap.ap_essid,"%s", g_essid.toStdString().c_str());
	sprintf(selected_ap.ap_bssid,"%s", g_bssid.toStdString().c_str());
	selected_ap.ap_channel = g_c.toInt();

	for (int i = ui->tableClient->rowCount()-1 ; i>=0 ; i--)
		ui->tableClient->removeRow(i);

	row_num = get_select_client_count(selected_ap);
	client_tuples = (struct FFA_client_info*)malloc(sizeof(struct FFA_client_info)*row_num);
	select_client(client_tuples, selected_ap);
	
	for(i = 0 ; i < row_num ; i++){
		ui->tableClient->insertRow(i);
		ui->tableClient->setItem(i, 0, new QTableWidgetItem(client_tuples[i].conn_ap_bssid));
		ui->tableClient->setItem(i, 1, new QTableWidgetItem(client_tuples[i].client_bssid));
	}
/*
	switch(currentRow)
	{
	case 0:
		for (i=0 ; i<3 ; i++)
		{
			ui->tableClient->insertRow(i);
			ui->tableClient->setItem(i, 0, new QTableWidgetItem("1st Elem"));
			ui->tableClient->setItem(i, 1, new QTableWidgetItem("("+QString::number(i)+", "+QString::number(1)+")"));
		}
		break;
	case 1:
		for (i=0 ; i<2 ; i++)
		{
			ui->tableClient->insertRow(i);
			ui->tableClient->setItem(i, 0, new QTableWidgetItem("2nd Elem"));
			ui->tableClient->setItem(i, 1, new QTableWidgetItem("("+QString::number(i)+", "+QString::number(1)+")"));
		}
		break;
	default:
		ui->tableClient->insertRow(0);
		ui->tableClient->setItem(0, 0, new QTableWidgetItem("Others =.="));
		ui->tableClient->setItem(0, 1, new QTableWidgetItem("AP Num: "+QString::number(currentRow)));
		break;
	}
*/
	ui->deauthClnt->setDisabled(true);
	ui->deauthAll->setEnabled(true);
	ui->tableClient->setEnabled(true);
	memset(client_tuples,'\0',sizeof(client_tuples));
	free(client_tuples);
}
