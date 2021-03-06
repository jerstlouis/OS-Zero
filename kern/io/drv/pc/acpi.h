#ifndef __KERN_IO_DRV_PC_ACPI_H__
#define __KERN_IO_DRV_PC_ACPI_H__

#include <stdint.h>

#include <zero/param.h>
#include <zero/cdecl.h>

#define ACPIRSDPTRSIG UINT64_C(0x2052545020445352) // "RSD PTR "

struct acpidesc {
    char     sig[8];
    uint8_t  chksum;
    char     oemstr[8];
    uint8_t  rev;
    uint32_t sysdesc;
    uint32_t len;
    uint64_t extsysdesc;
    uint64_t extchksum;
    uint8_t  res[3];
} PACK();

struct acpitab {
    char sig[4];
    uint32_t len;
    uint8_t  rev;
    uint8_t  chksum;
    char     oemid[6];
    char     oemtabid[8];
    uint32_t oemrev;
    uint32_t creatorid;
    uint32_t creatorrev;
} PACK();

#endif /* __KERN_IO_DRV_PC_ACPI_H__ */

