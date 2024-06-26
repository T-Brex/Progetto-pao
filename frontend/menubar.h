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

    QAction* openAct;
    QAction* loadAct;   
    QAction* saveAct;
    //QAction* deleteAct;

    MenuBar(QWidget* parent = nullptr);
    virtual ~MenuBar();
signals:
    void changeLayoutTrigger();
    void showOpenDialog();

    void saveTrigger();
    void loadTrigger();
    void showDeleteDialog();
};

#endif // MENUBAR_H
