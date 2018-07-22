#ifndef TOKENBUCKET_H
#define TOKENBUCKET_H

#include "IRateLimiter.h"
#include "mutex/Mutex.h"

using namespace Util;


/**
 * @brief The RL_TokenBucket class
 *
 * 令牌桶算法控制速率：
 * 实现方式：单线程，开始时记录投放令牌时间，令牌数初始化为0，然后在要获取令牌的
 *      时候，根据速率和上次投放令牌的时间差更新当前应该有的令牌数，然后判断令牌数
 *      量是否足够，如果足够，获得令牌，如果不足，计算应该等待的时间，然后线程睡眠
 *      到计算的时间后再次获取令牌。如果睡眠过程中有其他线程触发修改速率的操作，应
 *      该能唤醒该线程并且重新获取令牌。
 */
class TokenBucket : public IRateLimiter
{
public:
    TokenBucket();
    ~TokenBucket();

    virtual double aquire(int permits = 1);

    virtual bool try_aquire(int permits = 1);
    virtual bool try_aquire(int permits, int timeout_us);

    virtual double get_rate() const;
    virtual void set_rate(double rate);

    virtual double get_burst() const;
    virtual void set_burst(double burst);

private:
    void _recalpermits();

private:
    double _rate;               // 生成令牌的速率： 个/微秒
    double _stored_permits;
    double _max_stored_permits; // burst
    IMutex *_mutex;
    long long _last_time;
};

#endif // TOKENBUCKET_H
