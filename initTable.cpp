#include "mainwindow.h"
#include "FunctionList.h"

void MainWindow::initTable()
{
	static int numRef = 0;
	struct FFA_AP_info *ap_tuples;
	int chksum;
	int low_num;

	numRef ++;
	ui->tableAP->setEnabled(true);

	chksum = connect_db("FFA_.db");
	if(chksum)
		QMessageBox::warning(NULL,"DB error","DB connection fail");

	for (int i = ui->tableAP->rowCount()-1 ; i>=0 ; i--)
		ui->tableAP->removeRow(i);
	for (int i = ui->tableClient->rowCount()-1 ; i>=0 ; i--)
		ui->tableClient->removeRow(i);

	low_num = get_select_ap_count();
	ap_tuples = (struct FFA_AP_info*)malloc(sizeof(struct FFA_AP_info)*low_num);
	select_ap(ap_tuples);
	for (int i = 0 ; i < low_num ; i++)
	{
		ui->tableAP->insertRow(i);
		ui->tableAP->setItem(i, 0, new QTableWidgetItem(ap_tuples[i].ap_essid));
		ui->tableAP->setItem(i, 1, new QTableWidgetItem(ap_tuples[i].ap_bssid));
		ui->tableAP->setItem(i, 2, new QTableWidgetItem(QString::number(ap_tuples[i].ap_channel)));
	}
	ui->tableClient->insertRow(0);
	ui->tableClient->setItem(0, 0, new QTableWidgetItem("(None)"));
	ui->tableClient->setItem(0, 1, new QTableWidgetItem("Select AP First!"));
	
	close_db();
}
