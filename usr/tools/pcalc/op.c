void
opnot8(void *arg1, void *dummy)
{
    int8_t src = *((int8_t *)arg1);
    int8_t dest;

    dest = ~src;
    *((int8_t *)arg1) = dest;

    return;
}

void
opnot16(void *arg1, void *dummy)
{
    int16_t src = *((int16_t *)arg1);
    int16_t dest;

    dest = ~src;
    *((int16_t *)arg1) = dest;

    return;
}

void
opnot32(void *arg1, void *dummy)
{
    int32_t src = *((int32_t *)arg1);
    int32_t dest;

    dest = ~src;
    *((int32_t *)arg1) = dest;

    return;
}

void
opnot64(void *arg1, void *dummy)
{
    int64_t src = *((int64_t *)arg1);
    int64_t dest;

    dest = ~src;
    *((int64_t *)arg1) = dest;

    return;
}

void
opand8(void *arg1, void *arg2)
{
    int8_t src = *((int8_t *)arg1);
    int8_t dest = *((int8_t *)arg2);

    dest &= src;
    *((int8_t *)arg2) = dest;

    return;
}

void
opand16(void *arg1, void *arg2)
{
    int16_t src = *((int16_t *)arg1);
    int16_t dest = *((int16_t *)arg2);

    dest &= src;
    *((int16_t *)arg2) = dest;

    return;
}

void
opand32(void *arg1, void *arg2)
{
    int32_t src = *((int32_t *)arg1);
    int32_t dest = *((int32_t *)arg2);

    dest &= src;
    *((int32_t *)arg2) = dest;

    return;
}

void
opand64(void *arg1, void *arg2)
{
    int64_t src = *((int64_t *)arg1);
    int64_t dest = *((int64_t *)arg2);

    dest &= src;
    *((int64_t *)arg2) = dest;

    return;
}

void
opor8(void *arg1, void *arg2)
{
    int8_t src = *((int8_t *)arg1);
    int8_t dest = *((int8_t *)arg2);

    dest |= src;
    *((int8_t *)arg2) = dest;

    return;
}

void
opor16(void *arg1, void *arg2)
{
    int16_t src = *((int16_t *)arg1);
    int16_t dest = *((int16_t *)arg2);

    dest |= src;
    *((int16_t *)arg2) = dest;

    return;
}

void
opor32(void *arg1, void *arg2)
{
    int32_t src = *((int32_t *)arg1);
    int32_t dest = *((int32_t *)arg2);

    dest |= src;
    *((int32_t *)arg2) = dest;

    return;
}

void
opor64(void *arg1, void *arg2)
{
    int64_t src = *((int64_t *)arg1);
    int64_t dest = *((int64_t *)arg2);

    dest |= src;
    *((int64_t *)arg2) = dest;

    return;
}

void
opxor8(void *arg1, void *arg2)
{
    int8_t src = *((int8_t *)arg1);
    int8_t dest = *((int8_t *)arg2);

    dest ^= src;
    *((int8_t *)arg2) = dest;

    return;
}

void
opxor16(void *arg1, void *arg2)
{
    int16_t src = *((int16_t *)arg1);
    int16_t dest = *((int16_t *)arg2);

    dest ^= src;
    *((int16_t *)arg2) = dest;

    return;
}

void
opxor32(void *arg1, void *arg2)
{
    int32_t src = *((int32_t *)arg1);
    int32_t dest = *((int32_t *)arg2);

    dest ^= src;
    *((int32_t *)arg2) = dest;

    return;
}

void
opxor64(void *arg1, void *arg2)
{
    int64_t src = *((int64_t *)arg1);
    int64_t dest = *((int64_t *)arg2);

    dest ^= src;
    *((int64_t *)arg2) = dest;

    return;
}

void
opshl8(void *arg1, void *arg2)
{
    int8_t src = *((int8_t *)arg1);
    int8_t dest = *((int8_t *)arg2);

    dest <<= src;
    *((int8_t *)arg2) = dest;

    return;
}

void
opshl16(void *arg1, void *arg2)
{
    int16_t src = *((int16_t *)arg1);
    int16_t dest = *((int16_t *)arg2);

    dest <<= src;
    *((int16_t *)arg2) = dest;

    return;
}

