#include "layoutswidget.h"
#include "qpushbutton.h"
#include "searchMenu.h"

LayoutsWidget::LayoutsWidget(QWidget *parent):QStackedWidget(parent),
    sensWindow(new QWidget),sensWindowLayout(new QHBoxLayout(sensWindow)),sensWidget(new QWidget),sensLayout(new QVBoxLayout(sensWidget)), simuWidget(new QWidget), simuLayout(new QHBoxLayout(simuWidget))
{
    /*
    QWidget* sensWindow=new QWidget;
    QHBoxLayout* sensWindowLayout=new QHBoxLayout(sensWindow);

    QWidget* sensWidget=new QWidget;
    QVBoxLayout* sensLayout=new QVBoxLayout(sensWidget);
    QWidget* simuWidget=new QWidget;
    QHBoxLayout* simuLayout=new QHBoxLayout(simuWidget);
    */
    SearchMenu *searchMenu=new SearchMenu;

    //costruzione layout sensori
    sensWindowLayout->addWidget(searchMenu);

    simuLayout->addWidget(new QPushButton("SUCA"));
    this->addWidget(simuWidget);

    //costruzione layout simulazione
    sensLayout->addWidget(new QPushButton("Fottiti la granda"));
    this->addWidget(sensWindow);
}


LayoutsWidget::LayoutsWidget(QVector<QWidget*> frame,QWidget *parent):QStackedWidget(parent),
sensWindow(new QWidget),sensWindowLayout(new QHBoxLayout(sensWindow)),sensWidget(new QWidget),sensLayout(new QVBoxLayout(sensWidget)), simuWidget(new QWidget), simuLayout(new QHBoxLayout(simuWidget))
{
    /*
    QWidget* sensWindow=new QWidget;
    QHBoxLayout* sensWindowLayout=new QHBoxLayout(sensWindow);

    QWidget* sensWidget=new QWidget;
    QVBoxLayout* sensLayout=new QVBoxLayout(sensWidget);
    QWidget* simuWidget=new QWidget;
    QHBoxLayout* simuLayout=new QHBoxLayout(simuWidget);
    */
    SearchMenu *searchMenu=new SearchMenu;

    //costruzione layout sensori
    searchMenu->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    sensWindowLayout->addWidget(searchMenu);
    sensWindowLayout->addWidget(sensWidget);


    for(auto i=0;i<frame.size();i++){
        sensLayout->addWidget(frame[i]);
    }
    this->addWidget(sensWindow);

    //costruzione layout simulazione
    simuLayout->addWidget(new QPushButton("SUCA"));
    this->addWidget(simuWidget);


}

LayoutsWidget::LayoutsWidget(QVector<Sensor*> s,QWidget *parent):QStackedWidget(parent),
sensWindow(new QWidget),sensWindowLayout(new QHBoxLayout(sensWindow)),sensWidget(new QWidget),sensLayout(new QVBoxLayout(sensWidget)), simuWidget(new QWidget), simuLayout(new QHBoxLayout(simuWidget))
{
    /*
    QWidget* sensWindow=new QWidget;
    QHBoxLayout* sensWindowLayout=new QHBoxLayout(sensWindow);

    QWidget* sensWidget=new QWidget;
    QVBoxLayout* sensLayout=new QVBoxLayout(sensWidget);
    QWidget* simuWidget=new QWidget;
    QHBoxLayout* simuLayout=new QHBoxLayout(simuWidget);
    */

    SearchMenu *searchMenu=new SearchMenu;

    //costruzione layout sensori
    searchMenu->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    sensWindowLayout->addWidget(searchMenu);
    sensWindowLayout->addWidget(sensWidget);





    //costruzione layout sensori con trasformazione da Sensor a SensorPanel    
    for(auto i=0;i<s.size();i++){
        sensLayout->addWidget(new SensorPanel(*s[i]));
    }
    this->addWidget(sensWindow);

    //costruzione layout simulazione
    simuLayout->addWidget(new QPushButton("SUCA"));
    this->addWidget(simuWidget);
}
LayoutsWidget::LayoutsWidget(QVector<SensorPanel*> sp,QWidget *parent):QStackedWidget(parent),
sensWindow(new QWidget),sensWindowLayout(new QHBoxLayout(sensWindow)),sensWidget(new QWidget),sensLayout(new QVBoxLayout(sensWidget)), simuWidget(new QWidget), simuLayout(new QHBoxLayout(simuWidget))
{
    QWidget* sensWindow=new QWidget;
    QHBoxLayout* sensWindowLayout=new QHBoxLayout(sensWindow);

    QWidget* sensWidget=new QWidget;
    QVBoxLayout* sensLayout=new QVBoxLayout(sensWidget);
    QWidget* simuWidget=new QWidget;
    QHBoxLayout* simuLayout=new QHBoxLayout(simuWidget);
    SearchMenu *searchMenu=new SearchMenu;

    //costruzione layout sensori
    searchMenu->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    sensWindowLayout->addWidget(searchMenu);
    sensWindowLayout->addWidget(sensWidget);


    for(auto i=0;i<sp.size();i++){
        sensLayout->addWidget(sp[i]);
    }
    this->addWidget(sensWindow);

    //costruzione layout simulazione
    simuLayout->addWidget(new QPushButton("SUCA"));
    this->addWidget(simuWidget);
}


LayoutsWidget::~LayoutsWidget(){};
