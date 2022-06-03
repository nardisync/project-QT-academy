QT      += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG  += c++20
CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT

SOURCES += \
    Main.cpp \
    MainWindow.cpp \
    Worker.cpp \
    sorting.cpp

HEADERS += \
    ConstStringDefinition.h \
    EnumsType.h \
    GenericWorker.h \
    MainWindow.h \
    Worker.h \
    GenericTask.h \
    sorting.h

FORMS   += \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    stylesheet.qss

RC_ICONS = images/ico/academy.ico

