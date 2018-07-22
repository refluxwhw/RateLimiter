#ifndef TIME_H
#define TIME_H

namespace Util {
    class Time
    {
    public:
        static long long msDelay(long long ms);
        static long long usDelay(long long us);
        static long long getCurrentUs();
    };
}

#endif // TIME_H
