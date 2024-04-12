#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>
#include <QFile>
#include <QDebug>
#include <QPushButton>
#include <QLineEdit>
#include <QJsonDocument>
#include <QJsonObject>

class MenuBar : public QMenuBar
{
    Q_OBJECT

public:
    QMenuBar *menuBar;
    QMenu *fileMenu;

    //QLineEdit *lineEdit_nome;

    QAction *changeLayoutAct;
    QAction* newAct;
    QAction* loadAct;
    QAction* saveAct;
    QAction* deleteAct;

    MenuBar(QWidget* parent = nullptr);
    virtual ~MenuBar();
signals:
    void changeLayoutTrigger();
    void showAddDialog();
    void saveTrigger();
    void loadTrigger();
    void deleteTrigger();
};

#endif // MENUBAR_H
