QT      += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG  += c++20

SOURCES += \
    Main.cpp \
    MainWindow.cpp \
    Worker.cpp \
    sorting.cpp

HEADERS += \
    ConstStringDefinition.h \
    EnumsType.h \
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
