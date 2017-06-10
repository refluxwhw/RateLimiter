#ifndef RL_TOKENBUCKET_H
#define RL_TOKENBUCKET_H

#include "IRateLimiter.h"
#include "Mutex.h"

using namespace Util;

class RL_TokenBucket : public IRateLimiter
{
public:
    RL_TokenBucket();
    ~RL_TokenBucket();

    virtual double aquire(int permits = 1);

    virtual bool try_aquire(int permits = 1);
    virtual bool try_aquire(int permits, int timeout_us);

    virtual double get_rate() const;
    virtual void set_rate(double rate);

    virtual double get_burst() const;
    virtual void set_burst(double burst);

private:
    void recalpermits();

private:
    double  _rate;
    double  _stored_permits;
    double  _max_stored_permits; // burst
    IMutex *_mutex;
    long long _last_time;
};

#endif // RL_TOKENBUCKET_H
