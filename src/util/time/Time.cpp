#include "Time.h"

#ifdef _WIN32
#  include <windows.h>
#else
#  include <time.h>
#endif

namespace Util {

long long Time::msDelay(long long ms)
{
#ifdef _WIN32
    Sleep(ms);
#else

#endif
    return ms;
}

long long Time::usDelay(long long us)
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
#else

#endif
    return us;
}

long long Time::getCurrentUs()
{
#ifdef _WIN32
// 从1601年1月1日0:0:0:000到1970年1月1日0:0:0:000的时间(单位100ns)
#define EPOCHFILETIME   (116444736000000000UL)
    FILETIME ft;
    LARGE_INTEGER li;
    long long tt = 0;
    GetSystemTimeAsFileTime(&ft);
    li.LowPart = ft.dwLowDateTime;
    li.HighPart = ft.dwHighDateTime;
    // 从1970年1月1日0:0:0:000到现在的微秒数(UTC时间)
    tt = (li.QuadPart - EPOCHFILETIME) /10;
    return tt;
#else
    timeval tv;
    gettimeofday(&tv, 0);
    return (int64_t)tv.tv_sec * 1000000 + (int64_t)tv.tv_usec;
#endif // _WIN32
    return 0;
}


}
