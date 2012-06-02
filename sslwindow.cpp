#include "mainwindow.h"
#include "sslwindow.h"

sslwindow::sslwindow(QWidget *parent) :
	QWidget(parent),
	ssl(new Ui::sslwindow)
{
    ssl->setupUi(this);
    this->setWindowFlags(Qt::Window);
}
