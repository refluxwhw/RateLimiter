INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

SOURCES += \
    $$PWD/RateLimiter.cpp \
    $$PWD/Time.cpp

HEADERS += \
    $$PWD/RateLimiter.h\
    $$PWD/ratelimiter_global.h \
    $$PWD/IRateLimiter.h \
    $$PWD/Time.h

include (leaky_bucket/leaky_bucket.pri)
include (token_bucket/token_bucket.pri)
include (mutex/mutex.pri)
