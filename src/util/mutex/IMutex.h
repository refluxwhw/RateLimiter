#ifndef IMUTEX_H
#define IMUTEX_H

namespace Util {

    class IMutex
    {
    public:
        virtual ~IMutex(){}
        virtual void lock() = 0;
        virtual void unlock() = 0;
    };

}

#endif // IMUTEX_H
