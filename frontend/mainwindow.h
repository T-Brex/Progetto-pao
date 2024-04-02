#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "sensorPanel.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    MainWindow(QVector<Sensor*> s, QWidget *parent = nullptr);
    MainWindow(QVector<SensorPanel*> sp, QWidget *parent = nullptr);
    MainWindow(QVector<QWidget*> sezioni, QWidget *parent = nullptr);
    ~MainWindow();
    QWidget* setSensorsPanel(QVector<SensorPanel*>);


};
#endif // MAINWINDOW_H
