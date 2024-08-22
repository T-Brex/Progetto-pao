#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QComboBox>
#include <QDialog>
#include <QLineEdit>
#include <QVBoxLayout>

class AddDialog : public QDialog
{
    Q_OBJECT
protected:
    QLineEdit *lineEdit;
    QComboBox *sceltaTipo;
    QPushButton *confirmButton;
    QVBoxLayout *layout;
public:

    AddDialog(QWidget *parent = nullptr);
    QLineEdit* getLineEdit() const { return lineEdit; }
    QComboBox* getSceltaTipo() const { return sceltaTipo; }
    QPushButton* getConfirmButton() const { return confirmButton; }
    QVBoxLayout *getLayout() { return layout; }

};

#endif
