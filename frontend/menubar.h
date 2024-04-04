#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>
#include <QWidget>

class MenuBar : public QMenuBar
{
public:
    QMenuBar *menuBar;
    QMenu *fileMenu;
    QAction* simulazioneAct;
    QAction *sensoriAct;
    QAction* newAct;
    QAction* importAct;
    QAction* saveAct;

    friend class MainWindow;
    MenuBar();
};

#endif // MENUBAR_H
