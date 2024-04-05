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

    MenuBar(QWidget* parent = nullptr);
    virtual ~MenuBar();
signals:
    void changeLayoutTrigger();
};

#endif // MENUBAR_H
