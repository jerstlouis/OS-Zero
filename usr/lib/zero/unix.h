/*
 * Copyright (C) 2007-2008 Tuomo Petteri Venäläinen. All rights reserved.
 */

#ifndef __ZERO_UNIX_H__
#define __ZERO_UNIX_H__

#if 0
/* system feature macros. */
#if !defined(_ISOC9X_SOURCE)
#define _ISOC9X_SOURCE      1
#endif

#if !defined(_POSIX_SOURCE)
#define _POSIX_SOURCE       1
#endif
#if !defined(_POSIX_C_SOURCE)
#define _POSIX_C_SOURCE     199506L
#endif

#if !defined(_LARGEFILE_SOURCE)
#define _LARGEFILE_SOURCE   1
#endif
#if !defined(_FILE_OFFSET_BITS)
#define _FILE_OFFSET_BITS   64
#endif
#if !defined(_LARGE_FILES)
#define _LARGE_FILES        1
#endif
#if !defined(_LARGEFILE64_SOURCE)
#define _LARGEFILE64_SOURCE 1
#endif
#endif /* 0 */

#include <stdint.h>
#include <signal.h>

/* posix standard header. */
#include <unistd.h>

/* i/o headers. */
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define _SBRK_FAILED        ((void *)-1L)

#define _MMAP_DEV_ZERO      0 /* set mmap to use /dev/zero. */

/* some systems may need MAP_FILE with MAP_ANON. */
#ifndef MAP_FILE
#define MAP_FILE            0
#endif
#if !defined(MAP_FAILED)
#define MAP_FAILED          ((void *)-1L)
#endif
#if (defined(MMAP_DEV_ZERO) && MMAP_DEV_ZERO)
#define mapanon(fd, size)                    \
    mmap(NULL, size, PROT_READ | PROT_WRITE, \
         MAP_PRIVATE | MAP_FILE,             \
         fd,                                 \
         0)
#else
#define mapanon(fd, size)                                               \
    mmap(NULL,                                                          \
         size,                                                          \
         PROT_READ | PROT_WRITE,                                        \
         MAP_PRIVATE | MAP_ANON | MAP_FILE,                             \
         fd,                                                            \
         0)
#endif
#define unmapanon(ptr, size)                                            \
    munmap(ptr, size)

#define growheap(ofs) sbrk(ofs)

void * readfile(char *filename, size_t *sizeret);

#endif /* __ZERO_UNIX_H__ */

