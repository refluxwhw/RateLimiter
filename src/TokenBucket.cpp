#include "TokenBucket.h"
#include "mutex/AutoMutex.h"
#include "time/Time.h"

#define MAX(a,b) ((a)>=(b)?(a):(b))
#define MIN(a,b) ((a)<=(b)?(a):(b))

TokenBucket::TokenBucket()
    : _rate(0.0), _stored_permits(0.0), _max_stored_permits(0.0)
{
    _mutex = Mutex::create();
}

TokenBucket::~TokenBucket()
{
    delete _mutex;
}

double TokenBucket::aquire(int permits)
{
    _mutex->lock();
    _recalpermits();
    if (_stored_permits >= permits) {
        _stored_permits -= permits;
        _mutex->unlock();
        return 0.0;
    }

    double us = (permits - _stored_permits) / _rate;
    _mutex->unlock();
    return  Util::Time::usDelay((long long)us) + aquire(permits);
}

bool TokenBucket::try_aquire(int permits)
{
    Util::AutoMutex am(_mutex);
    _recalpermits();
    if (_stored_permits >= permits) {
        _stored_permits -= permits;
        return true;
    }

    return false;
}

bool TokenBucket::try_aquire(int permits, int timeout_us)
{
    _mutex->lock();
    _recalpermits();
    if (_stored_permits >= permits) {
        _stored_permits -= permits;
        _mutex->unlock();
        return true;
    }

    double us = (permits - _stored_permits) / _rate;
    if (timeout_us  >= us) {
        _mutex->unlock();
        return try_aquire(permits, timeout_us - Util::Time::usDelay(us));
    }

    _mutex->unlock();
    return false;
}

double TokenBucket::get_rate() const
{
    Util::AutoMutex am(_mutex);
    return _rate;
}

void TokenBucket::set_rate(double rate)
{
    Util::AutoMutex am(_mutex);
    _recalpermits();
    _rate = rate / 1000000.0;
}

double TokenBucket::get_burst() const
{
    Util::AutoMutex am(_mutex);
    return _max_stored_permits;
}

void TokenBucket::set_burst(double burst)
{
    Util::AutoMutex am(_mutex);
    _max_stored_permits = burst;
    if (_stored_permits > _max_stored_permits) {
        _stored_permits = _max_stored_permits;
    }
}

void TokenBucket::_recalpermits()
{
    long long now = Util::Time::getCurrentUs();

    if (now < _last_time) {
        _last_time = now;
    }

    _stored_permits += (now - _last_time) * _rate;
    if (_stored_permits > _max_stored_permits) {
        _stored_permits = _max_stored_permits;
    }

    _last_time = now;
}
