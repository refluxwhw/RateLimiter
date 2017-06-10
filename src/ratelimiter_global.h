#ifndef RATELIMITER_GLOBAL_H
#define RATELIMITER_GLOBAL_H

#ifdef _WIN32
#  if defined(RATELIMITER_LIBRARY)
#    define RATELIMITERSHARED_EXPORT __declspec(dllexport)
#  else
#    define RATELIMITERSHARED_EXPORT __declspec(dllimport)
#  endif
#else
#  if defined(RATELIMITER_LIBRARY)
#    define RATELIMITERSHARED_EXPORT __attribute__((visibility("default")))
#  else
#    define RATELIMITERSHARED_EXPORT __attribute__((visibility("default")))
#  endif
#endif

#endif // RATELIMITER_GLOBAL_H
