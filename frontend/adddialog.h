#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QComboBox>
#include <QDialog>
#include <QLineEdit>

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    QLineEdit *lineEdit;
    QComboBox *sceltaTipo;
    QPushButton *newButton;
    AddDialog(QWidget *parent = nullptr);

};

#endif // ADDDIALOG_H
