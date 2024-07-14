#ifndef MAINWINDOW_H
#define MAINWINDOW_H



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



    ~MainWindow();

public slots:
    void changeLayout();


};
#endif
