diocabe

#include "frontend/mainwindow.h"
#include <QRadioButton>
#include <QApplication>
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SensorPanel s;
    MainWindow w(&s);
    w.resize(960, 480);
    w.show();
    return a.exec();
}
