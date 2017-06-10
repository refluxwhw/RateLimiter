#include "Time.h"

#ifdef _WIN32
#  include <windows.h>
#else
#  include <time.h>
#endif

namespace Util {

void Time::msDelay(long long ms)
{
#ifdef _WIN32
    Sleep(ms);
#else

#endif
}

void Time::usDelay(long long us)
{
#ifdef _WIN32
    long long ms = us / 1000;
    msDelay(ms);
    us %= 1000;
    LARGE_INTEGER freq;
    LARGE_INTEGER start;
    LARGE_INTEGER now;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    do {
        QueryPerformanceCounter(&now);
    } while ( ((double)(now.QuadPart - start.QuadPart) / (double)freq.QuadPart * 1000000.0) < us );
#endif

#endif
}

long long Time::getCurrentUs()
{

}

long long Time::getCurrentMs()
{

}

}
