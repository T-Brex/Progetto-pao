#include "layoutswidget.h"
//#include "frontend/adddialog.h"
#include "qdialog.h"
#include "qmessagebox.h"
#include "qpushbutton.h"
//#include "searchMenu.h"
#include "backend/json.h"


LayoutsWidget::LayoutsWidget(QWidget *parent):QStackedWidget(parent),
    sensWindow(new QWidget),sensWindowLayout(new QHBoxLayout(sensWindow)),
    sensWidget(new QWidget),sensLayout(new QVBoxLayout(sensWidget)),
    simuWidget(new QWidget),simuLayout(new QHBoxLayout(simuWidget)),
    searchMenu(new SearchMenu(nullptr)), addDialog(new AddDialog(nullptr)),
    deleteDialog(new DeleteDialog(nullptr))
{

    QVector<Sensor*> sensors=Json::caricaSensori();
    for(auto it=sensors.begin();it!=sensors.end();++it){
        addSensor(*it);
    }

    this->addWidget(sensWindow);

    //costruzione layout simulazione
    simuLayout->addWidget(new QPushButton("SUCA"));
    this->addWidget(simuWidget);

    sensWindowLayout->addWidget(searchMenu);
    sensWindowLayout->addWidget(sensWidget);


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
    sensLayout->addWidget(sensorsPanels.last());
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
    sensWidget(new QWidget),sensLayout(new QVBoxLayout(sensWidget)),
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
    sensWindowLayout->addWidget(sensWidget);



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
