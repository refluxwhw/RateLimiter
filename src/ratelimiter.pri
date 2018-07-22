INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

SOURCES += \
    $$PWD/TokenBucket.cpp

HEADERS += \
    $$PWD/IRateLimiter.h \
    $$PWD/TokenBucket.h

include (util/util.pri)
