#ifndef DELETEDIALOG_H
#define DELETEDIALOG_H

#include <QDialog>
#include <QBoxLayout>
#include <QComboBox>
#include <QPushButton>

class DeleteDialog : public QDialog
{
    Q_OBJECT
    QComboBox* sceltaNome;
    QPushButton* deleteButton;
    QVBoxLayout *layout;
public:

    DeleteDialog(QWidget *parent);
    QComboBox* getSceltaNome() const{
        return sceltaNome;
    }

    QPushButton* getDeleteButton() const {
        return deleteButton;
    }
};

#endif
