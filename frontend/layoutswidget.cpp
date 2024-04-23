#include "layoutswidget.h"
//#include "frontend/adddialog.h"
#include "qdialog.h"
#include "qpushbutton.h"
//#include "searchMenu.h"
#include "backend/json.h"


LayoutsWidget::LayoutsWidget(QWidget *parent):QStackedWidget(parent),
    sensWindow(new QWidget),sensWindowLayout(new QHBoxLayout(sensWindow)),sensWidget(new QWidget),sensLayout(new QVBoxLayout(sensWidget)), simuWidget(new QWidget), simuLayout(new QHBoxLayout(simuWidget))
    ,searchMenu(new SearchMenu(this)),addDialog(new AddDialog(this)),deleteDialog(new DeleteDialog(this))
    //,dialog(new Dialog(nullptr))
{

    SearchMenu *searchMenu=new SearchMenu;

    //costruzione layout sensori
    sensWindowLayout->addWidget(searchMenu);

    simuLayout->addWidget(new QPushButton("SUCA"));
    this->addWidget(simuWidget);

    //costruzione layout simulazione
    sensLayout->addWidget(new QPushButton("Fottiti la granda"));
    this->addWidget(sensWindow);
}

LayoutsWidget::LayoutsWidget(QVector<Sensor*> s,QWidget *parent):QStackedWidget(parent),
    sensWindow(new QWidget),sensWindowLayout(new QHBoxLayout(sensWindow)),
    sensWidget(new QWidget),sensLayout(new QVBoxLayout(sensWidget)),
    simuWidget(new QWidget),simuLayout(new QHBoxLayout(simuWidget)),
    searchMenu(new SearchMenu(nullptr)), addDialog(new AddDialog(nullptr)),
    deleteDialog(new DeleteDialog(nullptr))
{

    QVector<Sensor*> sensors=Json::caricaSensori();
    int i=0;
    for(auto it=sensors.begin();it!=sensors.end();++it){
        sensorsPanels.push_back(new SensorPanel(*sensors[i]));
        sensLayout->addWidget(sensorsPanels[i]);
        ++i;
    }

    this->addWidget(sensWindow);

    //costruzione layout simulazione
    simuLayout->addWidget(new QPushButton("SUCA"));
    this->addWidget(simuWidget);

    sensWindowLayout->addWidget(searchMenu);
    sensWindowLayout->addWidget(sensWidget);


    connect(searchMenu,&SearchMenu::showAddDialog, addDialog, [&](){
        addDialog->open();
        addDialog->lineEdit->setFocus();
    });

    connect(addDialog, &AddDialog::newTrigger, this, [&]()
            {
                QString result=Json::nuovoSensore(addDialog->lineEdit->text(), addDialog->sceltaTipo->currentText());

                if(result=="ok"){
                    addSensor(Json::costruttore(addDialog->lineEdit->text(), addDialog->sceltaTipo->currentText()));
                    deleteDialog->sceltaNome->addItem(addDialog->lineEdit->text());
                    addDialog->lineEdit->clear();
                    addDialog->close();
                }else{
                    addDialog->lineEdit->setFocus();
                }
            });

    connect(deleteDialog->deleteButton,&QPushButton::clicked,this,[&](){
        Json::eliminaSensore(deleteDialog->sceltaNome->currentText());
        deleteSensor(deleteDialog->sceltaNome->currentText());
        deleteDialog->close();
        deleteDialog->sceltaNome->removeItem(deleteDialog->sceltaNome->currentIndex());
    });


    connect(searchMenu,&SearchMenu::showDeleteDialog, deleteDialog, &DeleteDialog::open);

}

void LayoutsWidget::addSensor(Sensor *s) {
    sensorsPanels.push_back(new SensorPanel(*s));
    sensLayout->addWidget(sensorsPanels.last());
}
void LayoutsWidget::deleteSensor(QString s) {
    for(auto it = sensorsPanels.begin(); it != sensorsPanels.end(); ++it) {
        qDebug() << (*it)->getName() << "==" << s;
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
LayoutsWidget::LayoutsWidget(QVector<QWidget*> frame,QWidget *parent):QStackedWidget(parent),
sensWindow(new QWidget),sensWindowLayout(new QHBoxLayout(sensWindow)),sensWidget(new QWidget),sensLayout(new QVBoxLayout(sensWidget)), simuWidget(new QWidget), simuLayout(new QHBoxLayout(simuWidget))
{



    //costruzione layout sensori
    //searchMenu->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    sensWindowLayout->addWidget(searchMenu);
    sensWindowLayout->addWidget(sensWidget);


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
sensWindow(new QWidget),sensWindowLayout(new QHBoxLayout(sensWindow)),sensWidget(new QWidget),sensLayout(new QVBoxLayout(sensWidget)), simuWidget(new QWidget), simuLayout(new QHBoxLayout(simuWidget))
{
    SearchMenu *searchMenu=new SearchMenu;

    //costruzione layout sensori
    searchMenu->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    sensWindowLayout->addWidget(searchMenu);
    sensWindowLayout->addWidget(sensWidget);


    for(auto i=0;i<sp.size();i++){
        sensLayout->addWidget(sp[i]);
    }
    this->addWidget(sensWindow);

    //costruzione layout simulazione
    simuLayout->addWidget(new QPushButton("SUCA"));
    this->addWidget(simuWidget);
}

LayoutsWidget::~LayoutsWidget(){};
