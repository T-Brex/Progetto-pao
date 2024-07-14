#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>

class MenuBar : public QMenuBar
{
    Q_OBJECT
private:
    QMenuBar *menuBar;
    QMenu *fileMenu;

    QAction *changeLayoutAct;

    QAction* openAct;
    QAction* loadAct;
    QAction* saveAct;
public:
    QMenuBar* getMenuBar() const { return menuBar; }
    QMenu* getFileMenu() const { return fileMenu; }
    QAction* getChangeLayoutAct() const { return changeLayoutAct; }
    QAction* getOpenAction() const { return openAct; }
    QAction* getLoadAction() const { return loadAct; }
    QAction* getSaveAction() const { return saveAct; }

    MenuBar(QWidget* parent = nullptr);
    virtual ~MenuBar();
signals:
    void changeLayoutTrigger();
    void showOpenDialog();

    void saveTrigger();
    void loadTrigger();
    void showDeleteDialog();
};

#endif
