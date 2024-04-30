QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    backend/json.cpp \
    frontend/adddialog.cpp \
    frontend/cartesianPlane.cpp \
    frontend/deletedialog.cpp \
    frontend/deletewarning.cpp \
    frontend/modifydialog.cpp \
    frontend/searchMenu.cpp \
    frontend/layoutswidget.cpp \
    frontend/menubar.cpp \
    frontend/sensorwindow.cpp \
    main.cpp \
    frontend/mainwindow.cpp \
    frontend/simulation.cpp \
    frontend/editor.cpp \
    frontend/sensorPanel.cpp \
    backend/sensors.cpp \
    frontend/simulationBar.cpp

HEADERS += \
    backend/json.h \
    frontend/adddialog.h \
    frontend/cartesianPlane.h \
    frontend/deletedialog.h \
    frontend/deletewarning.h \
    frontend/layoutswidget.h \
    frontend/mainwindow.h \
    frontend/modifydialog.h \
    frontend/searchMenu.h \
    frontend/menubar.h \
    frontend/sensorwindow.h \
    frontend/simulation.h \
    frontend/editor.h \
    frontend/sensorPanel.h \
    backend/sensors.h \
    frontend/simulationBar.h

RESOURCES = resources.qrc \




# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    dati.json


