#include <QApplication>
#include "frontend/mainwindow.h"
#include "frontend/simulation.h"
#include <QDebug>






//////// C:/Users/bress/Desktop/progetti/File C/Progetto-pao/resources/dati.json

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setWindowTitle("Sensori");
    return a.exec();


}

