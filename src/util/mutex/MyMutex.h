#ifndef MYMUTEX_H
#define MYMUTEX_H

#include "IMutex.h"

#ifdef _WIN32
#  include <windows.h>
#else
#  include <pthread.h>
#endif

namespace Util {
    class MyMutex : public IMutex
    {
    public:
        MyMutex();
        ~MyMutex();
        virtual void lock();
        virtual void unlock();

    private:
#ifdef _WIN32
        HANDLE m_handle;
#else
        pthread_mutex_t m_mutex;
#endif
    };
}

#endif // MYMUTEX_H
