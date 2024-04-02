#include "mainwindow.h"
#include "frontend/sensorPanel.h"
#include <QApplication>
#include <QRadioButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),window(new QWidget(this)), layout(new QHBoxLayout(window))
{
    setCentralWidget(window);
}

MainWindow::~MainWindow() {}

MainWindow::MainWindow(QVector<Sensor*> s, QWidget *parent): QMainWindow(parent),window(new QWidget(this)), layout(new QHBoxLayout(window))
{
    //trasformazione da Sensor a SensorPanel
    QVector<SensorPanel*> sp;
    for(auto i=0;i<s.size();i++){
        sp.push_front(new SensorPanel(*s[i]));
    }

    layout->addWidget(SensorPanel::getSensorsWidget(sp));
    setCentralWidget(window);

}
MainWindow::MainWindow(QVector<SensorPanel*> sp, QWidget *parent): QMainWindow(parent),window(new QWidget(this)), layout(new QHBoxLayout(window))
{
    layout->addWidget(SensorPanel::getSensorsWidget(sp));
    setCentralWidget(window);
}

MainWindow::MainWindow(QVector<QWidget*> frame, QWidget *parent): QMainWindow(parent),window(new QWidget(this)), layout(new QHBoxLayout(window))
/*frame è un n vettore di widget collegato ad un layout, such that:     QWidget *sensorsPanel = new QWidget;
                                                                        QHBoxLayout* panelsLayout = new QHBoxLayout(sensorsPanel);
                                                                        for(auto i=0;i<sp.size();i++){
                                                                            panelsLayout->addWidget(sp[i]);
                                                                        }
*/
{

    for(auto i=0;i<frame.size();i++){
        layout->addWidget(frame[i]);
    }

    setCentralWidget(window);
}




