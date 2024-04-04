#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "qmenubar.h"
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
    class MenuBar;

    QWidget *window;
    QLayout* mainLayout;


    QWidget *sensWidget;
    QGridLayout *sensLayout;
    QWidget *simuWidget;
    QHBoxLayout *simuLayout;
    static QStackedWidget *layoutsWidget;
    MenuBar *menuBar;





public:

    MainWindow(QWidget *parent = nullptr);
    MainWindow(QVector<Sensor*> s, QWidget *parent = nullptr);
    MainWindow(QVector<SensorPanel*> sp, QWidget *parent = nullptr);
    MainWindow(QVector<QWidget*> frame, QWidget *parent  = nullptr);
    void createMenuBar();

    ~MainWindow();



};
#endif // MAINWINDOW_H
