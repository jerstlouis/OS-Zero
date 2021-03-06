#include <stdint.h>
#include <stddef.h>
#include <sys/io.h>

//#define LIST_TYPE  struct pcidev
//#define LISTQ_TYPE struct pcidevlist
//#include <zero/list.h>

#include <kern/conf.h>
#include <kern/mem.h>
#include <kern/util.h>
#include <kern/io/drv/pc/pci.h>

#if (AC97)
extern void ac97init(struct pcidev *);
#endif

//static void    *pcidrvtab[4096] ALIGNED(PAGESIZE);
static struct pcidrvent *pcidrvtab[65536];
struct pcidev            pcidevtab[PCINDEV];
//struct pcidevlist pcidevlist;
long                     pcifound;
long                     pcindev;

long
pciprobe(void)
{
    outl(PCICONFBIT, PCICONFADR);
    if (inl(PCICONFADR) != PCICONFBIT) {
        kprintf("PCI controller not found\n");

        return 0;
    }
    kprintf("PCI controller found\n");

    return 1;
}

struct pcidrvent *
pcifinddrv(uint16_t vendor, uint16_t devid)
{
    struct pcidrvent *ptr = pcidrvtab[vendor];
    struct pcidrvent *drv = NULL;

    if (ptr) {
        drv = &ptr[devid];
    }

    return drv;
}

void
pciregdrv(uint16_t vendor, uint16_t devid,
          const char *str, pciinitfunc_t *initfunc)
{
    struct pcidrvent *ptr = pcidrvtab[vendor];
    struct pcidrvent *drv;

    if (!ptr) {
        ptr = kmalloc(65536 * sizeof(struct pcidrvent));
        if (ptr) {
            kbzero(ptr, 65536 * sizeof(struct pcidrvent));
            pcidrvtab[vendor] = ptr;
        }
    }
    if (ptr) {
        drv = &ptr[devid];
        drv->init = initfunc;
        drv->str = str;
    }

    return;
}

#if 0
struct pcidrvent *
pcifinddrv(uint16_t vendor, uint16_t devid)
{
    struct pcidrvent *drv = NULL;
    void             *ptr;
    uint32_t          vd;
    uint16_t          key1;
    uint16_t          key2;
    uint16_t          key3;

    vd = vendor;
    vd <<= 16;
    vd |= devid;
    key1 = vd >> 20;
    key2 = (vd >> 10) & 0x3ff;
    key3 = vd & 0x3ff;
    kprintf("FIND: %x:%x:%x - ", key1, key2, key3);
    ptr = ((void **)pcidrvtab)[key1];
    if (ptr) {
        {
            long  ndx;
            long *lptr = ptr;
            
            for (ndx = 0 ; ndx < 1024 ; ndx++) {
                if (*lptr) {
                    kprintf("%ld: %ld\n", ndx, *lptr);
                }
            }
        }
        kprintf("%p - ", ptr);
//        ptr = ((void **)ptr)[key2];
#if 0
        ptr = ((void **)ptr)[key2];
        kprintf("%p - ", ptr);
        if (ptr) {
            drv = &(((struct pcidrvent *)ptr)[key3]);
        }
#endif
        ptr = ((struct pcidrvent **)ptr)[key2];
        kprintf("%p - ", ptr);
        if (ptr) {
            drv = &(((struct pcidrvent *)ptr)[key3]);
        }
    }
    kprintf("%p\n", drv);

    return drv;
}

void
pciregdrv(uint16_t vendor, uint16_t devid, char *str, pciinitfunc_t *initfunc)
{
    struct pcidrvent *drv = NULL;
    void             *ptr1 = NULL;
    void             *ptr2 = NULL;
    uint32_t          vd;
    uint16_t          key1;
    uint16_t          key2;
    uint16_t          key3;
    
    vd = vendor;
    vd <<= 16;
    vd |= devid;
    key1 = vd >> 20;
    key2 = (vd >> 10) & 0x3ff;
    key3 = vd & 0x3ff;
    kprintf("REG: %x:%x:%x - %s - ", key1, key2, key3, str);
    ptr1 = ((void **)pcidrvtab)[key1];
    if (!ptr1) {
        ptr1 = kmalloc(4096 * sizeof(void *));
        kprintf("ALLOC - ");
        if  (ptr1) {
//            kbzero(ptr1, 4096 * sizeof(void *));
            kmemset(ptr1, 0, 4096 * sizeof(void *));
            ((void **)pcidrvtab)[key1] = ptr1;
        }
    }
    kprintf("%p - ", ptr1);
    if (ptr1) {
        ptr2 = ((void **)ptr1)[key2];
        if (!ptr2) {
            ptr2 = kmalloc(1024 * sizeof(struct pcidrvent));
            kprintf("ALLOC - ");
            if (ptr2) {
//                kbzero(ptr2, 1024 * sizeof(struct pcidrvent));
                kmemset(ptr2, 0, 1024 * sizeof(struct pcidrvent));
                ((void **)ptr1)[key2] = ptr2;
            }
        }
//        ptr1 = ptr2;
    }
    kprintf("%p - ", ptr2);
    if (ptr2) {
//        drv = &(((struct pcidrvent *)ptr1)[key3]);
        drv = &(((struct pcidrvent *)ptr2)[key3]);
        drv->init = initfunc;
        drv->str = str;
    }
    kprintf("%p\n", drv);

    return;
}
#endif

