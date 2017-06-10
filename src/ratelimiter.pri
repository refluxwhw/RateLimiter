INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

SOURCES += \
    $$PWD/RateLimiter.cpp

HEADERS += \
    $$PWD/RateLimiter.h\
    $$PWD/ratelimiter_global.h \
    $$PWD/IRateLimiter.h

include (leaky_bucket/leaky_bucket.pri)
include (token_bucket/token_bucket.pri)
include (mutex_util/mutex.pri)
include (time_util/time.pri)
