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
private:
    QWidget *window;
    QHBoxLayout *layout;

public:
    MainWindow(QWidget *parent = nullptr);
    MainWindow(QVector<Sensor*>, QWidget *parent = nullptr);
    MainWindow(QVector<SensorPanel*>, QWidget *parent = nullptr);
    MainWindow(QVector<QWidget*>, QWidget *parent  = nullptr);
    ~MainWindow();
    QWidget* setSensorsPanel(QVector<SensorPanel*>);


};
#endif // MAINWINDOW_H
