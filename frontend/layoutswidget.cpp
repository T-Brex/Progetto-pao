#include "layoutswidget.h"
//#include "frontend/adddialog.h"
//#include "frontend/sensorwindow.h"
#include "frontend/sensorwindow.h"
#include "frontend/simulation.h"
#include "qdialog.h"
#include "qmessagebox.h"
#include "qpushbutton.h"
//#include "searchMenu.h"
#include "backend/json.h"
#include <QScrollArea>


LayoutsWidget::LayoutsWidget(QWidget *parent) : QStackedWidget(parent),
    sensWindow(new QWidget), sensWindowLayout(new QHBoxLayout(sensWindow)),
    sensScrollArea(new QScrollArea()),sensWidget(new QWidget()),sensLayout(new QVBoxLayout(sensWidget)),
    dustWidget(new QWidget), dustLayout(new QHBoxLayout(dustWidget)),
    humidityWidget(new QWidget), humidityLayout(new QHBoxLayout(humidityWidget)),
    windWidget(new QWidget), windLayout(new QHBoxLayout(windWidget)),
    termometerWidget(new QWidget), termometerLayout(new QHBoxLayout(termometerWidget)),
    airQualityWidget(new QWidget), airQualityLayout(new QHBoxLayout(airQualityWidget)),
    searchMenu(new SearchMenu(nullptr)), simuWidget(new QWidget),
    simuLayout(new QHBoxLayout(simuWidget)), addDialog(new AddDialog(nullptr)),
    deleteDialog(new DeleteDialog(nullptr))
{
    sensScrollArea->setWidgetResizable(true);
    sensScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    sensScrollArea->setWidget(sensWidget);

    sensLayout->addWidget(dustWidget);
    sensLayout->addWidget(humidityWidget);
    sensLayout->addWidget(windWidget);
    sensLayout->addWidget(termometerWidget);
    sensLayout->addWidget(airQualityWidget);

    QVector<Sensor*> sensors=Json::caricaSensori();
    for(auto it=sensors.begin();it!=sensors.end();++it){
        addSensor(*it);
    }

    //sensWindowLayout->addWidget(searchMenu);
    //sensWindowLayout->addWidget(sensScrollArea);

    simuLayout->addWidget(new Simulation(sensors));

    this->addWidget(new sensorWindow(nullptr));
    this->addWidget(simuWidget);


    connect(searchMenu,&SearchMenu::showAddDialog, addDialog, [&]()
            {
                addDialog->open();
                addDialog->lineEdit->setFocus();
            });

    connect(addDialog->newButton,&QPushButton::clicked, this, [&]()
            {
                QString result=Json::nuovoSensore(addDialog->lineEdit->text(), addDialog->sceltaTipo->currentText());

                if(result=="ok"){
                    addSensor(Json::costruttore(addDialog->lineEdit->text(), addDialog->sceltaTipo->currentText()));
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

    connect(deleteDialog->deleteButton,&QPushButton::clicked,this,[&]()
            {
                Json::eliminaSensore(deleteDialog->sceltaNome->currentText());
                deleteSensor(deleteDialog->sceltaNome->currentText());
                deleteDialog->close();
                deleteDialog->sceltaNome->removeItem(deleteDialog->sceltaNome->currentIndex());
            });


    connect(searchMenu,&SearchMenu::showDeleteDialog, deleteDialog, &DeleteDialog::open);

}

void LayoutsWidget::addSensor(Sensor *s) {
    sensorsPanels.push_back(new SensorPanel(*s));
    if(s->getType()=="Dust")
        dustLayout->addWidget(sensorsPanels.last());
    if(s->getType()=="Humidity")
        humidityLayout->addWidget(sensorsPanels.last());
    if(s->getType()=="Wind")
        windLayout->addWidget(sensorsPanels.last());
    if(s->getType()=="Termometer")
        termometerLayout->addWidget(sensorsPanels.last());
    if(s->getType()=="AirQuality")
        airQualityLayout->addWidget(sensorsPanels.last());
}
void LayoutsWidget::deleteSensor(QString s) {
    for(auto it = sensorsPanels.begin(); it != sensorsPanels.end(); ++it) {
        if((*it)->getName() == s) {
            // Rimuovi il widget dalla disposizione
            sensLayout->removeWidget(*it);
            sensLayout->update();
            // Dealloca il widget
            delete *it;
            // Rimuovi il puntatore dal vettore
            it = sensorsPanels.erase(it);


            // Assicurati di non superare la fine del vettore
            if (it == sensorsPanels.end())
                break;

        }
    }

}












//Eliminabile(?)
LayoutsWidget::LayoutsWidget(QVector<Sensor*> s,QWidget *parent):QStackedWidget(parent),
    sensWindow(new QWidget),sensWindowLayout(new QHBoxLayout(sensWindow)),
    //sensScrollArea(new QWidget),sensLayout(new QVBoxLayout(sensScrollArea)),
    simuWidget(new QWidget),simuLayout(new QHBoxLayout(simuWidget)),
    searchMenu(new SearchMenu(nullptr)), addDialog(new AddDialog(nullptr)),
    deleteDialog(new DeleteDialog(nullptr))
{

    //QVector<Sensor*> sensors=Json::caricaSensori();
    for(auto it=s.begin();it!=s.end();++it){
        addSensor(*it);
    }

    this->addWidget(sensWindow);

    //costruzione layout simulazione
    simuLayout->addWidget(new QPushButton("SUCA"));
    this->addWidget(simuWidget);

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
                    addSensor(Json::costruttore(addDialog->lineEdit->text(), addDialog->sceltaTipo->currentText()));
                    deleteDialog->sceltaNome->addItem(addDialog->lineEdit->text());
                    addDialog->lineEdit->clear();
                    addDialog->close();

                }
            });


    connect(deleteDialog->deleteButton,&QPushButton::clicked,this,[&]()
            {

                Json::eliminaSensore(deleteDialog->sceltaNome->currentText());
                deleteSensor(deleteDialog->sceltaNome->currentText());
                deleteDialog->close();
                deleteDialog->sceltaNome->removeItem(deleteDialog->sceltaNome->currentIndex());
            });


    connect(searchMenu,&SearchMenu::showDeleteDialog, deleteDialog, &DeleteDialog::open);

}
//Eliminabile(?)
LayoutsWidget::LayoutsWidget(QVector<QWidget*> frame,QWidget *parent):QStackedWidget(parent),
sensWindow(new QWidget),sensWindowLayout(new QHBoxLayout(sensWindow))//,sensScrollArea(new QWidget),sensLayout(new QVBoxLayout(sensScrollArea)), simuWidget(new QWidget), simuLayout(new QHBoxLayout(simuWidget))
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
    this->addWidget(simuWidget);


}


//Eliminabile(?)
LayoutsWidget::LayoutsWidget(QVector<SensorPanel*> sp,QWidget *parent):QStackedWidget(parent),
sensWindow(new QWidget),sensWindowLayout(new QHBoxLayout(sensWindow))//,sensScrollArea(new QWidget),sensLayout(new QVBoxLayout(sensScrollArea)), simuWidget(new QWidget), simuLayout(new QHBoxLayout(simuWidget))
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
    this->addWidget(simuWidget);
}

LayoutsWidget::~LayoutsWidget(){};
