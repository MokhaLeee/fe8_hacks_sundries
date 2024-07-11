#include "gbafe.h"

extern u8 FireRingBgfx_081B3DF4[];
extern u8 FireRingBgfx_081B3E14[];
extern u8 FireRingBgfx_081B43E4[];
extern u8 FireRingBgfx_081B4730[];
extern u8 FireRingBgfx_081B498C[];
extern u8 FireRingBgfx_081B4BE8[];
extern u8 FireRingBgfx_081B4E44[];
extern u8 FireRingBgfx_081B5438[];
extern u8 FireRingBgfx_081B55F4[];
extern u8 FireRingBgfx_081B5850[];
extern u8 FireRingBgfx_081B5E5C[];
extern u8 FireRingBgfx_081B61F4[];
extern u8 FireRingBgfx_081B6450[];
extern u8 FireRingBgfx_081B6A28[];
extern u8 FireRingBgfx_081B6E08[];
extern u8 FireRingBgfx_081B7064[];
extern u8 FireRingBgfx_081B756C[];
extern u8 FireRingBgfx_081B7B88[];
extern u8 FireRingBgfx_081B7DE4[];
extern u8 FireRingBgfx_081B8418[];
extern u8 FireRingBgfx_081B8A84[];
extern u8 FireRingBgfx_081B8CE0[];
extern u8 FireRingBgfx_081B9300[];
extern u8 FireRingBgfx_081B9878[];
extern u8 FireRingBgfx_081B9AD4[];
extern u8 FireRingBgfx_081BA110[];
extern u8 FireRingBgfx_081BA730[];
extern u8 FireRingBgfx_081BA98C[];
extern u8 FireRingBgfx_081BAF4C[];
extern u8 FireRingBgfx_081BB494[];
extern u8 FireRingBgfx_081BB6F0[];
extern u8 FireRingBgfx_081BBD10[];
extern u8 FireRingBgfx_081BC1F0[];
extern u8 FireRingBgfx_081BC44C[];
extern u8 FireRingBgfx_081BC99C[];
extern u8 FireRingBgfx_081BCEF0[];

struct BmBgxConf CONST_DATA BmBgfxConf_DragonFlame[] = {
    { BMFX_CONFT_PAL,        FireRingBgfx_081B3DF4, 0x1, 0 },
    { BMFX_CONFT_ZIMG,       FireRingBgfx_081B3E14, 0x800, 1 },
    { BMFX_CONFT_ZIMG,       FireRingBgfx_081B43E4, 0x800, 1 },
    { BMFX_CONFT_TSA,        FireRingBgfx_081B4730,     0, 1 },
    { BMFX_CONFT_TSA,        FireRingBgfx_081B498C,     0, 3 },
    { BMFX_CONFT_TSA,        FireRingBgfx_081B4BE8,     0, 3 },
    { BMFX_CONFT_ZIMG,       FireRingBgfx_081B4E44, 0x800, 1 },
    { BMFX_CONFT_ZIMG,       FireRingBgfx_081B5438, 0x800, 1 },
    { BMFX_CONFT_TSA,        FireRingBgfx_081B55F4,     0, 1 },
    { BMFX_CONFT_LOOP_START },
    { BMFX_CONFT_ZIMG,       FireRingBgfx_081B5850, 0x800, 1 },
    { BMFX_CONFT_ZIMG,       FireRingBgfx_081B5E5C, 0x800, 1 },
    { BMFX_CONFT_TSA,        FireRingBgfx_081B61F4,     0, 1 },
    { BMFX_CONFT_ZIMG,       FireRingBgfx_081B6450, 0x800, 1 },
    { BMFX_CONFT_ZIMG,       FireRingBgfx_081B6A28, 0x800, 1 },
    { BMFX_CONFT_TSA,        FireRingBgfx_081B6E08,     0, 1 },
    { BMFX_CONFT_ZIMG,       FireRingBgfx_081B7064, 0x800, 1 },
    { BMFX_CONFT_ZIMG,       FireRingBgfx_081B756C, 0x800, 1 },
    { BMFX_CONFT_TSA,        FireRingBgfx_081B7B88,     0, 1 },
    { BMFX_CONFT_ZIMG,       FireRingBgfx_081B7DE4, 0x800, 1 },
    { BMFX_CONFT_ZIMG,       FireRingBgfx_081B8418, 0x800, 1 },
    { BMFX_CONFT_TSA,        FireRingBgfx_081B8A84,     0, 1 },
    { BMFX_CONFT_ZIMG,       FireRingBgfx_081B8CE0, 0x800, 1 },
    { BMFX_CONFT_ZIMG,       FireRingBgfx_081B9300, 0x800, 1 },
    { BMFX_CONFT_TSA,        FireRingBgfx_081B9878,     0, 1 },
    { BMFX_CONFT_ZIMG,       FireRingBgfx_081B9AD4, 0x800, 1 },
    { BMFX_CONFT_ZIMG,       FireRingBgfx_081BA110, 0x800, 1 },
    { BMFX_CONFT_TSA,        FireRingBgfx_081BA730,     0, 1 },
    { BMFX_CONFT_ZIMG,       FireRingBgfx_081BA98C, 0x800, 1 },
    { BMFX_CONFT_ZIMG,       FireRingBgfx_081BAF4C, 0x800, 1 },
    { BMFX_CONFT_TSA,        FireRingBgfx_081BB494,     0, 1 },
    { BMFX_CONFT_LOOP, 0, 0, -1 },
    { BMFX_CONFT_ZIMG,       FireRingBgfx_081BB6F0, 0x800, 1 },
    { BMFX_CONFT_ZIMG,       FireRingBgfx_081BBD10, 0x800, 1 },
    { BMFX_CONFT_TSA,        FireRingBgfx_081BC1F0,     0, 1 },
    { BMFX_CONFT_ZIMG,       FireRingBgfx_081BC44C, 0x800, 1 },
    { BMFX_CONFT_ZIMG,       FireRingBgfx_081BC99C, 0x800, 1 },
    { BMFX_CONFT_TSA,        FireRingBgfx_081BCEF0,      0, 1 },
    { BMFX_CONFT_BREAK },
};
