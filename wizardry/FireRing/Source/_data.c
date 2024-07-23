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

struct BmBgxConf const BmBgfxConf_DragonFlame[] = {
    {
        .type = BMFX_CONFT_PAL,
        .data = FireRingBgfx_081B3DF4,
        .size = 0x0001,
        .duration = 0,
    },
    {
        .type = BMFX_CONFT_ZIMG,
        .data = FireRingBgfx_081B3E14,
        .size = 0x0800,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_ZIMG,
        .data = FireRingBgfx_081B43E4,
        .size = 0x0800,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_TSA,
        .data = FireRingBgfx_081B4730,
        .size =      0,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_TSA,
        .data = FireRingBgfx_081B498C,
        .size =      0,
        .duration = 3,
    },
    {
        .type = BMFX_CONFT_TSA,
        .data = FireRingBgfx_081B4BE8,
        .size =      0,
        .duration = 3,
    },
    {
        .type = BMFX_CONFT_ZIMG,
        .data = FireRingBgfx_081B4E44,
        .size = 0x0800,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_ZIMG,
        .data = FireRingBgfx_081B5438,
        .size = 0x0800,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_TSA,
        .data = FireRingBgfx_081B55F4,
        .size =      0,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_LOOP_START,
    },
    {
        .type = BMFX_CONFT_ZIMG,
        .data = FireRingBgfx_081B5850,
        .size = 0x0800,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_ZIMG,
        .data = FireRingBgfx_081B5E5C,
        .size = 0x0800,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_TSA,
        .data = FireRingBgfx_081B61F4,
        .size =      0,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_ZIMG,
        .data = FireRingBgfx_081B6450,
        .size = 0x0800,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_ZIMG,
        .data = FireRingBgfx_081B6A28,
        .size = 0x0800,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_TSA,
        .data = FireRingBgfx_081B6E08,
        .size =      0,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_ZIMG,
        .data = FireRingBgfx_081B7064,
        .size = 0x0800,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_ZIMG,
        .data = FireRingBgfx_081B756C,
        .size = 0x0800,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_TSA,
        .data = FireRingBgfx_081B7B88,
        .size =      0,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_ZIMG,
        .data = FireRingBgfx_081B7DE4,
        .size = 0x0800,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_ZIMG,
        .data = FireRingBgfx_081B8418,
        .size = 0x0800,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_TSA,
        .data = FireRingBgfx_081B8A84,
        .size =      0,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_ZIMG,
        .data = FireRingBgfx_081B8CE0,
        .size = 0x0800,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_ZIMG,
        .data = FireRingBgfx_081B9300,
        .size = 0x0800,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_TSA,
        .data = FireRingBgfx_081B9878,
        .size =      0,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_ZIMG,
        .data = FireRingBgfx_081B9AD4,
        .size = 0x0800,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_ZIMG,
        .data = FireRingBgfx_081BA110,
        .size = 0x0800,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_TSA,
        .data = FireRingBgfx_081BA730,
        .size =      0,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_ZIMG,
        .data = FireRingBgfx_081BA98C,
        .size = 0x0800,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_ZIMG,
        .data = FireRingBgfx_081BAF4C,
        .size = 0x0800,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_TSA,
        .data = FireRingBgfx_081BB494,
        .size =      0,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_LOOP,
        .duration = 255,
    },
    {
        .type = BMFX_CONFT_ZIMG,
        .data = FireRingBgfx_081BB6F0,
        .size = 0x0800,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_ZIMG,
        .data = FireRingBgfx_081BBD10,
        .size = 0x0800,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_TSA,
        .data = FireRingBgfx_081BC1F0,
        .size =      0,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_ZIMG,
        .data = FireRingBgfx_081BC44C,
        .size = 0x0800,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_ZIMG,
        .data = FireRingBgfx_081BC99C,
        .size = 0x0800,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_TSA,
        .data = FireRingBgfx_081BCEF0,
        .size =      0,
        .duration = 1,
    },
    {
        .type = BMFX_CONFT_BREAK,
    },
    { BMFX_CONFT_BREAK },
};
