#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>
#include <QWidget>

class MenuBar : public QMenuBar
{
private:
    QMenuBar *menuBar;
    QMenu *fileMenu;
    QAction* simulazioneAct;
    QAction *sensoriAct;
    QAction* newAct;
    QAction* importAct;
    QAction* saveAct;
public:
    MenuBar(QWidget* parent = 0);
};

#endif // MENUBAR_H
