INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

QT += network

SOURCES += \
    $$PWD/main.cpp \
    $$PWD/mainwindow.cpp \
    $$PWD/NetworkThread.cpp

FORMS += \
    $$PWD/mainwindow.ui

HEADERS += \
    $$PWD/mainwindow.h \
    $$PWD/NetworkThread.h

