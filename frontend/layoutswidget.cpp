#include "layoutswidget.h"
#include "qpushbutton.h"
#include "searchMenu.h"

LayoutsWidget::LayoutsWidget(QWidget *parent):QStackedWidget(parent)
{
    QWidget* sensWidget=new QWidget;
    QGridLayout* sensLayout=new QGridLayout(sensWidget);
    QWidget* simuWidget=new QWidget;
    QHBoxLayout* simuLayout=new QHBoxLayout(simuWidget);

    //costruzione layout sensori
    simuLayout->addWidget(new QPushButton("SUCA"));
    this->addWidget(simuWidget);

    //costruzione layout simulazione
    sensLayout->addWidget(new QPushButton("Fottiti la granda"));
    this->addWidget(sensWidget);
}


LayoutsWidget::LayoutsWidget(QVector<QWidget*> frame,QWidget *parent):QStackedWidget(parent)
{
    QWidget* sensWidget=new QWidget;
    QGridLayout* sensLayout=new QGridLayout(sensWidget);
    QWidget* simuWidget=new QWidget;
    QHBoxLayout* simuLayout=new QHBoxLayout(simuWidget);
//suca

    //costruzione layout sensori
    for(auto i=0;i<frame.size();i++){
        sensLayout->addWidget(frame[i]);
    }
    this->addWidget(sensWidget);

    //costruzione layout simulazione
    simuLayout->addWidget(new QPushButton("SUCA"));
    this->addWidget(simuWidget);
}
LayoutsWidget::LayoutsWidget(QVector<Sensor*> s,QWidget *parent):QStackedWidget(parent)
{
    QWidget* sensWidget=new QWidget;
    QGridLayout* sensLayout=new QGridLayout(sensWidget);
    QWidget* simuWidget=new QWidget;
    QHBoxLayout* simuLayout=new QHBoxLayout(simuWidget);

    //costruzione layout sensori con trasformazione da Sensor a SensorPanel
    for(auto i=0;i<s.size();i++){
        sensLayout->addWidget(new SensorPanel(*s[i]));
    }
    this->addWidget(sensWidget);

    //costruzione layout simulazione
    simuLayout->addWidget(new QPushButton("SUCA"));
    this->addWidget(simuWidget);
}
LayoutsWidget::LayoutsWidget(QVector<SensorPanel*> sp,QWidget *parent):QStackedWidget(parent)
{
    QWidget* sensWidget=new QWidget;
    QGridLayout* sensLayout=new QGridLayout(sensWidget);
    QWidget* simuWidget=new QWidget;
    QHBoxLayout* simuLayout=new QHBoxLayout(simuWidget);
    SearchMenu *sm=new SearchMenu;

    //costruzione layout sensori
    sensLayout->addWidget(sm);
    for(auto i=0;i<sp.size();i++){
        sensLayout->addWidget(sp[i]);
    }
    this->addWidget(sensWidget);

    //costruzione layout simulazione
    simuLayout->addWidget(new QPushButton("SUCA"));
    this->addWidget(simuWidget);
}


LayoutsWidget::~LayoutsWidget(){};
