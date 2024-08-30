#include "frontend/simBarVisitor.h"
#include "qboxlayout.h"
#include "qpushbutton.h"
#include "qtoolbutton.h"
#include "qwidget.h"

SimBarVisitor::SimBarVisitor(QHBoxLayout &main, int &n, int &c)
    :  nButtons(n), colorCounter(c), mainLayout(main) {}


void SimBarVisitor::visit(Dust &sensor) {

    int currentNButtons = nButtons;
    int currentColorCounter = colorCounter;

    QWidget* layout = new QWidget();
    QVBoxLayout *buttonLayout = new QVBoxLayout(layout);

    QWidget *slot = new QWidget(layout);
    QHBoxLayout *slotLayout = new QHBoxLayout(slot);
    QToolButton *toggleButton = new QToolButton(layout);
    toggleButton->setCheckable(true);

    int hue = (currentColorCounter * 360 / 15) % 360; // Variazione dell'indice di tonalità
    colorCounter++;
    currentColorCounter++;

    toggleButton->setStyleSheet(QString("background-color: %1").arg(QColor::fromHsv(hue, 255, 255).name()));
    toggleButton->setText("pm10");

    connect(toggleButton, &QToolButton::clicked, this, [=](bool checked) {
        if (checked) {
            emit addDust(sensor, 0, currentNButtons);
        } else {
            emit remove(currentNButtons);
        }
    });

    slotLayout->addWidget(toggleButton);

    QPushButton *updateButton = new QPushButton("Update");
    slotLayout->addWidget(updateButton);
    connect(updateButton, &QPushButton::clicked, this, [=]() {
        if (toggleButton->isChecked()) {
            emit updateDust(sensor, 0, currentNButtons);
        }
    });
    currentNButtons++;
    nButtons++;
    buttonLayout->addWidget(slot);

    QWidget *slot2 = new QWidget(layout);
    QHBoxLayout *slot2Layout = new QHBoxLayout(slot2);
    QToolButton *toggleButton2 = new QToolButton(layout);
    toggleButton2->setCheckable(true);

    int hue2 = (currentColorCounter * 360 / 15) % 360;
    colorCounter++;
    currentColorCounter++;

    toggleButton2->setStyleSheet(QString("background-color: %1").arg(QColor::fromHsv(hue2, 255, 255).name()));
    toggleButton2->setText("pm25");

    connect(toggleButton2, &QToolButton::clicked, this, [=](bool checked) {
        if (checked) {
            emit addDust(sensor, 1, currentNButtons);
        } else {
            emit remove(currentNButtons);
        }
    });

    slot2Layout->addWidget(toggleButton2);

    QPushButton *updateButton2 = new QPushButton("Update");
    slot2Layout->addWidget(updateButton2);
    connect(updateButton2, &QPushButton::clicked, this, [=]() {
        if (toggleButton2->isChecked()) {
            emit updateDust(sensor, 1, currentNButtons);
        }
    });
    currentNButtons++;
    nButtons++;
    buttonLayout->addWidget(slot2);
    mainLayout.addWidget(layout);
}

void SimBarVisitor::visit(Humidity &sensor) {
    int currentNButtons = nButtons;
    int currentColorCounter = colorCounter;

    QWidget* layout = new QWidget();
    QVBoxLayout *buttonLayout = new QVBoxLayout(layout);

    QWidget *slot = new QWidget(layout);
    QHBoxLayout *slotLayout = new QHBoxLayout(slot);
    QToolButton *toggleButton = new QToolButton(layout);
    toggleButton->setCheckable(true);

    int hue = (currentColorCounter * 360 / 15) % 360;
    colorCounter++;
    currentColorCounter++;

    toggleButton->setStyleSheet(QString("background-color: %1").arg(QColor::fromHsv(hue, 255, 255).name()));
    toggleButton->setText("humidity");
    connect(toggleButton, &QToolButton::clicked, this, [=](bool checked) {
        if (checked) {
            emit addHumidity(sensor, 0, currentNButtons);
        } else {
            emit remove(currentNButtons);
        }
    });

    slotLayout->addWidget(toggleButton);

    QPushButton *updateButton = new QPushButton("Update");
    slotLayout->addWidget(updateButton);
    connect(updateButton, &QPushButton::clicked, this, [=]() {
        if (toggleButton->isChecked()) {
            emit updateHumidity(sensor, 0, currentNButtons);
        }
    });
    currentNButtons++;
    nButtons++;
    buttonLayout->addWidget(slot);

    QWidget *slot2 = new QWidget(layout);
    QHBoxLayout *slot2Layout = new QHBoxLayout(slot2);
    QToolButton *toggleButton2 = new QToolButton(layout);
    toggleButton2->setCheckable(true);

    int hue2 = (currentColorCounter * 360 / 15) % 360;
    colorCounter++;
    currentColorCounter++;

    toggleButton2->setStyleSheet(QString("background-color: %1").arg(QColor::fromHsv(hue2, 255, 255).name()));
    toggleButton2->setText("percentage");

    connect(toggleButton2, &QToolButton::clicked, this, [=](bool checked) {
        if (checked) {
            emit addHumidity(sensor, 1, currentNButtons);
        } else {
            emit remove(currentNButtons);
        }
    });

    slot2Layout->addWidget(toggleButton2);

    QPushButton *updateButton2 = new QPushButton("Update");
    slot2Layout->addWidget(updateButton2);
    connect(updateButton2, &QPushButton::clicked, this, [=]() {
        if (toggleButton2->isChecked()) {
            emit updateHumidity(sensor, 1, currentNButtons);
        }
    });
    currentNButtons++;
    nButtons++;
    buttonLayout->addWidget(slot2);
    mainLayout.addWidget(layout);
}