void
opshl32(void *arg1, void *arg2)
{
    int32_t src = *((int32_t *)arg1);
    int32_t dest = *((int32_t *)arg2);

    dest <<= src;
    *((int32_t *)arg2) = dest;

    return;
}

void
opshl64(void *arg1, void *arg2)
{
    int64_t src = *((int64_t *)arg1);
    int64_t dest = *((int64_t *)arg2);

    dest <<= src;
    *((int64_t *)arg2) = dest;

    return;
}

void
opshr8(void *arg1, void *arg2)
{
    int8_t src = *((int8_t *)arg1);
    int8_t dest = *((int8_t *)arg2);
    int8_t sign = dest & 0x80;

    sign = (sign) & 0xff << (8 - src) : 0;
    dest >>= cnt;
    dest |= sign;
    *((int8_t *)arg2) = dest;

    return;
}

opshr16(void *arg1, void *arg2)
{
    int16_t src = *((int16_t *)arg1);
    int16_t dest = *((int16_t *)arg2);
    int16_t sign = dest & 0x8000;

    sign = (sign) & 0xff << (16 - src) : 0;
    dest >>= cnt;
    dest |= sign;
    *((int16_t *)arg2) = dest;

    return;
}

void
opshr32(void *arg1, void *arg2)
{
    int32_t src = *((int32_t *)arg1);
    int32_t dest = *((int32_t *)arg2);
    int32_t sign = dest & 0x80000000;

    sign = (sign) & 0xff << (32 - src) : 0;
    dest >>= cnt;
    dest |= sign;
    *((int32_t *)arg2) = dest;

    return;
}

void
opshr64(void *arg1, void *arg2)
{
    int64_t src = *((int64_t *)arg1);
    int64_t dest = *((int64_t *)arg2);
    int64_t sign = dest & INT64_C(0x8000000000000000)

    sign = (sign) & 0xff << (64 - src) : 0;
    dest >>= cnt;
    dest |= sign;
    *((int64_t *)arg2) = dest;

    return;
}

void
opshrl8(void *arg1, void *arg2)
{
    int8_t src = *((int8_t *)arg1);
    int8_t dest = *((int8_t *)arg2);
    int8_t mask = 0xff >> src;

    sign = (sign) & 0xff << (8 - src) : 0;
    dest >>= cnt;
    dest &= mask;
    *((int8_t *)arg2) = dest;

    return;
}

void
opshrl16(void *arg1, void *arg2)
{
    int16_t src = *((int16_t *)arg1);
    int16_t dest = *((int16_t *)arg2);
    int16_t mask = 0xffff >> src;

    sign = (sign) & 0xff << (16 - src) : 0;
    dest >>= cnt;
    dest &= mask;
    *((int16_t *)arg2) = dest;

    return;
}

void
opshrl32(void *arg1, void *arg2)
{
    int32_t src = *((int32_t *)arg1);
    int32_t dest = *((int32_t *)arg2);
    int32_t mask = 0xffffffff >> src;

    sign = (sign) & 0xffffffff << (32 - src) : 0;
    dest >>= cnt;
    dest &= mask;
    *((int32_t *)arg2) = dest;

    return;
}

void
opshrl64(void *arg1, void *arg2)
{
    int64_t src = *((int64_t *)arg1);
    int64_t dest = *((int64_t *)arg2);
    int64_t mask = INT64_C(0xffffffffffffffff) >> src;

    sign = (sign) & 0xff << (64 - src) : 0;
    dest >>= cnt;
    dest &= mask;
    *((int64_t *)arg2) = dest;

    return;
}

void
opror8(void *arg1, void *arg2)
{
    int8_t src = *((int8_t *)arg1);
    int8_t dest = *((int8_t *)arg2);
    int8_t mask = 0xff >> (8 - src);
    int8_t bits = dest & mask;

    bits <<= 8 - cnt;
    dest >>= cnt;
    dest |= bits;
    *((int8_t *)arg2) = dest;

    return;
}

void
opror16(void *arg1, void *arg2)
{
    int16_t src = *((int16_t *)arg1);
    int16_t dest = *((int16_t *)arg2);
    int16_t mask = 0xffff >> (16 - src);
    int16_t bits = dest & mask;

    bits <<= 16 - cnt;
    dest >>= cnt;
    dest |= bits;
    *((int16_t *)arg2) = dest;

    return;
}

