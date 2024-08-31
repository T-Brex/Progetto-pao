QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    backend/deepsensorgetter.cpp \
    backend/json.cpp \
    backend/measurement.cpp \
    backend/measurementsaver.cpp \
    backend/measurementsetter.cpp \
    backend/sensorgetter.cpp \
    backend/sensors.cpp \
    backend/visitor.cpp \
    backend/dustSensor.cpp \
    backend/humiditySensor.cpp \
    backend/windSensor.cpp \
    backend/termometerSensor.cpp \
    backend/airQualitySensor.cpp \
    frontend/adddialog.cpp \
    frontend/cartesianPlane.cpp \
    frontend/deletedialog.cpp \
    frontend/legend.cpp \
    frontend/deletewarning.cpp \
    frontend/modifydialog.cpp \
    frontend/modifydialogsetter.cpp \
    frontend/searchMenu.cpp \
    frontend/layoutswidget.cpp \
    frontend/menubar.cpp \
    frontend/sensorlayoutchooser.cpp \
    frontend/sensorwindow.cpp \
    frontend/simBarVisitor.cpp \
    main.cpp \
    frontend/mainwindow.cpp \
    frontend/simulation.cpp \
    frontend/sensorPanel.cpp \
    frontend/simulationBar.cpp

HEADERS += \
    backend/deepsensorgetter.h \
    backend/json.h \
    backend/measurement.h \
    backend/measurementsaver.h \
    backend/measurementsetter.h \
    backend/sensorgetter.h \
    backend/sensors.h \
    backend/visitor.h \
    backend/dustSensor.h \
    backend/humiditySensor.h \
    backend/windSensor.h \
    backend/termometerSensor.h \
    backend/airQualitySensor.h \
    frontend/adddialog.h \
    frontend/cartesianPlane.h \
    frontend/deletedialog.h \
    frontend/deletewarning.h \
    frontend/layoutswidget.h \
    frontend/legend.h \
    frontend/mainwindow.h \
    frontend/modifydialog.h \
    frontend/modifydialogsetter.h \
    frontend/searchMenu.h \
    frontend/menubar.h \
    frontend/sensorlayoutchooser.h \
    frontend/sensorwindow.h \
    frontend/simBarVisitor.h \
    frontend/simulation.h \
    frontend/sensorPanel.h \
    frontend/simulationBar.h

RESOURCES = resources.qrc \




# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    dati.json


