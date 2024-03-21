#include "frontend/infoPanel.h"
#include <QVBoxLayout>
InfoPanel::InfoPanel(Sensor * s, QWidget* parent)
    : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    name= new QLabel("suca");
    layout->addWidget(name);

    value = new QLabel("no");
    layout->addWidget(value);

}
