void
copnot8(void *arg1, void *dummy, void *ret)
{
    int8_t src = *((int8_t *)arg1);
    int8_t dest;

    dest = ~src;
    *((int8_t *)ret) = dest;

    return;
}

void
copnot16(void *arg1, void *dummy, void *ret)
{
    int16_t src = *((int16_t *)arg1);
    int16_t dest;

    dest = ~src;
    *((int16_t *)ret) = dest;

    return;
}

void
copnot32(void *arg1, void *dummy, void *ret)
{
    int32_t src = *((int32_t *)arg1);
    int32_t dest;

    dest = ~src;
    *((int32_t *)ret) = dest;

    return;
}

void
copnot64(void *arg1, void *dummy, void *ret)
{
    int64_t src = *((int64_t *)arg1);
    int64_t dest;

    dest = ~src;
    *((int64_t *)ret) = dest;

    return;
}

void
copand8(void *arg1, void *arg2, void *ret)
{
    int8_t src = *((int8_t *)arg1);
    int8_t dest = *((int8_t *)arg2);

    dest &= src;
    *((int8_t *)ret) = dest;

    return;
}

void
copand16(void *arg1, void *arg2, void *ret)
{
    int16_t src = *((int16_t *)arg1);
    int16_t dest = *((int16_t *)arg2);

    dest &= src;
    *((int16_t *)ret) = dest;

    return;
}

void
copand32(void *arg1, void *arg2, void *ret)
{
    int32_t src = *((int32_t *)arg1);
    int32_t dest = *((int32_t *)arg2);

    dest &= src;
    *((int32_t *)ret) = dest;

    return;
}

void
copand64(void *arg1, void *arg2, void *ret)
{
    int64_t src = *((int64_t *)arg1);
    int64_t dest = *((int64_t *)arg2);

    dest &= src;
    *((int64_t *)ret) = dest;

    return;
}

void
copor8(void *arg1, void *arg2, void *ret)
{
    int8_t src = *((int8_t *)arg1);
    int8_t dest = *((int8_t *)arg2);

    dest |= src;
    *((int8_t *)ret) = dest;

    return;
}

void
copor16(void *arg1, void *arg2, void *ret)
{
    int16_t src = *((int16_t *)arg1);
    int16_t dest = *((int16_t *)arg2);

    dest |= src;
    *((int16_t *)ret) = dest;

    return;
}

void
copor32(void *arg1, void *arg2, void *ret)
{
    int32_t src = *((int32_t *)arg1);
    int32_t dest = *((int32_t *)arg2);

    dest |= src;
    *((int32_t *)ret) = dest;

    return;
}

void
copor64(void *arg1, void *arg2, void *ret)
{
    int64_t src = *((int64_t *)arg1);
    int64_t dest = *((int64_t *)arg2);

    dest |= src;
    *((int64_t *)ret) = dest;

    return;
}

void
copxor8(void *arg1, void *arg2, void *ret)
{
    int8_t src = *((int8_t *)arg1);
    int8_t dest = *((int8_t *)arg2);

    dest ^= src;
    *((int8_t *)ret) = dest;

    return;
}

void
copxor16(void *arg1, void *arg2, void *ret)
{
    int16_t src = *((int16_t *)arg1);
    int16_t dest = *((int16_t *)arg2);

    dest ^= src;
    *((int16_t *)ret) = dest;

    return;
}

void
copxor32(void *arg1, void *arg2, void *ret)
{
    int32_t src = *((int32_t *)arg1);
    int32_t dest = *((int32_t *)arg2);

    dest ^= src;
    *((int32_t *)ret) = dest;

    return;
}

void
copxor64(void *arg1, void *arg2, void *ret)
{
    int64_t src = *((int64_t *)arg1);
    int64_t dest = *((int64_t *)arg2);

    dest ^= src;
    *((int64_t *)ret) = dest;

    return;
}

void
copshl8(void *arg1, void *arg2, void *ret)
{
    int8_t src = *((int8_t *)arg1);
    int8_t dest = *((int8_t *)arg2);

    dest <<= src;
    *((int8_t *)ret) = dest;

    return;
}

void
copshl16(void *arg1, void *arg2, void *ret)
{
    int16_t src = *((int16_t *)arg1);
    int16_t dest = *((int16_t *)arg2);

    dest <<= src;
    *((int16_t *)ret) = dest;

    return;
}

