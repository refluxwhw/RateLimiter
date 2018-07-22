#include "Mutex.h"
#include "MyMutex.h"

namespace Util {
    IMutex *Mutex::create()
    {
        return new MyMutex();
    }
}
