#include <stddef.h>
#include <stdint.h>
#include <kern/conf.h>
#include <kern/util.h>
#include <kern/unit/x86/hpet.h>
#include <kern/unit/ia32/vm.h>

#if (HPET)

static struct hpetdrv hpetdrv;

void
hpetprobe(long id)
{
    struct hpet *ptr = !id ? (void *)HPET0BASE : (void *)HPET1BASE;
    uint32_t     dword1;
    uint32_t     dword2;

    dword1 = ptr->gencaplo;
    dword2 = ptr->gencaphi;
    if ((dword1) || (dword2)) {
        if (!id) {
            hpetdrv.iobase0 = ptr;
            hpetdrv.ntmr0 = hpetnumtim(ptr);
            hpetdrv.tmr0size = hpetcntsize(ptr);
            kprintf("HPET0: rev = 0x%x, vendor = 0x%x, %l timers, 64-bit = %x\n",
                    hpetrevid(ptr), hpetvendor(ptr),
                    hpetnumtim(ptr), hpetcntsize(ptr) >> 13);
        } else {
            hpetdrv.iobase1 = ptr;
            hpetdrv.ntmr1 = hpetnumtim(ptr);
            hpetdrv.tmr1size = hpetcntsize(ptr);
            kprintf("HPET1: rev = 0x%x, vendor = 0x%x, %l timers, 64-bit: %x\n",
                    hpetrevid(ptr), hpetvendor(ptr),
                    hpetnumtim(ptr), hpetcntsize(ptr));
        }
    }

    return;
}

void
hpetinit(void)
{
    unsigned long  len = HPETREGSIZE64;

    vmmapseg((uint32_t *)&_pagetab, HPET0BASE, HPET0BASE,
             HPET0BASE + len,
             PAGEPRES | PAGEWRITE | PAGENOCACHE | PAGEWIRED);
    vmmapseg((uint32_t *)&_pagetab, HPET1BASE, HPET1BASE,
             HPET1BASE + len,
             PAGEPRES | PAGEWRITE | PAGENOCACHE | PAGEWIRED);
    hpetprobe(0);
    hpetprobe(1);

    return;
}

#endif /* HPET */

