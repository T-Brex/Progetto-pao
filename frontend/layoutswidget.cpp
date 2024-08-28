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
        QVector<Measurement*> mVec;
        SensorGetter sg(mVec);
        const_cast<Sensor*>(sensor)->accept(sg);

        /*DA DEFINIRE I GET DI "mVec"
        for(int i=0;i<mVec.size();i++){
            modifyDialog->getMinimiEdit().push_back(mVec[i]->get);
            modifyDialog->getMassimiEdit().push_back(mVec[i]->get);
        }*/
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



        QLabel* misuraLabel = new QLabel("Misura");
        misuraLabel->setAlignment(Qt::AlignCenter);
        modifyDialog->getParametriLayout()->addWidget(misuraLabel, 0, 0);

        QLabel* minLabel = new QLabel("Min");
        minLabel->setAlignment(Qt::AlignCenter);
        modifyDialog->getParametriLayout()->addWidget(minLabel, 0, 1);

        QLabel* maxLabel = new QLabel("Max");
        maxLabel->setAlignment(Qt::AlignCenter);
        modifyDialog->getParametriLayout()->addWidget(maxLabel, 0, 2);

        // Aggiungi i dati del sensore alla griglia, centrati
        for (int i = 0; i < mVec.size(); i++) {
            QLabel* misura = new QLabel(mVec[i]->getName());
            misura->setAlignment(Qt::AlignCenter);
            modifyDialog->getParametriLayout()->addWidget(misura, i + 1, 0); // Colonna 0 per "Misura"

            QLineEdit* minEdit = new QLineEdit("22" /*mVec[i]->getMinDistribution()*/);
            minEdit->setAlignment(Qt::AlignCenter);
            modifyDialog->getParametriLayout()->addWidget(minEdit, i + 1, 1); // Colonna 1 per "Min"
            modifyDialog->getMinimiEdit().clear();
            modifyDialog->getMinimiEdit().push_back(minEdit); // Aggiungi QLineEdit al QVector

            QLineEdit* maxEdit = new QLineEdit("55" /*mVec[i]->getMaxDistribution()*/);
            maxEdit->setAlignment(Qt::AlignCenter);
            modifyDialog->getParametriLayout()->addWidget(maxEdit, i + 1, 2); // Colonna 2 per "Max"
            modifyDialog->getMassimiEdit().clear();
            modifyDialog->getMassimiEdit().push_back(maxEdit); // Aggiungi QLineEdit al QVector
        }
        modifyDialog->show();
    });

    connect(modifyDialog->getConfirmButton(), &QPushButton::clicked, this, [&]() {
        QVector<double> minimi;
        QVector<double> massimi;
        bool tuttiInt=true;
        qDebug()<<"fuori for";
        for (int i = 0; i < modifyDialog->getMassimiEdit().size(); i++) {
            qDebug()<<"dentro for";
            bool intero=true;
            if (modifyDialog->getMinimiEdit()[i] == nullptr || modifyDialog->getMassimiEdit()[i] == nullptr) {
                qDebug() << "Error: QLineEdit is null at index" << i;
                return;
            }
            int min = modifyDialog->getMinimiEdit()[i]->text().toInt(&intero);
            qDebug()<<"intero:"<<min;
            if(intero){
                minimi.push_back(min);
                qDebug()<<"minimo intero:"<<min;
            }else{
                tuttiInt=false;
                qDebug()<<"minimo non intero";
            }

            int max = modifyDialog->getMassimiEdit()[i]->text().toInt(&intero);
            if(intero){
                massimi.push_back(max);
                 qDebug()<<"massimo intero:"<<max;
            }else{
                tuttiInt=false;
                qDebug()<<"massimo non intero";
            }
        }
        if(tuttiInt)
        {
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



LayoutsWidget::~LayoutsWidget(){}
