QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    backend/json.cpp \
    backend/measurement.cpp \
    backend/sensors.cpp \
    backend/visitor.cpp \
    frontend/adddialog.cpp \
    frontend/cartesianPlane.cpp \
    frontend/deletedialog.cpp \
    frontend/legend.cpp \
    frontend/deletewarning.cpp \
    frontend/modifydialog.cpp \
    frontend/searchMenu.cpp \
    frontend/layoutswidget.cpp \
    frontend/menubar.cpp \
    frontend/sensorlayoutchooser.cpp \
    frontend/sensorvisibility.cpp \
    frontend/sensorwindow.cpp \
    main.cpp \
    frontend/mainwindow.cpp \
    frontend/simulation.cpp \
    frontend/sensorPanel.cpp \
    frontend/simulationBar.cpp \
    sensorconstructor.cpp

HEADERS += \
    backend/json.h \
    backend/measurement.h \
    backend/sensors.h \
    backend/visitor.h \
    frontend/adddialog.h \
    frontend/cartesianPlane.h \
    frontend/deletedialog.h \
    frontend/deletewarning.h \
    frontend/layoutswidget.h \
    frontend/legend.h \
    frontend/mainwindow.h \
    frontend/modifydialog.h \
    frontend/searchMenu.h \
    frontend/menubar.h \
    frontend/sensorlayoutchooser.h \
    frontend/sensorvisibility.h \
    frontend/sensorwindow.h \
    frontend/simulation.h \
    frontend/sensorPanel.h \
    frontend/simulationBar.h \
    sensorconstructor.h

RESOURCES = resources.qrc \




# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    dati.json


