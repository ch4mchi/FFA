#include <QtGui/QApplication>
#include "mainwindow.h"
#include "FFA_sqlite3.h"

char **argv_main;

int main(int argc, char *argv[])
{	
	argv_main = argv;
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();
}
