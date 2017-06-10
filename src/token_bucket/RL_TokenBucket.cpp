#include "RL_TokenBucket.h"
#include "AutoMutex.h"

#define MAX(a,b) ((a)>=(b)?(a):(b))
#define MIN(a,b) ((a)<=(b)?(a):(b))

RL_TokenBucket::RL_TokenBucket()
    : _rate(0.0), _stored_permits(0.0), _max_stored_permits(0.0)
{
    _mutex = Mutex::create();
}

RL_TokenBucket::~RL_TokenBucket()
{
    delete _mutex;
}

double RL_TokenBucket::aquire(int permits)
{

}

bool RL_TokenBucket::try_aquire(int permits)
{

}

bool RL_TokenBucket::try_aquire(int permits, int timeout_us)
{

}

double RL_TokenBucket::get_rate() const
{
    AutoMutex am(_mutex);
    return _rate;
}

void RL_TokenBucket::set_rate(double rate)
{
    AutoMutex am(_mutex);
    recalpermits();
    _rate = rate;
}

double RL_TokenBucket::get_burst() const
{
    AutoMutex am(_mutex);
    return _max_stored_permits;
}

void RL_TokenBucket::set_burst(double burst)
{
    AutoMutex am(_mutex);
    _max_stored_permits = burst;
    _stored_permits = MIN(_stored_permits, _max_stored_permits);
}

void RL_TokenBucket::recalpermits()
{

}
