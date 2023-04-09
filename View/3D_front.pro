QT       += core gui openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
include(gif/src/gifimage/qtgifimage.pri)

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../Controller/s21_controller.cc \
    ../Model/Parser/ObjectParser.cc \
    ../Model/Transformation/ObjectTransformation.cc \
    ../Model/s21_model.cc \
    main.cc \
    mainwindow.cc \
    widget.cc

HEADERS += \
    ../Controller/s21_controller.h \
    ../Model/Parser/ObjectParser.h \
    ../Model/Transformation/ObjectTransformation.h \
    ../Model/s21_model.h \
    mainwindow.h \
    widget.h

FORMS += \
    mainwindow.ui

#win32:RC_ICONS += 3d_icon.ico
macx: ICON = 3d_icon.icns

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images.qrc
