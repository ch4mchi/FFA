#include "mainwindow.h"
#include "FunctionList.h"
#define APP_CURRENT_PATH QCoreApplication::applicationDirPath()

void MainWindow::captureFunc()
{
        QProcess *captureOn = new QProcess();
        QString capture = APP_CURRENT_PATH
                                .append("/capture-sh.sh");
        captureOn->start(capture);
}
