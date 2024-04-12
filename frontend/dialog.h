#ifndef DIALOG_H
#define DIALOG_H

#include "qcombobox.h"
#include <QDialog>
#include <QLineEdit>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    QLineEdit *lineEdit;
    QComboBox *sceltaTipo;
    QPushButton *newButton;

    Dialog(QWidget *parent = nullptr);
signals:
    void newTrigger();
};

#endif // DIALOG_H
