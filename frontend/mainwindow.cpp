#include "mainwindow.h"
#include "frontend/adddialog.h"
#include "frontend/sensorPanel.h"
#include "frontend/addDialog.h"
#include "qmessagebox.h"
#include <QApplication>
#include <QRadioButton>
#include <QMenuBar>
#include <QMenuBar>



MainWindow::MainWindow(SearchMenu *menu, QWidget *parent)
    : QMainWindow(parent)
{

    setCentralWidget(menu);
}




MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent),layoutsWidget(new LayoutsWidget()),menuBar(new MenuBar)
{
    setMenuBar(menuBar);
    connect(menuBar, &MenuBar::changeLayoutTrigger, this, &MainWindow::changeLayout);
    setCentralWidget(layoutsWidget);
}

MainWindow::~MainWindow() {}

MainWindow::MainWindow(const QVector<Sensor*>& s, QWidget *parent):
    QMainWindow(parent),layoutsWidget(new LayoutsWidget(s)),menuBar(new MenuBar)//,addDialog(new AddDialog(this)),deleteDialog(new DeleteDialog(this))
{

    QMessageBox emptyName;
    emptyName.setDefaultButton(new QPushButton);
    emptyName.setText("Inserire un nome");
    emptyName.open();


    setMenuBar(menuBar);
    connect(menuBar, &MenuBar::changeLayoutTrigger, this, &MainWindow::changeLayout);
    connect(menuBar, &MenuBar::showAddDialog, layoutsWidget->addDialog, [&](){
        layoutsWidget->addDialog->open();
        layoutsWidget->addDialog->lineEdit->setFocus();
    });
    connect(layoutsWidget->searchMenu,&SearchMenu::showAddDialog, layoutsWidget->addDialog, [&](){
        layoutsWidget->addDialog->open();
        layoutsWidget->addDialog->lineEdit->setFocus();
    });

    /*connect(layoutsWidget->addDialog, &AddDialog::newTrigger, this, [&]()
        {
            QString result=Json::nuovoSensore(layoutsWidget->addDialog->lineEdit->text(), layoutsWidget->addDialog->sceltaTipo->currentText());

            if(result=="ok"){
                layoutsWidget->addSensor(Json::costruttore(layoutsWidget->addDialog->lineEdit->text(), layoutsWidget->addDialog->sceltaTipo->currentText()));
                layoutsWidget->deleteDialog->sceltaNome->addItem(layoutsWidget->addDialog->lineEdit->text());
                layoutsWidget->addDialog->lineEdit->clear();
                layoutsWidget->addDialog->close();
            }
        });*/

    connect(menuBar, &MenuBar::showDeleteDialog, layoutsWidget->deleteDialog, &DeleteDialog::open);
    /*connect(layoutsWidget->deleteDialog->deleteButton,&QPushButton::clicked,this,[&](){
        Json::eliminaSensore(layoutsWidget->deleteDialog->sceltaNome->currentText());
        layoutsWidget->deleteSensor(layoutsWidget->deleteDialog->sceltaNome->currentText());
        layoutsWidget->deleteDialog->close();
        layoutsWidget->deleteDialog->sceltaNome->removeItem(layoutsWidget->deleteDialog->sceltaNome->currentIndex());
    });


    connect(layoutsWidget->searchMenu,&SearchMenu::showDeleteDialog, layoutsWidget->deleteDialog, &DeleteDialog::open);
*/


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


void MainWindow::updateSensors() {

    layoutsWidget = new LayoutsWidget(Json::caricaSensori());
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







