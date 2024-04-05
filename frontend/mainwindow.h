#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "frontend/layoutswidget.h"
#include "frontend/menubar.h"
#include "sensorPanel.h"
#include <QMainWindow>
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

    QWidget *window;
    QLayout* mainLayout;
    LayoutsWidget* layoutsWidget;
    MenuBar *menuBar;





public:
    //friend class MenuBar;
    MainWindow(QWidget *parent = nullptr);
    MainWindow(QVector<Sensor*> s, QWidget *parent = nullptr);
    MainWindow(QVector<SensorPanel*> sp, QWidget *parent = nullptr);
    MainWindow(QVector<QWidget*> frame, QWidget *parent  = nullptr);
    ~MainWindow();

public slots:
    void changeLayout();


};
#endif // MAINWINDOW_H
