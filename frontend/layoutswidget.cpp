#include "layoutswidget.h"
#include "frontend/sensorwindow.h"
#include "frontend/simulation.h"
#include "frontend/modifydialog.h"
#include "qdialog.h"
#include "qmessagebox.h"
#include "qpushbutton.h"


#include "backend/json.h"
#include <QScrollArea>
#include <QFileDialog>


LayoutsWidget::LayoutsWidget(QWidget *parent) : QStackedWidget(parent),
    sensWindow(new sensorWindow(nullptr)),
    addDialog(new AddDialog),
    deleteDialog(new DeleteDialog(nullptr)),
    deleteAllWarning(new DeleteWarning(nullptr)),
    modifyDialog(new ModifyDialog(nullptr))
{
    this->addWidget(sensWindow);
    this->addWidget(new Simulation(Json::caricaSensori()));

    connect(sensWindow->searchMenu, &SearchMenu::showAddDialog, this, [&]() {
        addDialog->show();
        addDialog->getLineEdit()->setFocus();
    });

    connect(addDialog->getNewButton(), &QPushButton::clicked, this, [&]() {
        QString result = Json::nuovoSensore(addDialog->getLineEdit()->text(), addDialog->getSceltaTipo()->currentText());

        if (result == "ok") {
            sensWindow->addSensor(Json::costruttore(addDialog->getLineEdit()->text(), addDialog->getSceltaTipo()->currentText()));
            deleteDialog->getSceltaNome()->addItem(addDialog->getLineEdit()->text());
            addDialog->getLineEdit()->clear();
            addDialog->hide();
            this->update();
        } else if (result == "existing") {
            QMessageBox *existingName = new QMessageBox(nullptr);
            existingName->setIcon(QMessageBox::Warning);
            existingName->setText("Il sensore '" + addDialog->getLineEdit()->text() + "' esiste già nel file");
            existingName->show();
            addDialog->getLineEdit()->setFocus();
        } else if (result == "empty") {
            QMessageBox *emptyName = new QMessageBox(nullptr);
            emptyName->setIcon(QMessageBox::Warning);
            emptyName->setText("Inserire un nome");
            emptyName->show();
            addDialog->getLineEdit()->setFocus();
        }
    });

    connect(sensWindow->searchMenu, &SearchMenu::showModifyDialog, this, [&](const Sensor* sensor) {
        modifyDialog->getOldSensorName() = sensor->getName();
        modifyDialog->getOldSensorType() = sensor->getType();
        modifyDialog->getLineEdit()->setText(modifyDialog->getOldSensorName());
        modifyDialog->getSceltaTipo()->setCurrentText(modifyDialog->getOldSensorType());
        modifyDialog->show();
        modifyDialog->getLineEdit()->setFocus();
    });

    connect(sensWindow, &sensorWindow::showModifyDialog, this, [&](const Sensor* sensor) {
        modifyDialog->getOldSensorName() = sensor->getName();
        modifyDialog->getOldSensorType() = sensor->getType();
        modifyDialog->getLineEdit()->setText(modifyDialog->getOldSensorName());
        modifyDialog->getSceltaTipo()->setCurrentText(modifyDialog->getOldSensorType());
        modifyDialog->show();
        modifyDialog->getLineEdit()->setFocus();
    });

    connect(modifyDialog->getNewButton(), &QPushButton::clicked, this, [&]() {
        qDebug() << modifyDialog->getOldSensorName();
        QString result = Json::modificaSensore(modifyDialog->getOldSensorName(), modifyDialog->getLineEdit()->text(), modifyDialog->getSceltaTipo()->currentText());

        if (result == "ok") {
            sensWindow->modifySensor(modifyDialog->getOldSensorName(), modifyDialog->getLineEdit()->text(), modifyDialog->getSceltaTipo()->currentText());

            deleteDialog->getSceltaNome()->addItem(modifyDialog->getLineEdit()->text());

            // Rimuovere l'elemento dalla lista a discesa sceltaTipo
            int indexToRemove = deleteDialog->getSceltaNome()->findText(modifyDialog->getOldSensorName());
            if (indexToRemove != -1) {
                deleteDialog->getSceltaNome()->removeItem(indexToRemove);
            }


            modifyDialog->getLineEdit()->clear();
            modifyDialog->hide();
            this->update();
        } else if (result == "existing") {
            QMessageBox *existingName = new QMessageBox(nullptr);
            existingName->setIcon(QMessageBox::Warning);
            existingName->setText("Il sensore '" + modifyDialog->getLineEdit()->text() + "' esiste già nel file");
            existingName->show();
            modifyDialog->getLineEdit()->setFocus();
        } else if (result == "empty") {
            QMessageBox *emptyName = new QMessageBox(nullptr);
            emptyName->setIcon(QMessageBox::Warning);
            emptyName->setText("Inserire un nome");
            emptyName->show();
            modifyDialog->getLineEdit()->setFocus();
        }
    });


    connect(sensWindow->searchMenu,&SearchMenu::showDeleteDialog, deleteDialog, &DeleteDialog::show);
    connect(deleteDialog->getDeleteButton(),&QPushButton::clicked,this,[&]()
            {
                Json::eliminaSensore(deleteDialog->getSceltaNome()->currentText());
                sensWindow->deleteSensor(deleteDialog->getSceltaNome()->currentText());
                deleteDialog->hide();
                deleteDialog->getSceltaNome()->removeItem(deleteDialog->getSceltaNome()->currentIndex());
            });

    // Connect per mostrare il DeleteWarning e conservare il puntatore al sensore
    connect(sensWindow, &sensorWindow::showDeleteWarning, this, [=](const Sensor* sensor) {
        deleteOneWarning = new DeleteWarning(sensor->getName());
        deleteOneWarning->show();

        // Connect aggiornato per confermare l'eliminazione e usare il puntatore al sensore
        connect(deleteOneWarning, &DeleteWarning::confirmed, this, [this, sensor]() {
            if (sensor != nullptr) {
                int indexToRemove = deleteDialog->getSceltaNome()->findText(sensor->getName());
                if (indexToRemove != -1) {
                    deleteDialog->getSceltaNome()->removeItem(indexToRemove);
                }

                Json::eliminaSensore(sensor->getName());
                sensWindow->deleteSensor(sensor->getName());
                // Nascondi il DeleteWarning
                deleteOneWarning->hide();
            }
        });
    });


    connect(sensWindow->searchMenu, &::SearchMenu::showDeleteAllDialog, this, [=]() {
        deleteAllWarning->show();
    });

connect(deleteAllWarning,&DeleteWarning::confirmed, deleteAllWarning,[&]() {
    for(auto it=sensWindow->sensorsPanels.begin();it!=sensWindow->sensorsPanels.end();++it){
        Json::eliminaSensore((*it)->getName());
        deleteDialog->getSceltaNome()->removeItem(deleteDialog->getSceltaNome()->currentIndex());
    }
    sensWindow->deleteAllSensors();
    deleteAllWarning->hide();

});

    connect(sensWindow->searchMenu->lineEdit, &QLineEdit::textChanged, this, [&](const QString& searchText) {
        sensWindow->filterSensors(searchText);
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

                addDialog->show();
                addDialog->lineEdit->setFocus();
            });

    connect(addDialog->newButton,&QPushButton::clicked, this, [&]()

            {

                QString result=Json::nuovoSensore(addDialog->lineEdit->text(), addDialog->sceltaTipo->currentText());

                if(result=="ok"){
                    sensWindow->addSensor(Json::costruttore(addDialog->lineEdit->text(), addDialog->sceltaTipo->currentText()));
                    deleteDialog->getSceltaNome()->addItem(addDialog->lineEdit->text());
                    addDialog->lineEdit->clear();
                    addDialog->close();

                }
            });


    connect(deleteDialog->getDeleteButton(),&QPushButton::clicked,this,[&]()
            {

                Json::eliminaSensore(deleteDialog->getSceltaNome()->currentText());
                sensWindow->deleteSensor(deleteDialog->getSceltaNome()->currentText());
                deleteDialog->close();
                deleteDialog->getSceltaNome()->removeItem(deleteDialog->getSceltaNome()->currentIndex());
            });


    connect(searchMenu,&SearchMenu::showDeleteDialog, deleteDialog, &DeleteDialog::show);

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