void SimBarVisitor::visit(Wind &sensor) {
    int currentNButtons = nButtons;
    int currentColorCounter = colorCounter;

    QWidget* layout = new QWidget();
    QVBoxLayout *buttonLayout = new QVBoxLayout(layout);

    QWidget *slot = new QWidget(layout);
    QHBoxLayout *slotLayout = new QHBoxLayout(slot);
    QToolButton *toggleButton = new QToolButton(layout);
    toggleButton->setCheckable(true);

    int hue = (currentColorCounter * 360 / 15) % 360;
    colorCounter++;
    currentColorCounter++;

    toggleButton->setStyleSheet(QString("background-color: %1").arg(QColor::fromHsv(hue, 255, 255).name()));
    toggleButton->setText("wind");
    connect(toggleButton, &QToolButton::clicked, this, [=](bool checked) {
        if (checked) {
            emit addWind(sensor, 0, currentNButtons);
        } else {
            emit remove(currentNButtons);
        }
    });

    slotLayout->addWidget(toggleButton);

    QPushButton *updateButton = new QPushButton("Update");
    slotLayout->addWidget(updateButton);
    connect(updateButton, &QPushButton::clicked, this, [=]() {
        if (toggleButton->isChecked()) {
            emit updateWind(sensor, 0, currentNButtons);
        }
    });
    currentNButtons++;
    nButtons++;
    buttonLayout->addWidget(slot);
    mainLayout.addWidget(layout);
}

void SimBarVisitor::visit(Termometer &sensor) {
    int currentNButtons = nButtons;
    int currentColorCounter = colorCounter;

    QWidget* layout = new QWidget();
    QVBoxLayout *buttonLayout = new QVBoxLayout(layout);

    QWidget *slot = new QWidget(layout);
    QHBoxLayout *slotLayout = new QHBoxLayout(slot);
    QToolButton *toggleButton = new QToolButton(layout);
    toggleButton->setCheckable(true);

    int hue = (currentColorCounter * 360 / 15) % 360;
    colorCounter++;
    currentColorCounter++;

    toggleButton->setStyleSheet(QString("background-color: %1").arg(QColor::fromHsv(hue, 255, 255).name()));
    toggleButton->setText("temperature");
    connect(toggleButton, &QToolButton::clicked, this, [=](bool checked) {
        if (checked) {
            emit addTermometer(sensor, 0, currentNButtons);
        } else {
            emit remove(currentNButtons);
        }
    });

    slotLayout->addWidget(toggleButton);

    QPushButton *updateButton = new QPushButton("Update");
    slotLayout->addWidget(updateButton);
    connect(updateButton, &QPushButton::clicked, this, [=]() {
        if (toggleButton->isChecked()) {
            emit updateTermometer(sensor, 0, currentNButtons);
        }
    });
    currentNButtons++;
    nButtons++;
    buttonLayout->addWidget(slot);
    mainLayout.addWidget(layout);
}

void SimBarVisitor::visit(AirQuality &sensor) {
    int currentNButtons = nButtons;
    int currentColorCounter = colorCounter;

    QWidget* layout = new QWidget();
    QVBoxLayout *buttonLayout = new QVBoxLayout(layout);

    QWidget *slot = new QWidget(layout);
    QHBoxLayout *slotLayout = new QHBoxLayout(slot);
    QToolButton *toggleButton = new QToolButton(layout);
    toggleButton->setCheckable(true);

    int hue = (currentColorCounter * 360 / 15) % 360;
    colorCounter++;
    currentColorCounter++;

    toggleButton->setStyleSheet(QString("background-color: %1").arg(QColor::fromHsv(hue, 255, 255).name()));
    toggleButton->setText("quality");
    connect(toggleButton, &QToolButton::clicked, this, [=](bool checked) {
        if (checked) {
            emit addAirQuality(sensor, 0, currentNButtons);
        } else {
            emit remove(currentNButtons);
        }
    });

    slotLayout->addWidget(toggleButton);

    QPushButton *updateButton = new QPushButton("Update");
    slotLayout->addWidget(updateButton);
    connect(updateButton, &QPushButton::clicked, this, [=]() {
        if (toggleButton->isChecked()) {
            emit updateAirQuality(sensor, 0, currentNButtons);
        }
    });
    currentNButtons++;
    nButtons++;
    buttonLayout->addWidget(slot);
    mainLayout.addWidget(layout);
}

    QWidget* SimBarVisitor::getCreatedSlot() const { return 0; }


