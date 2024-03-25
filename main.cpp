#include "frontend/mainwindow.h"
#include <QRadioButton>
#include <QApplication>
#include <QMenuBar>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w;
    SensorPanel s(&w);
    w.setWindowTitle("Sensoooooori");
   // QMenuBar menuBar(&w);
    w.addToolBar("Titolo Tool Barr");



    w.resize(960, 480);
    w.show();
    return a.exec();
}
