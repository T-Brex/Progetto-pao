#include "mainwindow.h"
#include "frontend/sensorPanel.h"
#include <QApplication>
#include <QRadioButton>
#include <QMenuBar>


//forse meglio togliere la staticità e creare l'amicizia tra menu e window!
//QStackedWidget* MainWindow::layoutsWidget= new QStackedWidget();




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),window(new QWidget(this)), sensLayout(new QGridLayout(window))
{

    setCentralWidget(window);
}

MainWindow::~MainWindow() {}

MainWindow::MainWindow(QVector<Sensor*> s, QWidget *parent): QMainWindow(parent),window(new QWidget(this)), sensLayout(new QGridLayout(window))
{
    //trasformazione da Sensor a SensorPanel
    for(auto i=0;i<s.size();i++){

        sensLayout->addWidget(new SensorPanel(*s[i]));
    }
    setCentralWidget(window);

}
MainWindow::MainWindow(QVector<SensorPanel*> sp, QWidget *parent): QMainWindow(parent),window(new QWidget(this)), sensLayout(new QGridLayout(window))
{
    sensLayout->addWidget(SensorPanel::getSensorsWidget(sp));
    setCentralWidget(window);
}



MainWindow::MainWindow(QVector<QWidget*> frame, QWidget *parent):
    QMainWindow(parent),window(new QWidget(this)),mainLayout(new QHBoxLayout(window)),

    sensWidget(new QWidget),sensLayout(new QGridLayout(sensWidget)),simuWidget(new QWidget),simuLayout(new QHBoxLayout(simuWidget)),layoutsWidget(new QStackedWidget),
    menuBar(new MenuBar)
    {

    setMenuBar(menuBar);
    connect(menuBar, &MenuBar::changeLayoutTrigger, this, &MainWindow::changeLayout);

    //costruzione layout sensori
    for(auto i=0;i<frame.size();i++){
        sensLayout->addWidget(frame[i]);
    }
    layoutsWidget->addWidget(sensWidget);

    //costruzione layout simulazione
    simuLayout->addWidget(new QPushButton("SUCA"));
    layoutsWidget->addWidget(simuWidget);

    mainLayout->addWidget(layoutsWidget);
    setCentralWidget(window);
}

void MainWindow::changeLayout(){
    if(layoutsWidget->currentIndex()==0){
        layoutsWidget->setCurrentIndex(1);
        //menuBar->insertAction(menuBar->simulazioneAct,menuBar->sensoriAct);
        //menuBar->removeAction(menuBar->simulazioneAct);
        menuBar->changeLayoutAct->setText(tr("sensori"));



    }else{
        layoutsWidget->setCurrentIndex(0);
        //menuBar->insertAction(menuBar->sensoriAct,menuBar->simulazioneAct);
        //menuBar->removeAction(menuBar->sensoriAct);
        menuBar->changeLayoutAct->setText(tr("simulazione"));

    }
};

