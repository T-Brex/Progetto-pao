#include "frontend/simulationBar.h"
#include "qlabel.h"
#include <QToolButton>
#include<QFrame>
#include <QColor>

int SimBar::nButtons = 0;
SimBar::SimBar(const QVector<Sensor *> &s, QWidget* parent) : QWidget(parent) {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addStretch();
    int hue,colorCounter=0;

    for (int i = 0; i < s.size(); ++i) {
        QFrame *panel = new QFrame(this);
        QHBoxLayout *panelLayout = new QHBoxLayout(panel);

        panel->setFrameStyle(QFrame::Box | QFrame::Plain);
        panel->setLineWidth(1);
        panel->setMidLineWidth(0);

        QWidget *labels = new QWidget(panel);
        QVBoxLayout *labelsLayout = new QVBoxLayout(labels);
        QLabel *name = new QLabel(s[i]->getName(), panel);
        QLabel *type = new QLabel(s[i]->getType(), panel);
        labelsLayout->addWidget(name);
        labelsLayout->addWidget(type);

        QWidget *buttons = new QWidget(panel);
        QVBoxLayout *buttonLayout = new QVBoxLayout(buttons);

        for(unsigned int j = 0; j < s[i]->getValue().size(); j++){
            int n = nButtons;
            QWidget *slot = new QWidget(buttons);
            QHBoxLayout *slotLayout = new QHBoxLayout(slot);
            QToolButton *toggleButton = new QToolButton(panel);
            toggleButton->setText("Toggle Button");
            toggleButton->setCheckable(true);


            hue = (colorCounter * 360 / 15) % 360; // Variazione dell'indice di tonalità
            colorCounter++;

            toggleButton->setStyleSheet(QString("background-color: %1").arg(QColor::fromHsv(hue, 255, 255).name()));
            toggleButton->setText(s[i]->getNameValues()[j]);

            connect(toggleButton, &QToolButton::clicked, this,[=](bool checked) {
                if(checked){
                    emit add(s[i], j, n);
                } else {
                    emit remove(n);
                }
            });
            nButtons++;
            slotLayout->addWidget(toggleButton);

            QPushButton *updateButton = new QPushButton("Update");
            slotLayout->addWidget(updateButton);
            connect(updateButton, &QPushButton::clicked,this, [=](){
                if(toggleButton->isChecked())
                    emit updatePlane(s[i], j, n);
            });
            buttonLayout->addWidget(slot);

        }

        panelLayout->addWidget(labels);
        panelLayout->addWidget(buttons);
        mainLayout->addWidget(panel);



    }
    nButtons = 0;
    mainLayout->addStretch();
}

//SimBar::~SimBar() {

//}
