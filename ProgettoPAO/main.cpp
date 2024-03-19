#include "frontend/mainwindow.h"
#include <QRadioButton>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(99, 1080);
    w.show();
    return a.exec();
}
