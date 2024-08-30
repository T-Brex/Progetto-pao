#include "frontend/simulationBar.h"
#include "frontend/simBarVisitor.h"
#include "qlabel.h"
#include <QToolButton>
#include<QFrame>
#include <QColor>


SimBar::SimBar(QVector<Sensor*>& s, QWidget* parent)
    : QWidget(parent) {

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addStretch();
    int colorCounter = 0;
    int nButtons = 0;

    // Itera sui sensori e crea SimBarVisitor
    for (int i = 0; i < s.size(); ++i) {
        QFrame *panel = new QFrame(this);
        QHBoxLayout *panelLayout = new QHBoxLayout(panel);

        panel->setFrameStyle(QFrame::Box | QFrame::Plain);
        panel->setLineWidth(1);
        panel->setMidLineWidth(0);

        QWidget *labels = new QWidget(panel);
        QVBoxLayout *labelsLayout = new QVBoxLayout(labels);
        QLabel *name = new QLabel(s[i]->getName(), panel);
        labelsLayout->addWidget(name);




        SimBarVisitor* visitor = new SimBarVisitor(*panelLayout, nButtons, colorCounter);
        visitors.push_back(visitor);

        panelLayout->addWidget(labels);
        s[i]->accept(*visitor);//visitor aggiunge i bottoni direttamente in panelLayout

        connect(visitor, &SimBarVisitor::addDust, this, &SimBar::addDust);
        connect(visitor, &SimBarVisitor::addWind, this, &SimBar::addWind);
        connect(visitor, &SimBarVisitor::addHumidity, this, &SimBar::addHumidity);
        connect(visitor, &SimBarVisitor::addTermometer, this, &SimBar::addTermometer);
        connect(visitor, &SimBarVisitor::addAirQuality, this, &SimBar::addAirQuality);
        connect(visitor, &SimBarVisitor::remove, this, &SimBar::remove);
        connect(visitor, &SimBarVisitor::updateDust, this, &SimBar::updateDust);
        connect(visitor, &SimBarVisitor::updateWind, this, &SimBar::updateWind);
        connect(visitor, &SimBarVisitor::updateTermometer, this, &SimBar::updateTermometer);
        connect(visitor, &SimBarVisitor::updateHumidity, this, &SimBar::updateHumidity);
        connect(visitor, &SimBarVisitor::updateAirQuality, this, &SimBar::updateAirQuality);
        mainLayout->addWidget(panel);
    }




    nButtons = 0;
    mainLayout->addStretch();
}

SimBar::~SimBar() {
    for (auto visitor : visitors) {
        delete visitor;
    }
}
void SimBar::addDust(const Dust& s, int i, int n){
    emit addD( s, i, n);
}
void SimBar::addWind(const Wind& s, int i, int n){
    emit addW( s, i, n);
}
void SimBar::addTermometer(const Termometer& s, int i, int n){
    emit addT( s, i, n);
}
void SimBar::addAirQuality(const AirQuality& s, int i, int n){
    emit addA( s, i, n);
}
void SimBar::addHumidity(const Humidity& s, int i, int n){
    emit addH( s, i, n);
}
void SimBar::remove(int n){
    emit rem( n);
}
void SimBar::updateDust(const Dust &s, int i, int n){
    emit updateD(s,i,n);
}

void SimBar::updateWind(const Wind &s, int i, int n){
    emit updateW(s,i,n);
}

void SimBar::updateTermometer(const Termometer &s, int i, int n){
    emit updateT(s,i,n);
}

void SimBar::updateHumidity(const Humidity &s, int i, int n){
    emit updateH(s,i,n);
}

void SimBar::updateAirQuality(const AirQuality &s, int i, int n){
    emit updateA(s,i,n);
}

