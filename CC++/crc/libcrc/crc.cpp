#include "crc.h"
#include "cmath"

ulong bitReverse(ulong v, int b){
    ulong converts[] = {
        0xaaaaaaaa,
        0xcccccccc,
        0xf0f0f0f0,
        0xff00ff00,
        0xffff0000
    };
    ulong mask = 0xffffffff << b;
    ulong t = v & mask;
    int shift = 1;
    ulong count = (ulong)ceil(log(double(b)) / log(2.0));
    for (uint i = 0; i < count; i++) {
        ulong conv = converts[i];
        v = (v & conv) >> shift | (v & ~conv) << shift;
        shift <<= 1;
    }
    return t | ((v >> ((1L << count) - b)) & ~mask);
}

ulong bitReverseHex(ulong v){
    v = (v & 0xaaaaaaaa) >> 1 | (v & ~0xaaaaaaaa) << 1;
    v = (v & 0xcccccccc) >> 2 | (v & ~0xcccccccc) << 2;
    return v;
}
