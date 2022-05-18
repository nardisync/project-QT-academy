QT      += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG  += c++20

SOURCES += \
    Main.cpp \
    Mainwindow.cpp \
    Worker.cpp

HEADERS += \
    EnumsType.h \
    Mainwindow.h \
    Worker.h

FORMS   += \
    Mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
