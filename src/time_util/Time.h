#ifndef TIME_H
#define TIME_H

namespace Util {
    class Time
    {
    public:
        static void msDelay(long long ms);
        static void usDelay(long long us);
        static long long getCurrentUs();
        static long long getCurrentMs();
    };
}

#endif // TIME_H
