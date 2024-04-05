#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "frontend/sensorPanel.h"

#include "frontend/layoutswidget.h"
#include "frontend/menubar.h"
#include "sensorPanel.h"

#include <QMainWindow>
#include <QStackedWidget>

#include "frontend/searchMenu.h"

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

public:
    MainWindow(QWidget *parent = nullptr);
    //MainWindow(SearchMenu *menu, QWidget *parent=nullptr);
    MainWindow(QVector<Sensor*> s, QWidget *parent = nullptr);
    MainWindow(QVector<SensorPanel*> sp, QWidget *parent = nullptr);
    MainWindow(QVector<QWidget*> frame, QWidget *parent  = nullptr);
    ~MainWindow();

private slots:
    void changeLayout();


};
#endif // MAINWINDOW_H
