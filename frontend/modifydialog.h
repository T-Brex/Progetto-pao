#ifndef MODIFYDIALOG_H
#define MODIFYDIALOG_H

#include "adddialog.h"
#include "qlabel.h"

class ModifyDialog : public AddDialog
{
    Q_OBJECT
private:
    QString oldSensorName;
    QString oldSensorType;

    QWidget* parametriWidget;
    QGridLayout* parametriLayout;

    QWidget* misureWidget;
    QVBoxLayout* misureLayout;

    QWidget* minWidget;
    QVBoxLayout* minLayout;

    QWidget* maxWidget;
    QVBoxLayout* maxLayout;
public:
    QString getOldSensorName() const ;
    QString getOldSensorType() const ;
    void setOldSensorName(const QString &name);
    void setOldSensorType(const QString &type);
    QWidget* getParametriWidget() const;
    QGridLayout* getParametriLayout() const;
    QWidget* getMisureWidget() const;
    QVBoxLayout* getMisureLayout() const;
    QWidget* getMinWidget() const;
    QVBoxLayout* getMinLayout() const;
    QWidget* getMaxWidget() const;
    QVBoxLayout* getMaxLayout() const;
    //QVector<QWidget*>& getDatiWidget();
    //QVector<QHBoxLayout*>& getDatiLayout();
    //QVector<QLabel*>& getMisure();
    //QVector<QLineEdit*>& getMinimi();
    //QVector<QLineEdit*>& getMassimi();

    ModifyDialog(QWidget *parent);
};

#endif