#if 0
uint8_t
pcireadconfb(uint8_t busid, uint8_t slotid, uint8_t funcid, uint8_t ofs)
{
    uint32_t conf;
    uint32_t bus = busid;
    uint32_t slot = slotid;
    uint32_t func = funcid;
    uint16_t byte = 0;

    conf = (bus << 16) | (slot << 11) | (func << 8) | ofs | PCICONFBIT;
    outl(conf, PCICONFADR);
    byte = inb(PCICONFADR + (ofs & 0x03));

    return byte;
}
#endif

uint16_t
pcireadconfw(uint8_t busid, uint8_t slotid, uint8_t funcid, uint8_t ofs)
{
    uint32_t conf;
    uint32_t bus = busid;
    uint32_t slot = slotid;
    uint32_t func = funcid;
    uint16_t word = 0;

    conf = (bus << 16) | (slot << 11) | (func << 8) | ofs | PCICONFBIT;
    outl(conf, PCICONFADR);
//    tmp = inw(PCICONFDATA) >> ((ofs & 0x02) << 3) & 0xffff);
    word = inw(PCICONFDATA + (ofs & 0x02));

    return word;
}

#if 0
uint32_t
pcireadconfl(uint8_t busid, uint8_t slotid, uint8_t funcid, uint8_t ofs)
{
    uint32_t conf;
    uint32_t bus = busid;
    uint32_t slot = slotid;
    uint32_t func = funcid;
    uint32_t longword = 0;

    conf = (bus << 16) | (slot << 11) | (func << 8) | ofs | PCICONFBIT;
    outl(conf, PCICONFADR);
//    tmp = inw(PCICONFDATA) >> ((ofs & 0x02) << 3) & 0xffff);
    longword = inl(PCICONFDATA);

    return longword;
}
#endif

#if 0
void
pciwriteconfb(uint8_t busid, uint8_t slotid, uint8_t funcid, uint8_t ofs,
                  uint8_t val)
{
    uint32_t conf;
    uint32_t bus = busid;
    uint32_t slot = slotid;
    uint32_t func = funcid;
    uint16_t byte = 0;

    conf = (bus << 16) | (slot << 11) | (func << 8) | ofs | PCICONFBIT;
    outb(conf, PCICONFADR);

    return byte;
}

void
pciwriteconfw(uint8_t busid, uint8_t slotid, uint8_t funcid, uint8_t ofs)
{
    uint32_t conf;
    uint32_t bus = busid;
    uint32_t slot = slotid;
    uint32_t func = funcid;
    uint16_t word = 0;

    conf = (bus << 16) | (slot << 11) | (func << 8) | ofs | PCICONFBIT;
    outl(conf, PCICONFADR);
//    tmp = inw(PCICONFDATA) >> ((ofs & 0x02) << 3) & 0xffff);
    word = inw(PCICONFDATA + (ofs & 0x02));

    return word;
}

uint16_t
pcireadconfl(uint8_t busid, uint8_t slotid, uint8_t funcid, uint8_t ofs)
{
    uint32_t conf;
    uint32_t bus = busid;
    uint32_t slot = slotid;
    uint32_t func = funcid;
    uint16_t longword = 0;

    conf = (bus << 16) | (slot << 11) | (func << 8) | ofs | PCICONFBIT;
    outl(conf, PCICONFADR);
//    tmp = inw(PCICONFDATA) >> ((ofs & 0x02) << 3) & 0xffff);
    longword = inl(PCICONFDATA);

    return longword;
}
#endif

int
pcireadconf1(uint8_t busid, uint8_t slotid, uint8_t funcid,
             uint16_t regid, uint8_t len)
{
    int retval = ~0;

    outl(pciconfadr1(busid, slotid, funcid, regid), PCICONFADR);
    switch (len) {
        case 4:
            retval = inl(PCICONFADR);

            break;
        case 2:
            retval = inw(PCICONFADR + (regid & 0x02));

            break;
        case 1:
            retval = inb(PCICONFADR + (regid & 0x03));

            break;
    }

    return retval;
}

