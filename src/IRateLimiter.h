#ifndef IRATELIMITER_H
#define IRATELIMITER_H

class IRateLimiter
{
public:
    virtual ~IRateLimiter() {}

    virtual double aquire(int permits = 1) = 0;

    virtual bool try_aquire(int permits = 1) = 0;
    virtual bool try_aquire(int permits, int timeout_us) = 0;

    virtual double get_rate() const = 0;
    virtual void set_rate(double rate) = 0;

    virtual double get_burst() const = 0;
    virtual void set_burst(double rate) = 0;
};

#endif // IRATELIMITER_H
