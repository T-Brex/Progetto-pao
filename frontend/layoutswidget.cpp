#include "layoutswidget.h"
#include "frontend/modifydialog.h"
#include "frontend/sensorwindow.h"
#include "qdialog.h"
#include "qmessagebox.h"
#include "qpushbutton.h"
#include "backend/json.h"
#include <QScrollArea>
#include <QFileDialog>


LayoutsWidget::LayoutsWidget(QWidget *parent) : QStackedWidget(parent),
    sensWindow(new sensorWindow(nullptr)), addDialog(new AddDialog),
    deleteDialog(new DeleteDialog(nullptr)),deleteWarning(new DeleteWarning(nullptr)),
    modifyDialog(new ModifyDialog)
{
    //UTILE SE LA "simulationWindow" e "sensWindow" condividessero gli stessi sensori!
    //QVector<Sensor*> sensors=Json::caricaSensori();


    //DA CAMBIARE IL FATTO CHE SENSWINDOW NON RICEVE PARAMETRI, DEVE AVERE GLI STESSI SENSORI DI LAYOUTSWDIGET
    this->addWidget(sensWindow);
    this->addWidget(new QPushButton("suca"));

    //ModifyDialog* modifyDialog = new ModifyDialog;


    connect(sensWindow->searchMenu,&SearchMenu::showAddDialog, addDialog, [&]()
            {
                addDialog->show();
                addDialog->lineEdit->setFocus();
            });

    connect(addDialog->newButton,&QPushButton::clicked, this, [&]()
            {
                QString result=Json::nuovoSensore(addDialog->lineEdit->text(), addDialog->sceltaTipo->currentText());

                if(result=="ok"){
                    sensWindow->addSensor(Json::costruttore(addDialog->lineEdit->text(), addDialog->sceltaTipo->currentText()));
                    deleteDialog->sceltaNome->addItem(addDialog->lineEdit->text());
                    addDialog->lineEdit->clear();
                    addDialog->hide();
                    this->update();
                }else if(result=="existing"){
                    QMessageBox *existingName=new QMessageBox(nullptr);
                    existingName->setIcon(QMessageBox::Warning);
                    existingName->setText("Il sensore '" + addDialog->lineEdit->text() + "' esiste già nel file");
                    existingName->show();
                    addDialog->lineEdit->setFocus();
                }else if(result=="empty"){
                    QMessageBox *emptyName=new QMessageBox(nullptr);
                    emptyName->setIcon(QMessageBox::Warning);
                    emptyName->setText("Inserire un nome");
                    emptyName->show();
                    addDialog->lineEdit->setFocus();
                }
            });

    connect(sensWindow->searchMenu, &SearchMenu::showModifyDialog, this, [&](const Sensor* sensor) {
        modifyDialog->oldSensorName=sensor->getName();
        modifyDialog->oldSensorType=sensor->getType();
        modifyDialog->lineEdit->setText(modifyDialog->oldSensorName);
        modifyDialog->sceltaTipo->setCurrentText(modifyDialog->oldSensorType);
        modifyDialog->show();
        modifyDialog->lineEdit->setFocus();
    });

    connect(modifyDialog->newButton,&QPushButton::clicked, this, [&]()
            {
        qDebug()<<modifyDialog->oldSensorName;
        QString result=Json::modificaSensore(modifyDialog->oldSensorName,modifyDialog->lineEdit->text(), modifyDialog->sceltaTipo->currentText());

        if(result=="ok"){
            sensWindow->modifySensor(modifyDialog->oldSensorName,modifyDialog->lineEdit->text(), modifyDialog->sceltaTipo->currentText());
            deleteDialog->sceltaNome->addItem(modifyDialog->lineEdit->text());

            // Rimuovere l'elemento dalla lista a discesa sceltaTipo
            int indexToRemove = modifyDialog->sceltaTipo->findText(modifyDialog->oldSensorName);
            if (indexToRemove != -1) {
                modifyDialog->sceltaTipo->removeItem(indexToRemove);
            }
            modifyDialog->lineEdit->clear();
            modifyDialog->hide();
            this->update();
        }else if(result=="existing"){
            QMessageBox *existingName=new QMessageBox(nullptr);
            existingName->setIcon(QMessageBox::Warning);
            existingName->setText("Il sensore '" + modifyDialog->lineEdit->text() + "' esiste già nel file");
            existingName->show();
            modifyDialog->lineEdit->setFocus();
        }else if(result=="empty"){
            QMessageBox *emptyName=new QMessageBox(nullptr);
            emptyName->setIcon(QMessageBox::Warning);
            emptyName->setText("Inserire un nome");
            emptyName->show();
            modifyDialog->lineEdit->setFocus();
        }

            });

    connect(sensWindow->searchMenu,&SearchMenu::showImportDialog, this, [&]()
            {
        QString fileName = QFileDialog::getOpenFileName(nullptr, "Seleziona un file", "", "JSON Files (*.json)");

        // Verifica se l'utente ha selezionato un file
        if (!fileName.isEmpty()) {
            qDebug() << "Hai selezionato il file:" << fileName;
            QVector<Sensor*>nuoviSensori=Json::caricaSensori(fileName);
            for(auto i=nuoviSensori.begin();i!=nuoviSensori.end();++i){
                if(Json::nuovoSensore((*i)->getName(),(*i)->getType())=="ok"){
                    sensWindow->addSensor(*i);
                    deleteDialog->sceltaNome->addItem((*i)->getName());
                }
            }
        } else {
            qDebug() << "Nessun file selezionato.";
        }
            });


    connect(sensWindow->searchMenu, &SearchMenu::showSaveAsDialog, this, [=]() {
        QString newFileName = QFileDialog::getSaveFileName(this, tr("Save As"), "", tr("JSON Files (*.json)"));
        if (!newFileName.isEmpty()) {
            Json::saveAs(Json::caricaSensori(), newFileName);
            qDebug() << "Sensori salvati in:" << newFileName;
        }
    });
    connect(sensWindow->searchMenu,&SearchMenu::showDeleteDialog, deleteDialog, &DeleteDialog::show);
    connect(deleteDialog->deleteButton,&QPushButton::clicked,this,[&]()
            {
                Json::eliminaSensore(deleteDialog->sceltaNome->currentText());
                sensWindow->deleteSensor(deleteDialog->sceltaNome->currentText());
                deleteDialog->hide();
                deleteDialog->sceltaNome->removeItem(deleteDialog->sceltaNome->currentIndex());
            });


    connect(sensWindow->searchMenu,&SearchMenu::showDeleteAllDialog, deleteWarning,&DeleteWarning::show);


connect(deleteWarning,&DeleteWarning::confirmed, deleteWarning,[&]() {
    for(auto it=sensWindow->sensorsPanels.begin();it!=sensWindow->sensorsPanels.end();++it){
        Json::eliminaSensore((*it)->getName());
        deleteDialog->sceltaNome->removeItem(deleteDialog->sceltaNome->currentIndex());
    }
    sensWindow->deleteAllSensors();
    deleteWarning->hide();

});

    connect(sensWindow->searchMenu->lineEdit, &QLineEdit::textChanged, this, [&](const QString& searchText) {
        sensWindow->filterSensors(searchText);
    });

//connect(addDialog->newButton,&QPushButton::clicked, this, [&]()

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

    //costruzione layout simulazione
    simuLayout->addWidget(new QPushButton("SUCA"));
    this->addWidget(simuWindow);

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
