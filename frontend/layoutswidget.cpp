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

        modifyDialog->setOldSensorName(sensor->getName());
        modifyDialog->setOldSensorType(sensor->getType());
        modifyDialog->getLineEdit()->setText(modifyDialog->getOldSensorName());
        modifyDialog->getLineEdit()->setFocus();
        modifyDialog->getSceltaTipo()->setCurrentText(modifyDialog->getOldSensorType());

        //Svuotamento modifyDialog.parametriLayout
        QLayoutItem* item;
        while ((item = modifyDialog->getParametriLayout()->takeAt(0)) != nullptr) {
            if (QWidget* widget = item->widget()) {
                widget->deleteLater();
            }
            delete item;
        }


        QVector<Measurement*> mVec;
        SensorGetter sg(mVec);
        const_cast<Sensor*>(sensor)->accept(sg);

        modifyDialog->getParametriLayout()->addWidget(new QLabel("Misura"), 0, 0);
        modifyDialog->getParametriLayout()->addWidget(new QLabel("Min"), 0, 1);
        modifyDialog->getParametriLayout()->addWidget(new QLabel("Max"), 0, 2);

        // Aggiungi i dati del sensore alla griglia
        for (int i = 0; i < mVec.size(); i++) {
            modifyDialog->getParametriLayout()->addWidget(new QLabel(mVec[i]->getName()), i + 1, 0); // Colonna 0 per "Misura"
            modifyDialog->getParametriLayout()->addWidget(new QLineEdit("22"), i + 1, 1);            // Colonna 1 per "Min"
            modifyDialog->getParametriLayout()->addWidget(new QLineEdit("55"), i + 1, 2);            // Colonna 2 per "Max"
        }
        modifyDialog->show();
    });

    connect(modifyDialog->getConfirmButton(), &QPushButton::clicked, this, [&]() {

        QString result = Json::modificaSensore(modifyDialog->getOldSensorName(), modifyDialog->getLineEdit()->text(), modifyDialog->getSceltaTipo()->currentText());

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



LayoutsWidget::~LayoutsWidget(){}
