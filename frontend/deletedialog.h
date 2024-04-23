#ifndef DELETEDIALOG_H
#define DELETEDIALOG_H

#include "qboxlayout.h"
#include "qcombobox.h"
#include "qpushbutton.h"
#include <QDialog>

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
