#include "mainwindow.h"
#include "frontend/sensorPanel.h"
#include <QApplication>
#include <QRadioButton>
#include <QMenuBar>


MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent),layoutsWidget(new LayoutsWidget()),menuBar(new MenuBar)
{
    setMenuBar(menuBar);
    connect(menuBar, &MenuBar::changeLayoutTrigger, this, &MainWindow::changeLayout);
    setCentralWidget(layoutsWidget);
}

MainWindow::~MainWindow() {}

MainWindow::MainWindow(QVector<Sensor*> s, QWidget *parent):
    QMainWindow(parent),layoutsWidget(new LayoutsWidget(s)),menuBar(new MenuBar)
{

    setMenuBar(menuBar);
    connect(menuBar, &MenuBar::changeLayoutTrigger, this, &MainWindow::changeLayout);
    setCentralWidget(layoutsWidget);
}


MainWindow::MainWindow(QVector<SensorPanel*> sp, QWidget *parent):
    QMainWindow(parent),layoutsWidget(new LayoutsWidget(sp)),menuBar(new MenuBar)
{
    setMenuBar(menuBar);
    connect(menuBar, &MenuBar::changeLayoutTrigger, this, &MainWindow::changeLayout);
    setCentralWidget(layoutsWidget);
}



MainWindow::MainWindow(QVector<QWidget*> frame, QWidget *parent):
    QMainWindow(parent),layoutsWidget(new LayoutsWidget(frame)),menuBar(new MenuBar)
{

    const QString *p = new QString("prova");
    QLineEdit *lineEdit_nome = new QLineEdit("provaLoad");

    setMenuBar(menuBar);
    connect(menuBar, &MenuBar::changeLayoutTrigger, this, &MainWindow::changeLayout);
   //connect()
    connect(menuBar, &MenuBar::saveTrigger, this,  [&]()
        {
            save(*p);
        });

    connect(menuBar, &MenuBar::loadTrigger, this, [&]()
    {
        load(lineEdit_nome);
    });
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

void MainWindow::save(const QString &nome)
{
    QJsonObject dati;
    dati["nome"] = nome;

    QJsonDocument document(dati);
    QFile file("resources/dati.json");
    if (file.open(QIODevice::WriteOnly)) {
        file.write(document.toJson());
        file.close();
        //qDebug() << "Dati salvati con successo.";
    }
}

void MainWindow::load(QLineEdit *lineEdit_nome)
{


    QFile file("resources/dati.json");
    if (file.open(QIODevice::ReadOnly)) {
        QJsonDocument document = QJsonDocument::fromJson(file.readAll());
        QJsonObject dati = document.object();

        lineEdit_nome->setText(dati["nome"].toString());

        file.close();
        //qDebug() << "Dati caricati con successo.";
    }
}

