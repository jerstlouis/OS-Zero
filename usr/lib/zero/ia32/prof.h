#ifndef __ZERO_IA32_PROF_H__
#define __ZERO_IA32_PROF_H__

#include <stdint.h>

union _tickval {
    uint64_t u64;
    uint32_t u32v[2];
};

#define PROFDECLTICK(id)                                                \
    union _tickval __tv##id[2]
#define profclrtick(id)                                                 \
    (__tv##id[0].u64 = __tv##id[1].u64 = UINT64_C(0))
//    memset(&__tv##id, 0, sizeof(__tv##id))
#define profstarttick(id)                                               \
    _rdtsc(&__tv##id[0])
#define profstoptick(id)                                                \
    _rdtsc(&__tv##id[1])
#define proftickdiff(id)                                                \
    (__tv##id[1].u64 - __tv##id[0].u64)

/* read TSC (time stamp counter) */
#define _rdtsc(tp)                                                      \
    __asm__("rdtsc\n"                                                   \
            "movl %%eax, %0\n"                                          \
            "movl %%edx, %1\n"                                          \
            : "=m" ((tp)->u32v[0]), "=m" ((tp)->u32v[1])                \
            :                                                           \
            : "eax", "edx");

/* read performance monitor counter */
static __inline__ uint64_t
_rdpmc(union _tickval *tp, int id)
{
    __asm__("movl %0, %%ecx\n"                                          \
            "rdpmc\n"                                                   \
            "mov %%eax, %1\n"                                           \
            "mov %%edx, %2"
            : "=rm" (tp->u32v[0]), "=rm" (tp->u32v[1])
            : "rm" (id)
            : "eax", "edx");
    
    return (tp->u64);
}

#endif /* __ZERO_IA32_PROF_H__ */

