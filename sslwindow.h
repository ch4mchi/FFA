#ifndef SSLWINDOW_H
#define SSLWINDOW_H
#include <QTabWidget>
#include "ui_sslwindow.h"
//#include "sslwindow.cpp"
namespace Ui {
	class sslwindow;
}

class sslwindow : public QWidget {
	Q_OBJECT
public:
	sslwindow(QWidget *parent = 0);
//public slots:

//protected:

private:
	Ui::sslwindow *ssl;
};

#endif // SSLWINDOW_H
