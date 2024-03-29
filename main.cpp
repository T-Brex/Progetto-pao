#include <QApplication>
#include <QRadioButton>
#include <iostream>
#include "frontend/mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AirQuality ss ("nome");

    std::cout<<ss.getType();
    MainWindow w(&ss);

    w.resize(960, 480);
    w.show();
    return a.exec();
}
//
