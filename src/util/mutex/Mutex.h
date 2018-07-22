#ifndef MUTEX_H
#define MUTEX_H

#include "IMutex.h"

namespace Util {

    class Mutex
    {
    public:
        static IMutex *create();
    };

}

#endif // MUTEX_H
