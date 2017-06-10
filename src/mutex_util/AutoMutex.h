#ifndef AUTOMUTEX_H
#define AUTOMUTEX_H

#include "IMutex.h"
#include <stdexcept>

namespace Util {

    class AutoMutex
    {
    public:
        AutoMutex(IMutex &mutex) : mutex(&mutex){
            this->mutex->lock();
        }
        AutoMutex(IMutex *mutex) : mutex(mutex){
            if (NULL == mutex) {
                std::runtime_error("Mutex pointer is NULL");
            }
            this->mutex->lock();
        }
        ~AutoMutex() { mutex->unlock(); }
    private:
        IMutex *mutex;
    };

}

#endif // AUTOMUTEX_H
