#ifndef __POLL_H__
#define __POLL_H__

#if defined(_POSIX_SOURCE) && (_POSIX_C_SOURCE >= 200112L)

#include <sys/select.h>

struct pollfd {
    fd_set set;
};

typedef long nfds_t;

int poll(struct pollfd fds[], nfds_t nfds, int timeout);

#endif /* POSIX */

#endif /* __POLL_H__ */

