#include "mainwindow.h"
#include "backend/json.h"

MainWindow::MainWindow(SearchMenu *menu, QWidget *parent)
    : QMainWindow(parent)
{

    setCentralWidget(menu);
}




MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent),layoutsWidget(new LayoutsWidget())//,menuBar(new MenuBar)
{
    //setMenuBar(menuBar);
    //connect(menuBar, &MenuBar::changeLayoutTrigger, this, &MainWindow::changeLayout);
    setCentralWidget(layoutsWidget);
}

MainWindow::~MainWindow() {}

MainWindow::MainWindow(const QVector<Sensor*>& s, QWidget *parent):
    QMainWindow(parent),layoutsWidget(new LayoutsWidget(s)),menuBar(new MenuBar)
{




    setMenuBar(menuBar);
    connect(menuBar, &MenuBar::changeLayoutTrigger, this, &MainWindow::changeLayout);
    connect(menuBar, &MenuBar::showAddDialog, layoutsWidget->addDialog, [&](){
        layoutsWidget->addDialog->open();
        layoutsWidget->addDialog->lineEdit->setFocus();
    });
    connect(menuBar, &MenuBar::showDeleteDialog, layoutsWidget->deleteDialog, &DeleteDialog::open);

    connect(menuBar, &MenuBar::saveTrigger, this,  [&]()
            {
        Json::salvaSensori(s);
            });

    connect(menuBar, &MenuBar::loadTrigger, this, [&]()
            {
        Json::caricaSensori();
            });
    setCentralWidget(layoutsWidget);
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


//Eliminabile(?)
MainWindow::MainWindow(QVector<SensorPanel*> sp, QWidget *parent):
    QMainWindow(parent),layoutsWidget(new LayoutsWidget(sp)),menuBar(new MenuBar)
{
    setMenuBar(menuBar);
    connect(menuBar, &MenuBar::changeLayoutTrigger, this, &MainWindow::changeLayout);
    setCentralWidget(layoutsWidget);
}


//Eliminabile(?)
MainWindow::MainWindow(QVector<QWidget*> frame, QWidget *parent):
    QMainWindow(parent),layoutsWidget(new LayoutsWidget(frame)),menuBar(new MenuBar)
{
    setMenuBar(menuBar);
    connect(menuBar, &MenuBar::changeLayoutTrigger, this, &MainWindow::changeLayout);
    setCentralWidget(layoutsWidget);
}









