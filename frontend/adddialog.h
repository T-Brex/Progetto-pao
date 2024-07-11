#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QComboBox>
#include <QDialog>
#include <QLineEdit>

class AddDialog : public QDialog
{
    Q_OBJECT
protected:
    QLineEdit *lineEdit;
    QComboBox *sceltaTipo;
    QPushButton *newButton;
public:

    AddDialog(QWidget *parent = nullptr);
    QLineEdit* getLineEdit() const { return lineEdit; }
    QComboBox* getSceltaTipo() const { return sceltaTipo; }
    QPushButton* getNewButton() const { return newButton; }

};

#endif // ADDDIALOG_H
