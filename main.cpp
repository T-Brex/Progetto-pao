#include <QApplication>
#include <QRadioButton>
#include "frontend/mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dust ss ("nome");




    MainWindow w(&ss);

    w.resize(960, 480);
    w.show();
    return a.exec();
}
