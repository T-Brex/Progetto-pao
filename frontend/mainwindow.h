#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "frontend/sensorPanel.h"

#include "frontend/layoutswidget.h"
#include "frontend/menubar.h"
#include "sensorPanel.h"

#include <QMainWindow>
#include <QStackedWidget>

//#include "frontend/searchMenu.h"

#include <QStackedWidget>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{

    Q_OBJECT
private:

    LayoutsWidget* layoutsWidget;
    MenuBar *menuBar;
    Dialog *dialog;

public:
    MainWindow(QWidget *parent = nullptr);

    //MainWindow(QVector<Sensor*> s, QWidget *parent = nullptr);


    MainWindow(SearchMenu *menu, QWidget *parent=nullptr);//Eliminabile(?)
    MainWindow(const QVector<Sensor*>& s, QWidget *parent = nullptr);
    MainWindow(QVector<SensorPanel*> sp, QWidget *parent = nullptr);//Eliminabile(?)
    MainWindow(QVector<QWidget*> frame, QWidget *parent  = nullptr);//Eliminabile(?)
    //static bool sensoreEsiste(const QString& nome,const QString& fileName="C:/Users/bress/Desktop/progetti/File C/Progetto-pao/resources/dati.json");
    static QJsonArray leggiJson(const QString& fileName="C:/Users/bress/Desktop/progetti/File C/Progetto-pao/resources/dati.json");
    ~MainWindow();

public slots:
    void changeLayout();
    void nuovoSensore(const QString& nome, const QString& tipo,const QString& fileName="C:/Users/bress/Desktop/progetti/File C/Progetto-pao/resources/dati.json");
    void salvaSensori(const QVector<Sensor*>& nuoviSensori, const QString& fileName="C:/Users/bress/Desktop/progetti/File C/Progetto-pao/resources/dati.json");
    void eliminaSensore( const QString& sensoreDaRimuovere,const QString& fileName="C:/Users/bress/Desktop/progetti/File C/Progetto-pao/resources/dati.json");
    static QVector<Sensor*> caricaSensori(const QString& fileName="C:/Users/bress/Desktop/progetti/File C/Progetto-pao/resources/dati.json");
    void updateSensors();
private slots:
    //void showAddDialog();
    //void showDialog();

signals:
    void acceptNewAct();


};
#endif // MAINWINDOW_H
