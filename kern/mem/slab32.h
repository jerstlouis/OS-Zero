#ifndef __MEM_SLAB32_H__
#define __MEM_SLAB32_H__

#include <zero/param.h>
#include <zero/mtx.h>
#include <zero/trix.h>
#include <kern/task.h>
#include <kern/mem/slab.h>

#define slabgetprev(hp, tab)                                            \
    (!(hp)                                                              \
     ? NULL                                                             \
     : (((hp)->link & 0x0000ffffL)                                      \
        ? ((struct slabhdr *)(tab) + ((hp)->link & 0x0000ffffL))        \
        : NULL))
#define slabgetnext(hp, tab)                                            \
    (!(hp)                                                              \
     ? NULL                                                             \
     : (((hp)->link & 0xffff0000L)                                      \
        ? ((struct slabhdr *)(tab) + (((hp)->link & 0xffff0000L) >> 16)) \
        : NULL))
#define slabclrprev(hp)                                                 \
    ((hp)->link &= 0xffff0000L)
#define slabclrnext(hp)                                                 \
    ((hp)->link &= 0x0000ffffL)
#define slabclrlink(hp)                                                 \
    ((hp)->link = 0L)
#define slabsetprev(hp, hdr, tab)                                       \
    (slabclrprev(hp), (hp)->link |= slabhdrnum(hdr, tab))
#define slabsetnext(hp, hdr, tab)                                       \
    (slabclrnext(hp), (hp)->link |= (slabhdrnum(hdr, tab) << 16))

#define slabnum(ptr)                                                    \
    ((uintptr_t)(ptr) >> SLABMINLOG2)
#define slabhdrnum(hdr, tab)                                            \
    (!(hdr) ? 0 : (uintptr_t)((hdr) - (struct slabhdr *)(tab)))
#define slabgetadr(hdr, tab)                                            \
    ((void *)(slabhdrnum(hdr, tab) << SLABMINLOG2))
#define slabgethdr(ptr, tab)                                            \
    (!(ptr) ? NULL : (struct slabhdr *)(tab) + slabnum(ptr))

void  slabinit(struct slabhdr **zone, struct slabhdr *hdrtab,
               unsigned long base, unsigned long size);
void *slaballoc(struct slabhdr **zone, struct slabhdr *hdrtab,
                unsigned long nb, unsigned long flg);
void  slabfree(struct slabhdr **zone, struct slabhdr *hdrtab, void *ptr);

#endif /* __MEM_SLAB32_H__ */