void
opror32(void *arg1, void *arg2)
{
    int32_t src = *((int32_t *)arg1);
    int32_t dest = *((int32_t *)arg2);
    int32_t mask = 0xffffffff >> (32 - src);
    int32_t bits = dest & mask;

    bits <<= 32 - cnt;
    dest >>= cnt;
    dest |= bits;
    *((int32_t *)arg2) = dest;

    return;
}

void
opror64(void *arg1, void *arg2)
{
    int64_t src = *((int64_t *)arg1);
    int64_t dest = *((int64_t *)arg2);
    int64_t mask = INT64_C(0xffffffffffffffff) >> (64 - src);
    int64_t bits = dest & mask;

    bits <<= 64 - cnt;
    dest >>= cnt;
    dest |= bits;
    *((int64_t *)arg2) = dest;

    return;
}

void
oprol8(void *arg1, void *arg2)
{
    int8_t src = *((int8_t *)arg1);
    int8_t dest = *((int8_t *)arg2);
    int8_t mask = 0xff >> (8 - src);
    int8_t bits = dest & mask;

    bits >>= 8 - cnt;
    dest <<= cnt;
    dest |= bits;
    *((int8_t *)arg2) = dest;

    return;
}

void
oprol16(void *arg1, void *arg2)
{
    int16_t src = *((int16_t *)arg1);
    int16_t dest = *((int16_t *)arg2);
    int16_t mask = 0xffff >> (16 - src);
    int16_t bits = dest & mask;

    bits >>= 16 - cnt;
    dest <<= cnt;
    dest |= bits;
    *((int16_t *)arg2) = dest;

    return;
}

void
oprol32(void *arg1, void *arg2)
{
    int32_t src = *((int32_t *)arg1);
    int32_t dest = *((int32_t *)arg2);
    int32_t mask = 0xffffffff >> (32 - src);
    int32_t bits = dest & mask;

    bits >>= 32 - cnt;
    dest <<= cnt;
    dest |= bits;
    *((int32_t *)arg2) = dest;

    return;
}

void
oprol64(void *arg1, void *arg2)
{
    int64_t src = *((int64_t *)arg1);
    int64_t dest = *((int64_t *)arg2);
    int64_t mask = INT64_C(0xffffffffffffffff) >> (64 - src);
    int64_t bits = dest & mask;

    bits >>= 64 - cnt;
    dest <<= cnt;
    dest |= bits;
    *((int64_t *)arg2) = dest;

    return;
}

void
opinc8(void *arg1, void *arg2)
{
    int8_t src = *((int8_t *)arg1);

    src++;
    *((int8_t *)arg1) = dest;

    return;
}

void
opinc16(void *arg1, void *arg2)
{
    int16_t src = *((int16_t *)arg1);

    src++;
    *((int16_t *)arg1) = dest;

    return;
}

void
opinc32(void *arg1, void *arg2)
{
    int32_t src = *((int32_t *)arg1);

    src++;
    *((int32_t *)arg1) = dest;

    return;
}

void
opinc64(void *arg1, void *arg2)
{
    int64_t src = *((int64_t *)arg1);

    src++;
    *((int64_t *)arg1) = dest;

    return;
}

void
opdec8(void *arg1, void *arg2)
{
    int8_t src = *((int8_t *)arg1);

    src--;
    *((int8_t *)arg1) = dest;

    return;
}

void
opdec16(void *arg1, void *arg2)
{
    int16_t src = *((int16_t *)arg1);

    src--;
    *((int16_t *)arg1) = dest;

    return;
}

void
opdec32(void *arg1, void *arg2)
{
    int32_t src = *((int32_t *)arg1);

    src--;
    *((int32_t *)arg1) = dest;

    return;
}

void
opdec64(void *arg1, void *arg2)
{
    int64_t src = *((int64_t *)arg1);

    src--;
    *((int64_t *)arg1) = dest;

    return;
}

void
opadd8(void *arg1, void *arg2)
{
    int8_t src = *((int8_t *)arg1);
    int8_t dest = *((int8_t *)arg2);

    dest += src;
    *((int8_t *)arg2) = dest;

    return;
}

void
opadd16(void *arg1, void *arg2)
{
    int16_t src = *((int16_t *)arg1);
    int16_t dest = *((int16_t *)arg2);

    dest += src;
    *((int16_t *)arg2) = dest;

    return;
}