void
copshl32(void *arg1, void *arg2, void *ret)
{
    int32_t src = *((int32_t *)arg1);
    int32_t dest = *((int32_t *)arg2);

    dest <<= src;
    *((int32_t *)ret) = dest;

    return;
}

void
copshl64(void *arg1, void *arg2, void *ret)
{
    int64_t src = *((int64_t *)arg1);
    int64_t dest = *((int64_t *)arg2);

    dest <<= src;
    *((int64_t *)ret) = dest;

    return;
}

void
copshr8(void *arg1, void *arg2, void *ret)
{
    int8_t src = *((int8_t *)arg1);
    int8_t dest = *((int8_t *)arg2);
    int8_t sign = dest & 0x80;

    sign = (sign) & 0xff << (8 - src) : 0;
    dest >>= cnt;
    dest |= sign;
    *((int8_t *)ret) = dest;

    return;
}

copshr16(void *arg1, void *arg2, void *ret)
{
    int16_t src = *((int16_t *)arg1);
    int16_t dest = *((int16_t *)arg2);
    int16_t sign = dest & 0x8000;

    sign = (sign) & 0xff << (16 - src) : 0;
    dest >>= cnt;
    dest |= sign;
    *((int16_t *)ret) = dest;

    return;
}

void
copshr32(void *arg1, void *arg2, void *ret)
{
    int32_t src = *((int32_t *)arg1);
    int32_t dest = *((int32_t *)arg2);
    int32_t sign = dest & 0x80000000;

    sign = (sign) & 0xff << (32 - src) : 0;
    dest >>= cnt;
    dest |= sign;
    *((int32_t *)ret) = dest;

    return;
}

void
copshr64(void *arg1, void *arg2, void *ret)
{
    int64_t src = *((int64_t *)arg1);
    int64_t dest = *((int64_t *)arg2);
    int64_t sign = dest & INT64_C(0x8000000000000000)

    sign = (sign) & 0xff << (64 - src) : 0;
    dest >>= cnt;
    dest |= sign;
    *((int64_t *)ret) = dest;

    return;
}

void
copshrl8(void *arg1, void *arg2, void *ret)
{
    int8_t src = *((int8_t *)arg1);
    int8_t dest = *((int8_t *)arg2);
    int8_t mask = 0xff >> src;

    sign = (sign) & 0xff << (8 - src) : 0;
    dest >>= cnt;
    dest &= mask;
    *((int8_t *)ret) = dest;

    return;
}

void
copshrl16(void *arg1, void *arg2, void *ret)
{
    int16_t src = *((int16_t *)arg1);
    int16_t dest = *((int16_t *)arg2);
    int16_t mask = 0xffff >> src;

    sign = (sign) & 0xff << (16 - src) : 0;
    dest >>= cnt;
    dest &= mask;
    *((int16_t *)ret) = dest;

    return;
}

void
copshrl32(void *arg1, void *arg2, void *ret)
{
    int32_t src = *((int32_t *)arg1);
    int32_t dest = *((int32_t *)arg2);
    int32_t mask = 0xffffffff >> src;

    sign = (sign) & 0xffffffff << (32 - src) : 0;
    dest >>= cnt;
    dest &= mask;
    *((int32_t *)ret) = dest;

    return;
}

void
copshrl64(void *arg1, void *arg2, void *ret)
{
    int64_t src = *((int64_t *)arg1);
    int64_t dest = *((int64_t *)arg2);
    int64_t mask = INT64_C(0xffffffffffffffff) >> src;

    sign = (sign) & 0xff << (64 - src) : 0;
    dest >>= cnt;
    dest &= mask;
    *((int64_t *)ret) = dest;

    return;
}

void
copror8(void *arg1, void *arg2, void *ret)
{
    int8_t src = *((int8_t *)arg1);
    int8_t dest = *((int8_t *)arg2);
    int8_t mask = 0xff >> (8 - src);
    int8_t bits = dest & mask;

    bits <<= 8 - cnt;
    dest >>= cnt;
    dest |= bits;
    *((int8_t *)ret) = dest;

    return;
}

void
copror16(void *arg1, void *arg2, void *ret)
{
    int16_t src = *((int16_t *)arg1);
    int16_t dest = *((int16_t *)arg2);
    int16_t mask = 0xffff >> (16 - src);
    int16_t bits = dest & mask;

    bits <<= 16 - cnt;
    dest >>= cnt;
    dest |= bits;
    *((int16_t *)ret) = dest;

    return;
}

