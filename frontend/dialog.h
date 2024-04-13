#ifndef DIALOG_H
#define DIALOG_H

#include "backend/sensors.h"
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
    static Sensor* costruttore(const QString& nome, const QString& tipo);
signals:
    void newTrigger();
};

#endif // DIALOG_H
