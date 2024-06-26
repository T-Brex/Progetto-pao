#ifndef DELETEWARNING_H
#define DELETEWARNING_H

#include <QDialog>

class DeleteWarning : public QDialog
{
    Q_OBJECT
public:
    DeleteWarning(QWidget *parent = nullptr);
    DeleteWarning(const QString&,QWidget *parent = nullptr);
signals:
    void confirmed();
};

#endif // DELETEWARNING_H