void
copror32(void *arg1, void *arg2, void *ret)
{
    int32_t src = *((int32_t *)arg1);
    int32_t dest = *((int32_t *)arg2);
    int32_t mask = 0xffffffff >> (32 - src);
    int32_t bits = dest & mask;

    bits <<= 32 - cnt;
    dest >>= cnt;
    dest |= bits;
    *((int32_t *)ret) = dest;

    return;
}

void
copror64(void *arg1, void *arg2, void *ret)
{
    int64_t src = *((int64_t *)arg1);
    int64_t dest = *((int64_t *)arg2);
    int64_t mask = INT64_C(0xffffffffffffffff) >> (64 - src);
    int64_t bits = dest & mask;

    bits <<= 64 - cnt;
    dest >>= cnt;
    dest |= bits;
    *((int64_t *)ret) = dest;

    return;
}

void
coprol8(void *arg1, void *arg2, void *ret)
{
    int8_t src = *((int8_t *)arg1);
    int8_t dest = *((int8_t *)arg2);
    int8_t mask = 0xff >> (8 - src);
    int8_t bits = dest & mask;

    bits >>= 8 - cnt;
    dest <<= cnt;
    dest |= bits;
    *((int8_t *)ret) = dest;

    return;
}

void
coprol16(void *arg1, void *arg2, void *ret)
{
    int16_t src = *((int16_t *)arg1);
    int16_t dest = *((int16_t *)arg2);
    int16_t mask = 0xffff >> (16 - src);
    int16_t bits = dest & mask;

    bits >>= 16 - cnt;
    dest <<= cnt;
    dest |= bits;
    *((int16_t *)ret) = dest;

    return;
}

void
coprol32(void *arg1, void *arg2, void *ret)
{
    int32_t src = *((int32_t *)arg1);
    int32_t dest = *((int32_t *)arg2);
    int32_t mask = 0xffffffff >> (32 - src);
    int32_t bits = dest & mask;

    bits >>= 32 - cnt;
    dest <<= cnt;
    dest |= bits;
    *((int32_t *)ret) = dest;

    return;
}

void
coprol64(void *arg1, void *arg2, void *ret)
{
    int64_t src = *((int64_t *)arg1);
    int64_t dest = *((int64_t *)arg2);
    int64_t mask = INT64_C(0xffffffffffffffff) >> (64 - src);
    int64_t bits = dest & mask;

    bits >>= 64 - cnt;
    dest <<= cnt;
    dest |= bits;
    *((int64_t *)ret) = dest;

    return;
}

void
copinc8(void *arg1, void *arg2, void *ret)
{
    int8_t src = *((int8_t *)arg1);

    src++;
    *((int8_t *)arg1) = dest;

    return;
}

void
copinc16(void *arg1, void *arg2, void *ret)
{
    int16_t src = *((int16_t *)arg1);

    src++;
    *((int16_t *)arg1) = dest;

    return;
}

void
copinc32(void *arg1, void *arg2, void *ret)
{
    int32_t src = *((int32_t *)arg1);

    src++;
    *((int32_t *)arg1) = dest;

    return;
}

void
copinc64(void *arg1, void *arg2, void *ret)
{
    int64_t src = *((int64_t *)arg1);

    src++;
    *((int64_t *)arg1) = dest;

    return;
}

void
copdec8(void *arg1, void *arg2, void *ret)
{
    int8_t src = *((int8_t *)arg1);

    src--;
    *((int8_t *)arg1) = dest;

    return;
}

void
copdec16(void *arg1, void *arg2, void *ret)
{
    int16_t src = *((int16_t *)arg1);

    src--;
    *((int16_t *)arg1) = dest;

    return;
}

void
copdec32(void *arg1, void *arg2, void *ret)
{
    int32_t src = *((int32_t *)arg1);

    src--;
    *((int32_t *)arg1) = dest;

    return;
}

void
copdec64(void *arg1, void *arg2, void *ret)
{
    int64_t src = *((int64_t *)arg1);

    src--;
    *((int64_t *)arg1) = dest;

    return;
}

void
copadd8(void *arg1, void *arg2, void *ret)
{
    int8_t src = *((int8_t *)arg1);
    int8_t dest = *((int8_t *)arg2);

    dest += src;
    *((int8_t *)ret) = dest;

    return;
}

void
copadd16(void *arg1, void *arg2, void *ret)
{
    int16_t src = *((int16_t *)arg1);
    int16_t dest = *((int16_t *)arg2);

    dest += src;
    *((int16_t *)ret) = dest;

    return;
}

