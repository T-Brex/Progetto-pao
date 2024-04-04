#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "frontend/sensorPanel.h"
#include <QMainWindow>
#include "frontend/searchMenu.h"
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
    MainWindow(SearchMenu *menu, QWidget *parent=nullptr);
    MainWindow(QVector<Sensor*> s, QWidget *parent = nullptr);
    MainWindow(QVector<SensorPanel*> sp, QWidget *parent = nullptr);
    MainWindow(QVector<QWidget*> frame, QWidget *parent  = nullptr);
    ~MainWindow();



};
#endif // MAINWINDOW_H
