#include <QtGui/QApplication>
#include <QtGui/QMdiArea>
#include <QtGui/QMdiSubWindow>
#include "mainwindow.h"

char **argv_main;

int main(int argc, char *argv[])
{	
	argv_main = argv;
	QApplication a(argc, argv);
	MainWindow w;
	//sslwindow w2;
	w.show();
	//w2.show();
	return a.exec();
}
