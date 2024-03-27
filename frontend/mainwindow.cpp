#include "mainwindow.h"
#include "frontend/sensorPanel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{   }

MainWindow::~MainWindow() {}

MainWindow::MainWindow(Sensor* s,QWidget *parent): QMainWindow(parent)
{
    SensorPanel *sp = new SensorPanel(*s);
    setCentralWidget(sp);
}
