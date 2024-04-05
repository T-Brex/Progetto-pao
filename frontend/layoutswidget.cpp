#include "layoutswidget.h"
#include "qpushbutton.h"

LayoutsWidget::LayoutsWidget(QWidget *parent):QStackedWidget(parent)
    //,layoutsWidget(new QStackedWidget),
{
    /*
    for(auto i=0;i<frame.size();i++){
        sensLayout->addWidget(frame[i]);
    }
    */

    QWidget* sensWidget=new QWidget;
    QGridLayout* sensLayout=new QGridLayout(sensWidget);
    QWidget* simuWidget=new QWidget;
    QHBoxLayout* simuLayout=new QHBoxLayout(simuWidget);


    //costruzione layout sensori
    sensLayout->addWidget(new QPushButton("Fottiti la granda"));
    this->addWidget(sensWidget);



    //costruzione layout simulazione
    simuLayout->addWidget(new QPushButton("SUCA"));
    this->addWidget(simuWidget);
}
LayoutsWidget::~LayoutsWidget(){};
