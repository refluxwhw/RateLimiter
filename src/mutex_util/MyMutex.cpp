#include "MyMutex.h"

namespace Util {
    MyMutex::MyMutex()
    {
#ifdef _WIN32
        m_handle = ::CreateMutex(NULL, FALSE, NULL);
#else
        pthread_mutex_init(&m_mutex, NULL);
#endif
    }

    MyMutex::~MyMutex()
    {
#ifdef _WIN32
        ::CloseHandle(m_handle);
#else
        pthread_mutex_destroy(&m_mutex);
#endif
    }

    void MyMutex::lock()
    {
#ifdef _WIN32
        WaitForSingleObject(m_handle, INFINITE);
#else
        pthread_mutex_lock(&m_mutex);
#endif
    }

    void MyMutex::unlock()
    {
#ifdef _WIN32
        ::ReleaseMutex(m_handle);
#else
        pthread_mutex_unlock(&m_mutex);
#endif
    }
}