void
opadd32(void *arg1, void *arg2)
{
    int32_t src = *((int32_t *)arg1);
    int32_t dest = *((int32_t *)arg2);

    dest += src;
    *((int32_t *)arg2) = dest;

    return;
}

void
opadd64(void *arg1, void *arg2)
{
    int64_t src = *((int64_t *)arg1);
    int64_t dest = *((int64_t *)arg2);

    dest += src;
    *((int64_t *)arg2) = dest;

    return;
}

void
opsub8(void *arg1, void *arg2)
{
    int8_t src = *((int8_t *)arg1);
    int8_t dest = *((int8_t *)arg2);

    dest -= src;
    *((int8_t *)arg2) = dest;

    return;
}

void
opsub16(void *arg1, void *arg2)
{
    int16_t src = *((int16_t *)arg1);
    int16_t dest = *((int16_t *)arg2);

    dest -= src;
    *((int16_t *)arg2) = dest;

    return;
}

void
opsub32(void *arg1, void *arg2)
{
    int32_t src = *((int32_t *)arg1);
    int32_t dest = *((int32_t *)arg2);

    dest -= src;
    *((int32_t *)arg2) = dest;

    return;
}

void
opsub64(void *arg1, void *arg2)
{
    int64_t src = *((int64_t *)arg1);
    int64_t dest = *((int64_t *)arg2);

    dest -= src;
    *((int64_t *)arg2) = dest;

    return;
}

void
opmul8(void *arg1, void *arg2)
{
    int8_t src = *((int8_t *)arg1);
    int8_t dest = *((int8_t *)arg2);

    dest *= src;
    *((int8_t *)arg2) = dest;

    return;
}

void
opmul16(void *arg1, void *arg2)
{
    int16_t src = *((int16_t *)arg1);
    int16_t dest = *((int16_t *)arg2);

    dest *= src;
    *((int16_t *)arg2) = dest;

    return;
}

void
opmul32(void *arg1, void *arg2)
{
    int32_t src = *((int32_t *)arg1);
    int32_t dest = *((int32_t *)arg2);

    dest *= src;
    *((int32_t *)arg2) = dest;

    return;
}

void
opmul64(void *arg1, void *arg2)
{
    int64_t src = *((int64_t *)arg1);
    int64_t dest = *((int64_t *)arg2);

    dest *= src;
    *((int64_t *)arg2) = dest;

    return;
}

void
opdiv8(void *arg1, void *arg2)
{
    int8_t src = *((int8_t *)arg1);
    int8_t dest = *((int8_t *)arg2);

    dest /= src;
    *((int8_t *)arg2) = dest;

    return;
}

void
opdiv16(void *arg1, void *arg2)
{
    int16_t src = *((int16_t *)arg1);
    int16_t dest = *((int16_t *)arg2);

    dest /= src;
    *((int16_t *)arg2) = dest;

    return;
}

void
opdiv32(void *arg1, void *arg2)
{
    int32_t src = *((int32_t *)arg1);
    int32_t dest = *((int32_t *)arg2);

    dest /= src;
    *((int32_t *)arg2) = dest;

    return;
}

void
opdiv64(void *arg1, void *arg2)
{
    int64_t src = *((int64_t *)arg1);
    int64_t dest = *((int64_t *)arg2);

    dest /= src;
    *((int64_t *)arg2) = dest;

    return;
}

void
opmod8(void *arg1, void *arg2)
{
    int8_t src = *((int8_t *)arg1);
    int8_t dest = *((int8_t *)arg2);

    dest %= src;
    *((int8_t *)arg2) = dest;

    return;
}

void
opmod16(void *arg1, void *arg2)
{
    int16_t src = *((int16_t *)arg1);
    int16_t dest = *((int16_t *)arg2);

    dest %= src;
    *((int16_t *)arg2) = dest;

    return;
}

void
opmod32(void *arg1, void *arg2)
{
    int32_t src = *((int32_t *)arg1);
    int32_t dest = *((int32_t *)arg2);

    dest %= src;
    *((int32_t *)arg2) = dest;

    return;
}

void
opmod64(void *arg1, void *arg2)
{
    int64_t src = *((int64_t *)arg1);
    int64_t dest = *((int64_t *)arg2);

    dest %= src;
    *((int64_t *)arg2) = dest;

    return;
}
