#ifndef SEARCHMENU_H
#define SEARCHMENU_H

#include "backend/sensors.h"
#include <QBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QLineEdit>


class SearchMenu: public QWidget {
    Q_OBJECT
private:
    QString *searchName;
    QVBoxLayout * layout;

    QWidget *foundSensorsWidget;
    QVBoxLayout *foundSensorsLayout;

    QLineEdit *lineEdit;
    QPushButton *addButton;

    QPushButton *deleteButton;
    QPushButton *deleteAllButton;
public:
    QString* getSearchName() const { return searchName; }
    QVBoxLayout* getLayout() const { return layout; }
    QWidget* getFoundSensorsWidget() const { return foundSensorsWidget; }
    QVBoxLayout* getFoundSensorsLayout() const { return foundSensorsLayout; }
    QLineEdit* getLineEdit() const { return lineEdit; }
    QPushButton* getAddButton() const { return addButton; }
    QPushButton* getDeleteButton() const { return deleteButton; }
    QPushButton* getDeleteAllButton() const { return deleteAllButton; }
    void aggiuntaSensori();
    void updateSensori();

    SearchMenu(QWidget* parent = nullptr);
signals:
    void showAddDialog();
    void showDeleteDialog();;
    void showDeleteAllDialog();
    void showModifyDialog(const Sensor* sensor);
};
#endif
