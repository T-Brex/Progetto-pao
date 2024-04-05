#include "mainwindow.h"
#include "frontend/sensorPanel.h"
#include <QApplication>
#include <QRadioButton>
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),window(new QWidget(this)), mainLayout(new QHBoxLayout(window))
{

    setCentralWidget(window);
}

MainWindow::~MainWindow() {}

MainWindow::MainWindow(QVector<Sensor*> s, QWidget *parent): QMainWindow(parent),window(new QWidget(this)), mainLayout(new QGridLayout(window))
{
    //trasformazione da Sensor a SensorPanel
    for(auto i=0;i<s.size();i++){

        mainLayout->addWidget(new SensorPanel(*s[i]));
    }
    setCentralWidget(window);

}
MainWindow::MainWindow(QVector<SensorPanel*> sp, QWidget *parent): QMainWindow(parent),window(new QWidget(this)), mainLayout(new QGridLayout(window))
{
    mainLayout->addWidget(SensorPanel::getSensorsWidget(sp));
    setCentralWidget(window);
}



MainWindow::MainWindow(QVector<QWidget*> frame, QWidget *parent):
    QMainWindow(parent),window(new QWidget(this)),mainLayout(new QHBoxLayout(window)),layoutsWidget(new LayoutsWidget),
       menuBar(new MenuBar)
    {

    setMenuBar(menuBar);
    connect(menuBar, &MenuBar::changeLayoutTrigger, this, &MainWindow::changeLayout);


    /*costruzione layout sensori
    for(auto i=0;i<frame.size();i++){
        sensLayout->addWidget(frame[i]);
    }
    layoutsWidget->addWidget(sensWidget);

*/

    //costruzione layout simulazione
    QWidget* simuWidget =new QWidget;
    QHBoxLayout* simuLayout=new QHBoxLayout(simuWidget);
    simuLayout->addWidget(new QPushButton("SUCA"));
    LayoutsWidget* lw=new LayoutsWidget;
    lw->addWidget(simuWidget);



    mainLayout->addWidget(layoutsWidget);
    setCentralWidget(window);
}

void MainWindow::changeLayout(){

    if(layoutsWidget->currentIndex()==0){
        layoutsWidget->setCurrentIndex(1);
        menuBar->changeLayoutAct->setText(tr("Sensori"));
    }else{
        layoutsWidget->setCurrentIndex(0);
        menuBar->changeLayoutAct->setText(tr("Simulazione"));

    }

};

