#ifndef LAYOUTSWIDGET_H
#define LAYOUTSWIDGET_H

#include "frontend/adddialog.h"
#include "frontend/deletedialog.h"
#include "frontend/deletewarning.h"
#include "frontend/modifydialog.h"
#include "frontend/sensorwindow.h"
#include "frontend/simulation.h"
#include <QStackedWidget>

class LayoutsWidget : public QStackedWidget
{
    Q_OBJECT
private:
    sensorWindow* sensWindow;
    Simulation *simuWindow;

    AddDialog *addDialog;
    DeleteDialog *deleteDialog;
    DeleteWarning *deleteAllWarning;
    DeleteWarning* deleteOneWarning;
    ModifyDialog* modifyDialog;
public:
    sensorWindow* getSensWindow() const { return sensWindow; }
    Simulation* getSimuWindow() const { return simuWindow; }
    AddDialog* getAddDialog() const { return addDialog; }
    DeleteDialog* getDeleteDialog() const { return deleteDialog; }
    DeleteWarning* getDeleteAllWarning() const { return deleteAllWarning; }
    DeleteWarning* getDeleteOneWarning() const { return deleteOneWarning; }
    ModifyDialog* getModifyDialog() const { return modifyDialog; }

    LayoutsWidget(QWidget * parent = nullptr);
    ~LayoutsWidget();

};

#endif
