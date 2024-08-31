#ifndef MODIFYDIALOGSETTER_H
#define MODIFYDIALOGSETTER_H

#include "frontend/modifydialog.h"
#include <backend/visitor.h>

class modifyDialogSetter : public Visitor
{
private:
    ModifyDialog *modifyDialog;
public:
    explicit modifyDialogSetter(QObject *parent = nullptr);
    modifyDialogSetter(ModifyDialog&);
    void visit(Dust&);
    void visit(Wind&);
    void visit(Termometer&);
    void visit(Humidity&);
    void visit(AirQuality&);
};
#endif // MODIFYDIALOGSETTER_H
