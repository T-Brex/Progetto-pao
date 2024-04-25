#ifndef DELETEDIALOG_H
#define DELETEDIALOG_H

#include <QDialog>
#include <QBoxLayout>
#include <QComboBox>
#include <QPushButton>

class DeleteDialog : public QDialog
{
    Q_OBJECT
public:
    QComboBox* sceltaNome;
    QPushButton* deleteButton;
    QVBoxLayout *layout;
    DeleteDialog(QWidget *parent);
};

#endif // DELETEDIALOG_H
