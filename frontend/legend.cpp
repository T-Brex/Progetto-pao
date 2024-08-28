#include "frontend/legend.h"

Legend::Legend(QWidget* parent):QWidget(parent){
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *title = new QLabel("Legenda :          (default)");
    layout->addWidget(title);
    QWidget *info = new QWidget(this);
    QHBoxLayout *infoLayout = new QHBoxLayout(info);
    QLabel *type = new QLabel("Tipo :\n- Pm10 \n- Pm25 \n- Umidità \n- Percentuale \n- Vento \n- Temperatura \n- Qualità");
    infoLayout->addWidget(type);
    QLabel *range = new QLabel("Range :\n[0,50] \n[0,35] \n[0,23] \n[0,10] \n[0,10] \n[-20,30] \n[-10,10]");
    infoLayout->addWidget(range);
    QLabel *unitMeasure = new QLabel("Unità di misura :\nµg/m3 \nµg/m3 \ng/m3 \n%/10 \n(km/h)/10 \nC° \nMedia");
    infoLayout->addWidget(unitMeasure);

    layout->addWidget(info);
}
