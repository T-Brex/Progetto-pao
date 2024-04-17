#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "backend/json.h"
#include "frontend/adddialog.h"
#include "frontend/deletedialog.h"
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
    //AddDialog *addDialog;
    //DeleteDialog *deleteDialog;


public:
    MainWindow(QWidget *parent = nullptr);
    MainWindow(const QVector<Sensor*>& s, QWidget *parent = nullptr);
    MainWindow(SearchMenu *menu, QWidget *parent=nullptr);//Eliminabile(?)    
    MainWindow(QVector<SensorPanel*> sp, QWidget *parent = nullptr);//Eliminabile(?)
    MainWindow(QVector<QWidget*> frame, QWidget *parent  = nullptr);//Eliminabile(?)
    //static bool sensoreEsiste(const QString& nome,const QString& fileName="C:/Users/bress/Desktop/progetti/File C/Progetto-pao/resources/dati.json");

    ~MainWindow();

public slots:
    void changeLayout();
    void updateSensors();





signals:
    void acceptNewAct();


};
#endif // MAINWINDOW_H
