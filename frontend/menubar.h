#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>
class MenuBar : public QMenuBar
{
    Q_OBJECT

public:
    QMenuBar *menuBar;
    QMenu *fileMenu;
    QAction *changeLayoutAct;
    QAction* newAct;
    QAction* importAct;
    QAction* saveAct;

    //friend class MainWindow;
    MenuBar(QWidget* parent = nullptr);
    virtual ~MenuBar();
signals:
    void changeLayoutTrigger();



    /*
     * MenuBar(QWidget *parent = nullptr);
    QSize sizeHint() const override { return QMenuBar::sizeHint(); }
    QSize minimumSizeHint() const override { return QMenuBar::minimumSizeHint(); }*/
};

#endif // MENUBAR_H
