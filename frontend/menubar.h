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

    QLineEdit *lineEdit_nome;


    //QPushButton *saveButton = new QPushButton("Salva", this);
    //QPushButton *loadButton = new QPushButton("Carica", this);





    QAction *changeLayoutAct;
    QAction* newAct;
    QAction* loadAct;
    QAction* saveAct;

    MenuBar(QWidget* parent = nullptr);
    virtual ~MenuBar();
signals:
    void changeLayoutTrigger();
    void saveTrigger();
    void loadTrigger();
};

#endif // MENUBAR_H
