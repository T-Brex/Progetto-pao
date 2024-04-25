#include "layoutswidget.h"

#include "frontend/sensorwindow.h"

#include "frontend/simulation.h"
#include "qdialog.h"
#include "qmessagebox.h"
#include "qpushbutton.h"


#include "backend/json.h"
#include <QScrollArea>


LayoutsWidget::LayoutsWidget(QWidget *parent) : QStackedWidget(parent),
    sensWindow(new sensorWindow(nullptr)), addDialog(new AddDialog(nullptr)),

    deleteDialog(new DeleteDialog(nullptr))
{

    QVector<Sensor*> sensors=Json::caricaSensori();

    simuWindow = new Simulation(sensors);

    //DA CAMBIARE IL FATTO CHE SENSWINDOW NON RICEVE PARAMETRI, DEVE AVERE GLI STESSI SENSORI DI LAYOUTSWDIGET
    this->addWidget(sensWindow);
    this->addWidget(simuWindow);


    connect(sensWindow->searchMenu,&SearchMenu::showAddDialog, addDialog, [&]()
            {
                addDialog->open();
                addDialog->lineEdit->setFocus();
            });

    connect(addDialog->newButton,&QPushButton::clicked, this, [&]()
            {
                QString result=Json::nuovoSensore(addDialog->lineEdit->text(), addDialog->sceltaTipo->currentText());

                if(result=="ok"){
                    sensWindow->addSensor(Json::costruttore(addDialog->lineEdit->text(), addDialog->sceltaTipo->currentText()));
                    deleteDialog->sceltaNome->addItem(addDialog->lineEdit->text());
                    addDialog->lineEdit->clear();
                    addDialog->close();
                }else if(result=="existing"){
                    QMessageBox *existingName=new QMessageBox(nullptr);
                    existingName->setIcon(QMessageBox::Warning);
                    existingName->setText("Il sensore '" + addDialog->lineEdit->text() + "' esiste già nel file");
                    existingName->open();
                    addDialog->lineEdit->setFocus();
                }else if(result=="empty"){
                    QMessageBox *emptyName=new QMessageBox(nullptr);
                    emptyName->setIcon(QMessageBox::Warning);
                    emptyName->setText("Inserire un nome");
                    emptyName->open();
                    addDialog->lineEdit->setFocus();
                }
            });
    connect(sensWindow->searchMenu,&SearchMenu::showDeleteDialog, deleteDialog, &DeleteDialog::open);

    connect(deleteDialog->deleteButton,&QPushButton::clicked,this,[&]()
            {
                Json::eliminaSensore(deleteDialog->sceltaNome->currentText());
                sensWindow->deleteSensor(deleteDialog->sceltaNome->currentText());
                deleteDialog->close();
                deleteDialog->sceltaNome->removeItem(deleteDialog->sceltaNome->currentIndex());
            });
}












/*Eliminabile(?)
LayoutsWidget::LayoutsWidget(QVector<Sensor*> s,QWidget *parent):QStackedWidget(parent),
    //sensWindow(new QWidget),sensWindowLayout(new QHBoxLayout(sensWindow)),
    //sensScrollArea(new QWidget),sensLayout(new QVBoxLayout(sensScrollArea)),
    searchMenu(new SearchMenu(nullptr)),simuWindow(new QWidget),
    simuLayout(new QHBoxLayout(simuWindow)), addDialog(new AddDialog(nullptr)),
    deleteDialog(new DeleteDialog(nullptr))
{

    //QVector<Sensor*> sensors=Json::caricaSensori();
    for(auto it=s.begin();it!=s.end();++it){
        sensWindow->addSensor(*it);
    }

    this->addWidget(sensWindow);
    simuWidget = new Simulation(sensors);
    //costruzione layout simulazione
<<<<<<< HEAD
    //simuLayout->addWidget(new QPushButton("SUCA"));
    this->addWidget(simuWidget);
=======
    simuLayout->addWidget(new QPushButton("SUCA"));
    this->addWidget(simuWindow);
>>>>>>> main

    sensWindowLayout->addWidget(searchMenu);
    sensWindowLayout->addWidget(sensScrollArea);



    connect(searchMenu,&SearchMenu::showAddDialog, addDialog, [&]()
            {

                addDialog->open();
                addDialog->lineEdit->setFocus();
            });

    connect(addDialog->newButton,&QPushButton::clicked, this, [&]()

            {

                QString result=Json::nuovoSensore(addDialog->lineEdit->text(), addDialog->sceltaTipo->currentText());

                if(result=="ok"){
                    sensWindow->addSensor(Json::costruttore(addDialog->lineEdit->text(), addDialog->sceltaTipo->currentText()));
                    deleteDialog->sceltaNome->addItem(addDialog->lineEdit->text());
                    addDialog->lineEdit->clear();
                    addDialog->close();

                }
            });


    connect(deleteDialog->deleteButton,&QPushButton::clicked,this,[&]()
            {

                Json::eliminaSensore(deleteDialog->sceltaNome->currentText());
                sensWindow->deleteSensor(deleteDialog->sceltaNome->currentText());
                deleteDialog->close();
                deleteDialog->sceltaNome->removeItem(deleteDialog->sceltaNome->currentIndex());
            });


    connect(searchMenu,&SearchMenu::showDeleteDialog, deleteDialog, &DeleteDialog::open);

}
//Eliminabile(?)
LayoutsWidget::LayoutsWidget(QVector<QWidget*> frame,QWidget *parent):QStackedWidget(parent)
//,sensWindow(new QWidget),sensWindowLayout(new QHBoxLayout(sensWindow))//,sensScrollArea(new QWidget),sensLayout(new QVBoxLayout(sensScrollArea)), simuWidget(new QWidget), simuLayout(new QHBoxLayout(simuWidget))
{



    //costruzione layout sensori
    //searchMenu->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    sensWindowLayout->addWidget(searchMenu);
    sensWindowLayout->addWidget(sensScrollArea);


    for(auto i=0;i<frame.size();i++){
        sensLayout->addWidget(frame[i]);
    }
    this->addWidget(sensWindow);

    //costruzione layout simulazione
    simuLayout->addWidget(new QPushButton("SUCA"));
    this->addWidget(simuWindow);


}


//Eliminabile(?)
LayoutsWidget::LayoutsWidget(QVector<SensorPanel*> sp,QWidget *parent):QStackedWidget(parent)
//,sensWindow(new QWidget),sensWindowLayout(new QHBoxLayout(sensWindow))//,sensScrollArea(new QWidget),sensLayout(new QVBoxLayout(sensScrollArea)), simuWidget(new QWidget), simuLayout(new QHBoxLayout(simuWidget))
{
    SearchMenu *searchMenu=new SearchMenu;

    //costruzione layout sensori
    searchMenu->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    sensWindowLayout->addWidget(searchMenu);
    sensWindowLayout->addWidget(sensScrollArea);


    for(auto i=0;i<sp.size();i++){
        sensLayout->addWidget(sp[i]);
    }
    this->addWidget(sensWindow);

    //costruzione layout simulazione
    simuLayout->addWidget(new QPushButton("SUCA"));
    this->addWidget(simuWindow);
}
*/
LayoutsWidget::~LayoutsWidget(){};
