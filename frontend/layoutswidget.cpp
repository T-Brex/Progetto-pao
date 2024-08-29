#include "layoutswidget.h"
#include "frontend/sensorwindow.h"
#include "frontend/simulation.h"
#include "frontend/modifydialog.h"
#include "qdialog.h"
#include "qmessagebox.h"
#include "qpushbutton.h"
#include "backend/sensorgetter.h"


#include "backend/json.h"
#include <QScrollArea>
#include <QFileDialog>


LayoutsWidget::LayoutsWidget(QWidget *parent) : QStackedWidget(parent),
    sensWindow(new sensorWindow(nullptr)),
    addDialog(new AddDialog(this)),
    deleteDialog(new DeleteDialog(this)),
    deleteAllWarning(new DeleteWarning(this)),
    modifyDialog(new ModifyDialog(this))
{
    this->addWidget(sensWindow);
    this->addWidget(new Simulation(Json::caricaSensori()));

    connect(sensWindow->getSearchMenu(), &SearchMenu::showAddDialog, this, [&]() {
        addDialog->show();
        addDialog->getLineEdit()->setFocus();
    });

    connect(addDialog->getConfirmButton(), &QPushButton::clicked, this, [&]() {
        QString result = Json::nuovoSensore(addDialog->getLineEdit()->text(), addDialog->getSceltaTipo()->currentText());

        if (result == "ok") {
            sensWindow->addSensor(Json::costruttore(addDialog->getLineEdit()->text(), addDialog->getSceltaTipo()->currentText()));
            deleteDialog->getSceltaNome()->addItem(addDialog->getLineEdit()->text());
            addDialog->getLineEdit()->clear();
            addDialog->hide();
            sensWindow->getSearchMenu()->updateSensori();
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

    connect(sensWindow->getSearchMenu(), &SearchMenu::showModifyDialog, this, [&](const Sensor* sensor) {
        modifyDialog->setOldSensorName(sensor->getName());
        modifyDialog->setOldSensorType(sensor->getType());
        modifyDialog->getLineEdit()->setText(modifyDialog->getOldSensorName());
        modifyDialog->getSceltaTipo()->setCurrentText(modifyDialog->getOldSensorType());

        modifyDialog->show();
        modifyDialog->getLineEdit()->setFocus();
    });

    connect(sensWindow, &sensorWindow::showModifyDialog, this, [&](const Sensor* sensor) {




        /*for(int i=0;i<mVec.size();i++){
            modifyDialog->getMinimiEdit().push_back(mVec[i]->getRangeMin());
            modifyDialog->getMassimiEdit().push_back(mVec[i]->getRangeMax());
        }*/
        //qDebug()<<sensor->getName();
        sensor=Json::trovaSensorePerNome(sensor->getName());
        QVector<Measurement*> mVec;
        SensorGetter sg(mVec);
        const_cast<Sensor*>(sensor)->accept(sg);
        //qDebug()<<sensor->getName();
        modifyDialog->setOldSensorName(sensor->getName());
        modifyDialog->setOldSensorType(sensor->getType());
        modifyDialog->getLineEdit()->setText(modifyDialog->getOldSensorName());
        modifyDialog->getSceltaTipo()->setCurrentText(modifyDialog->getOldSensorType());

    QLayoutItem* item;
    while ((item = modifyDialog->getParametriLayout()->takeAt(0)) != nullptr) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();  // Elimina il widget associato
        }
    }
    delete item;  // Elimina l'item stesso
        modifyDialog->getMassimiEdit().clear();
        modifyDialog->getMinimiEdit().clear();
        // Aggiungi i dati del sensore alla griglia, centrati
        for (int i = 0; i < mVec.size(); i++) {
            //qDebug()<<mVec[i]->getName();
            QLabel* misura = new QLabel(mVec[i]->getName());
            misura->setAlignment(Qt::AlignCenter);
            modifyDialog->getParametriLayout()->addWidget(misura, i + 1, 0); // Colonna 0 per "Misura"

            //qDebug()<<"range Min:"<<mVec[i]->getRangeMin();
            QLineEdit* minEdit = new QLineEdit(QString::number(mVec[i]->getRangeMin()));
            minEdit->setAlignment(Qt::AlignCenter);
            modifyDialog->getParametriLayout()->addWidget(minEdit, i + 1, 1); // Colonna 1 per "Min"
            modifyDialog->getMinimiEdit().push_back(minEdit); // Aggiungi QLineEdit al QVector

            //qDebug()<<"range Max:"<<mVec[i]->getRangeMax();
            QLineEdit* maxEdit = new QLineEdit(QString::number(mVec[i]->getRangeMax()));
            maxEdit->setAlignment(Qt::AlignCenter);
            modifyDialog->getParametriLayout()->addWidget(maxEdit, i + 1, 2); // Colonna 2 per "Max"
            modifyDialog->getMassimiEdit().push_back(maxEdit); // Aggiungi QLineEdit al QVector

        }
        //modifyDialog->getLayout()->removeWidget(modifyDialog->getConfirmButton());
        modifyDialog->getLayout()->addWidget(modifyDialog->getConfirmButton());
        modifyDialog->show();
        modifyDialog->getLineEdit()->setFocus();
    });

    connect(modifyDialog->getConfirmButton(), &QPushButton::clicked, this, [&]() {

        QVector<double> minimi;
        QVector<double> massimi;
bool tuttiInt = true;  // Flag per verificare se tutti i valori sono interi

// Iterare attraverso i QLineEdit di Minimi
for (int i = 0; i < modifyDialog->getMinimiEdit().size(); i++) {
    bool isInt = false; // Variabile per controllare la conversione
    int minValue = modifyDialog->getMinimiEdit()[i]->text().toInt(&isInt);

    if (isInt) {
        minimi.push_back(static_cast<double>(minValue)); // Aggiungi se è un intero
    } else {
        tuttiInt = false;  // Setta il flag a false se un valore non è intero
    }

    int maxValue = modifyDialog->getMassimiEdit()[i]->text().toInt(&isInt);

    if (isInt) {
        massimi.push_back(static_cast<double>(maxValue)); // Aggiungi se è un intero
    } else {
        tuttiInt = false;  // Setta il flag a false se un valore non è intero
    }
}

    if (!tuttiInt) {
        // Se qualche valore non è un intero, mostra un messaggio di avviso
        QMessageBox* notInt = new QMessageBox;
        notInt->setText("La modifica di massimi/minimi richiede dei valori interi.");
        notInt->show();
    } else {
        QString result = Json::modificaSensore(modifyDialog->getOldSensorName(), modifyDialog->getLineEdit()->text(), modifyDialog->getSceltaTipo()->currentText(),minimi,massimi);

        if (result == "ok") {
            sensWindow->modifySensor(modifyDialog->getOldSensorName(), modifyDialog->getLineEdit()->text(), modifyDialog->getSceltaTipo()->currentText());
            //qDebug() << "dentro if"<<modifyDialog->getOldSensorName()<<modifyDialog->getLineEdit()->text()<<modifyDialog->getSceltaTipo()->currentText();
            deleteDialog->getSceltaNome()->addItem(modifyDialog->getLineEdit()->text());

            // Rimuovere l'elemento dalla lista a discesa sceltaTipo
            int indexToRemove = deleteDialog->getSceltaNome()->findText(modifyDialog->getOldSensorName());
            if (indexToRemove != -1) {
                deleteDialog->getSceltaNome()->removeItem(indexToRemove);
            }


            modifyDialog->getLineEdit()->clear();
            modifyDialog->hide();
            sensWindow->getSearchMenu()->updateSensori();
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
}
    });


    connect(sensWindow->getSearchMenu(),&SearchMenu::showDeleteDialog, deleteDialog, &DeleteDialog::open);
    connect(deleteDialog->getDeleteButton(),&QPushButton::clicked,this,[&]()
            {
                Json::eliminaSensore(deleteDialog->getSceltaNome()->currentText());
                sensWindow->deleteSensor(deleteDialog->getSceltaNome()->currentText());
                sensWindow->getSearchMenu()->updateSensori();
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
                sensWindow->getSearchMenu()->updateSensori();
                // Nascondi il DeleteWarning
                deleteOneWarning->hide();
            }
        });
    });


    connect(sensWindow->getSearchMenu(), &::SearchMenu::showDeleteAllDialog, this, [=]() {
        deleteAllWarning->show();
    });

connect(deleteAllWarning,&DeleteWarning::confirmed, deleteAllWarning,[&]() {
    for(auto it=sensWindow->getSensorsPanels().begin();it!=sensWindow->getSensorsPanels().end();++it){
        Json::eliminaSensore((*it)->getName());
        deleteDialog->getSceltaNome()->removeItem(deleteDialog->getSceltaNome()->currentIndex());
    }
    sensWindow->deleteAllSensors();
    deleteAllWarning->hide();
    sensWindow->getSearchMenu()->updateSensori();

});

    connect(sensWindow->getSearchMenu()->getLineEdit(), &QLineEdit::textChanged, this, [&](const QString& searchText) {
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
