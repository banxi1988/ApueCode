#include "apue.h"
#include <sys/time.h>

struct timespec timeval_to_timespec(struct timeval tv) {
  struct timespec ts;
  ts.tv_sec = tv.tv_sec;
  ts.tv_nsec = tv.tv_usec * 1000;
  return ts;
}


struct timeval timespec_to_timeval(struct timespec ts) {
  struct timeval tv;
  tv.tv_sec = ts.tv_sec;
  tv.tv_usec = (int)ts.tv_nsec / 1000;
  return tv;
}

#ifdef __APPLE__
int futimens(int fd, const struct timespec times[2]){
    struct timeval timevals[2];
    timevals[0] = timespec_to_timeval(times[0]);
    timevals[1] = timespec_to_timeval(times[1]);
    return futimes(fd,timevals);
}
#endif