void
pciwriteconf1(uint8_t busid, uint8_t slotid, uint8_t funcid,
              uint16_t regid, uint8_t len, uint32_t val)
{
    outl(pciconfadr1(busid, slotid, funcid, regid), PCICONFADR);
    switch (len) {
        case 4:
            outl(val, PCICONFADR);

            break;
        case 2:
            outw((uint16_t)val, PCICONFADR + (regid & 0x02));

            break;
        case 1:
            outb((uint8_t)val, PCICONFADR + (regid & 0x03));

            break;
    }

    return;
}

int
pcireadconf2(uint8_t busid, uint8_t slotid, uint8_t funcid,
             uint16_t regid, uint8_t len)
{
    int retval = ~0;

    if (!(slotid & 0x10)) {
        outb((uint8_t)(0xf0 | (funcid << 1)), PCICONFADR);
        outb(busid, 0xcfa);
        switch (len) {
            case 4:
                retval = inl(pciconfadr2(slotid, regid));

                break;
            case 2:
                retval = inw(pciconfadr2(slotid, regid));

                break;
            case 1:
                retval = inb(pciconfadr2(slotid, regid));

                break;
        }
        outb(0, PCICONFADR);
    }

    return retval;
}

void
pciwriteconf2(uint8_t busid, uint8_t slotid, uint8_t funcid,
              uint16_t regid, uint8_t len, uint8_t val)
{
    if (!(slotid & 0x10)) {
        outb((uint8_t)(0xf0 | (funcid << 1)), PCICONFADR);
        outb(busid, 0xcfa);
        switch (len) {
            case 4:
                outl(val, pciconfadr2(slotid, regid));
                
                break;
            case 2:
                outw(val, pciconfadr2(slotid, regid));

                break;
            case 1:
                outb(val, pciconfadr2(slotid, regid));

                break;
        }
        outb(0, PCICONFADR);
    }

    return;
}

uint16_t
pcichkvendor(uint8_t busid, uint8_t slotid, uint16_t *devret)
{
    uint16_t vendor;
    uint16_t dev;

    vendor = pcireadconfw(busid, slotid, 0, 0);
    if (vendor != 0xffff && (devret)) {
        dev = pcireadconfw(busid, slotid, 0, 2);
        *devret = dev;
    }

    return vendor;
}

void
pciinit(void)
{
    struct pcidrvent *drv;
    struct pcidev    *dev;
    pciinitfunc_t    *initfunc;
    uint16_t          vendor;
    uint16_t          devid;
    long              bus;
    long              slot;
    long              ndev;

    pcifound = pciprobe();
    if (pcifound) {
        pciregdrv(0x8086, 0x1237, "Intel 82440LX/EX Chipset", NULL);
        pciregdrv(0x8086, 0x7000, "Intel 82371SB PCI-to-ISA Bridge (Triton II)",
                  NULL);
        pciregdrv(0x1013, 0xb8, "Cirrus Logic CL-GD5546 Graphics Card", NULL);
        pciregdrv(0x8086, 0x100e, "Intel PRO 1000/MT Ethernet Controller",
                  NULL);
#if (AC97)
        pciregdrv(0x8086, 0x2415, "Aureal AD1881 SOUNDMAX (AC97)", ac97init);
#endif
        ndev = 0;
        for (bus = 0 ; bus < PCINBUS ; bus++) {
            for (slot = 0 ; slot < PCINSLOT ; slot++) {
                vendor = pcichkvendor(bus, slot, &devid);
                if (vendor != 0xffff) {
                    if (ndev < PCINDEV) {
                        dev = &pcidevtab[ndev];
                        dev->vendor = vendor;
                        dev->id = devid;
                        dev->bus = bus;
                        dev->slot = slot;
//                        listqueue(&pcidevlist, &pcidevtab[ndev]);
                        ndev++;
                    }
                }
            }
        }
        if (ndev) {
            pcindev = ndev;
            dev = &pcidevtab[0];
            while (ndev--) {
                drv = pcifinddrv(dev->vendor, dev->id);
                if (drv) {
                    kprintf("PCI: %s: bus: %x, slot: %x, vendor: 0x%x, device: 0x%x\n",
                            (drv->str) ? drv->str : "UNKNOWN",
                            dev->bus, dev->slot,
                            dev->vendor, dev->id);
                    initfunc = drv->init;
                    if (initfunc) {
                        initfunc(dev);
                    }
                } else {
                    kprintf("PCI: bus: %x, slot: %x, vendor: 0x%x, device: 0x%x\n",
                            dev->bus, dev->slot,
                            dev->vendor, dev->id);
                }
                dev++;
            }
        }
    }

    return;
}

