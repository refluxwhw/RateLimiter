#ifndef RATELIMITER_H
#define RATELIMITER_H

#include "ratelimiter_global.h"
#include "IRateLimiter.h"

class RATELIMITERSHARED_EXPORT RateLimiter
{
public:
    RateLimiter();
    virtual ~RateLimiter() {}

    static IRateLimiter* create();

};

#endif // RATELIMITER_H
