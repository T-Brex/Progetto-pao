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
    QAction* loadAct;
    QAction* deleteAct;

    MenuBar(QWidget* parent = nullptr);
    virtual ~MenuBar();
signals:
    void changeLayoutTrigger();
    void showAddDialog();
    void loadTrigger();
    void showDeleteDialog();
};

#endif // MENUBAR_H
