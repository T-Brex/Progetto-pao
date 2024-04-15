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
    QMainWindow(parent),layoutsWidget(new LayoutsWidget(s)),menuBar(new MenuBar),addDialog(new AddDialog(this)),deleteDialog(new DeleteDialog(this))
{

    QMessageBox emptyName;
    emptyName.setDefaultButton(new QPushButton);
    emptyName.setText("Inserire un nome");
    emptyName.open();


    setMenuBar(menuBar);

    connect(menuBar, &MenuBar::changeLayoutTrigger, this, &MainWindow::changeLayout);


    connect(menuBar, &MenuBar::showAddDialog, addDialog, &AddDialog::open);
    connect(addDialog, &AddDialog::newTrigger, this, [&]()
        {
            //addDialog->lineEdit->setFocus();
            Json::nuovoSensore(addDialog->lineEdit->text(), addDialog->sceltaTipo->currentText());
            this->updateSensors();

            deleteDialog->sceltaNome->addItem(addDialog->lineEdit->text());
            addDialog->lineEdit->clear();
            addDialog->close();
        });


    /*connect(layoutsWidget->searchMenu,&SearchMenu::showAddDialog, this, [&]()
                {
        addDialog->show();
        connect(addDialog, &Dialog::newTrigger, this, [&]()
                {
                    nuovoSensore(addDialog->lineEdit->text(), addDialog->sceltaTipo->currentText());

                    addDialog->hide();
                });


    connect(menuBar, &MenuBar::saveTrigger, this,  [&]()
            {
                salvaSensori(s);
            });
   });*/

    connect(menuBar, &MenuBar::showDeleteDialog, deleteDialog, &AddDialog::open);
    connect(deleteDialog->deleteButton,&QPushButton::clicked,this,[&](){

        Json::eliminaSensore(deleteDialog->sceltaNome->currentText());
        this->updateSensors();
        deleteDialog->close();
        deleteDialog->sceltaNome->removeItem(deleteDialog->sceltaNome->currentIndex());
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







