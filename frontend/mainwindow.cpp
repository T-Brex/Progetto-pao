#include "mainwindow.h"
#include "frontend/sensorPanel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

}

MainWindow::~MainWindow() {}

MainWindow::MainWindow(SensorPanel* s,QWidget *parent): QMainWindow(parent)
{
    setCentralWidget(s);
}

