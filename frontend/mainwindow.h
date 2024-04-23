#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include "frontend/sensorPanel.h"

#include "frontend/layoutswidget.h"
#include "frontend/menubar.h"
#include <QMainWindow>



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

public:
    MainWindow(QWidget *parent = nullptr);
    MainWindow(const QVector<Sensor*>& s, QWidget *parent = nullptr);
    MainWindow(SearchMenu *menu, QWidget *parent=nullptr);//Eliminabile(?)    
    MainWindow(QVector<SensorPanel*> sp, QWidget *parent = nullptr);//Eliminabile(?)
    MainWindow(QVector<QWidget*> frame, QWidget *parent  = nullptr);//Eliminabile(?)

    ~MainWindow();

public slots:
    void changeLayout();


};
#endif // MAINWINDOW_H
