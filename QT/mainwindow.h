#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QItemSelection>
#include <QSortFilterProxyModel>
#include <QTableView>
#include <QTabWidget>
#include <QComboBox>
#include "ui_mainwindow.h"

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow {
	Q_OBJECT
public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
public slots:
	void showBitchbox();
	void TotheBox();
	void initTable();
	void airmonFunc();
	void airbaseFunc();
	void refreshFunc();
	void selectAP();
	void selectClnt();
	void deauthAllFunc();
	void deauthClntFunc();
protected:
	void changeEvent(QEvent *e);
private:
	Ui::MainWindow *ui;
	QSortFilterProxyModel *proxyModel;
};

#endif // MAINWINDOW_H
