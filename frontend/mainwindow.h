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
    QGridLayout *sensLayout;
    QHBoxLayout *simuLayout;

    QMenuBar *menuBar;
    QMenu *fileMenu;
    QAction* simulazioneAct;
    QAction *sensoriAct;
    QAction* newAct;
    QAction* importAct;
    QAction* saveAct;


public:
    MainWindow(QWidget *parent = nullptr);
    MainWindow(QVector<Sensor*> s, QWidget *parent = nullptr);
    MainWindow(QVector<SensorPanel*> sp, QWidget *parent = nullptr);
    MainWindow(QVector<QWidget*> frame, QWidget *parent  = nullptr);

    ~MainWindow();



};
#endif // MAINWINDOW_H
