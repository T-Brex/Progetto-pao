#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include "qcombobox.h"
#include "qmessagebox.h"
#include <QDialog>
#include <QLineEdit>

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    QLineEdit *lineEdit;
    QComboBox *sceltaTipo;
    QPushButton *newButton;
    QMessageBox emptyName;
    QMessageBox existingName;

    AddDialog(QWidget *parent = nullptr);

signals:
    void newTrigger();
};

#endif // ADDDIALOG_H
