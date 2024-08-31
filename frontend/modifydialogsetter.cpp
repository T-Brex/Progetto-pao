#include "modifydialogsetter.h"

modifyDialogSetter::modifyDialogSetter(QObject *parent)
    : Visitor{parent}
{}

modifyDialogSetter::modifyDialogSetter(ModifyDialog& md):modifyDialog(&md){}
void modifyDialogSetter::visit(Dust&){

}
void modifyDialogSetter::visit(Wind&){

}
void modifyDialogSetter::visit(Termometer&){

}
void modifyDialogSetter::visit(Humidity&){

}
void modifyDialogSetter::visit(AirQuality&){

}