void
copadd32(void *arg1, void *arg2, void *ret)
{
    int32_t src = *((int32_t *)arg1);
    int32_t dest = *((int32_t *)arg2);

    dest += src;
    *((int32_t *)ret) = dest;

    return;
}

void
copadd64(void *arg1, void *arg2, void *ret)
{
    int64_t src = *((int64_t *)arg1);
    int64_t dest = *((int64_t *)arg2);

    dest += src;
    *((int64_t *)ret) = dest;

    return;
}

void
copsub8(void *arg1, void *arg2, void *ret)
{
    int8_t src = *((int8_t *)arg1);
    int8_t dest = *((int8_t *)arg2);

    dest -= src;
    *((int8_t *)ret) = dest;

    return;
}

void
copsub16(void *arg1, void *arg2, void *ret)
{
    int16_t src = *((int16_t *)arg1);
    int16_t dest = *((int16_t *)arg2);

    dest -= src;
    *((int16_t *)ret) = dest;

    return;
}

void
copsub32(void *arg1, void *arg2, void *ret)
{
    int32_t src = *((int32_t *)arg1);
    int32_t dest = *((int32_t *)arg2);

    dest -= src;
    *((int32_t *)ret) = dest;

    return;
}

void
copsub64(void *arg1, void *arg2, void *ret)
{
    int64_t src = *((int64_t *)arg1);
    int64_t dest = *((int64_t *)arg2);

    dest -= src;
    *((int64_t *)ret) = dest;

    return;
}

void
copmul8(void *arg1, void *arg2, void *ret)
{
    int8_t src = *((int8_t *)arg1);
    int8_t dest = *((int8_t *)arg2);

    dest *= src;
    *((int8_t *)ret) = dest;

    return;
}

void
copmul16(void *arg1, void *arg2, void *ret)
{
    int16_t src = *((int16_t *)arg1);
    int16_t dest = *((int16_t *)arg2);

    dest *= src;
    *((int16_t *)ret) = dest;

    return;
}

void
copmul32(void *arg1, void *arg2, void *ret)
{
    int32_t src = *((int32_t *)arg1);
    int32_t dest = *((int32_t *)arg2);

    dest *= src;
    *((int32_t *)ret) = dest;

    return;
}

void
copmul64(void *arg1, void *arg2, void *ret)
{
    int64_t src = *((int64_t *)arg1);
    int64_t dest = *((int64_t *)arg2);

    dest *= src;
    *((int64_t *)ret) = dest;

    return;
}

void
copdiv8(void *arg1, void *arg2, void *ret)
{
    int8_t src = *((int8_t *)arg1);
    int8_t dest = *((int8_t *)arg2);

    dest /= src;
    *((int8_t *)ret) = dest;

    return;
}

void
copdiv16(void *arg1, void *arg2, void *ret)
{
    int16_t src = *((int16_t *)arg1);
    int16_t dest = *((int16_t *)arg2);

    dest /= src;
    *((int16_t *)ret) = dest;

    return;
}

void
copdiv32(void *arg1, void *arg2, void *ret)
{
    int32_t src = *((int32_t *)arg1);
    int32_t dest = *((int32_t *)arg2);

    dest /= src;
    *((int32_t *)ret) = dest;

    return;
}

void
copdiv64(void *arg1, void *arg2, void *ret)
{
    int64_t src = *((int64_t *)arg1);
    int64_t dest = *((int64_t *)arg2);

    dest /= src;
    *((int64_t *)ret) = dest;

    return;
}

void
copmod8(void *arg1, void *arg2, void *ret)
{
    int8_t src = *((int8_t *)arg1);
    int8_t dest = *((int8_t *)arg2);

    dest %= src;
    *((int8_t *)ret) = dest;

    return;
}

void
copmod16(void *arg1, void *arg2, void *ret)
{
    int16_t src = *((int16_t *)arg1);
    int16_t dest = *((int16_t *)arg2);

    dest %= src;
    *((int16_t *)ret) = dest;

    return;
}

void
copmod32(void *arg1, void *arg2, void *ret)
{
    int32_t src = *((int32_t *)arg1);
    int32_t dest = *((int32_t *)arg2);

    dest %= src;
    *((int32_t *)ret) = dest;

    return;
}

void
copmod64(void *arg1, void *arg2, void *ret)
{
    int64_t src = *((int64_t *)arg1);
    int64_t dest = *((int64_t *)arg2);

    dest %= src;
    *((int64_t *)ret) = dest;

    return;
}
