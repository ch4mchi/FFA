#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <unistd.h>

#include <QMainWindow>
#include <QMessageBox>
#include <QItemSelection>
#include <QSortFilterProxyModel>
#include <QTableView>
#include <QTabWidget>
#include <QComboBox>
#include <QTimer>
#include "ui_mainwindow.h"
//#include "sslwindow.h"

namespace Ui {
	class MainWindow;
	//class sslwindow;
}

class MainWindow : public QMainWindow {
	Q_OBJECT
public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
public slots:
	void showBitchbox();
	void openSSLWindow();
	void onTimer();
	void initTable();
	void airmonFunc();
	void airbaseFunc();
        void captureFunc();
	void refreshFunc();
	void selectAP();
	void selectClnt();
	void deauthAllFunc();
	void deauthClntFunc();
protected:
	void changeEvent(QEvent *e);
	void closeEvent(QCloseEvent *e);
private:
	Ui::MainWindow *ui;
	//sslwindow *sub_w;
	QSortFilterProxyModel *proxyModel;
};

#endif // MAINWINDOW_H
