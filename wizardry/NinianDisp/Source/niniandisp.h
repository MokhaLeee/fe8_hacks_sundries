#pragma once

#include "gbafe.h"

enum
{
    BGPAL_NINIANDISP = 0x0F,
    OBPAL_NINIANDISP = 0x05,
    OBCHR_NINIANDISP = 0x40,
};

struct ProcNinianAppear {
    PROC_HEADER;

    /* 2C */ int unk2C;
    /* 30 */ int timer;

    STRUCT_PAD(0x34, 0x3C);

    /* 3C */ int x, y;
    /* 44 */ ProcPtr approc[8];
};

void NinianAppear_Init(struct ProcNinianAppear * proc);
void NinianDisp_FadeIn_Unused(struct ProcNinianAppear * proc);
void NinianDisp_FadeOut_Unused(struct ProcNinianAppear * proc);
void NinianDisp_AnimLoopEnd_Unused(struct ProcNinianAppear * proc);
void NinianAppear_Anim1(struct ProcNinianAppear * proc);
void NinianAppear_LoopAnim1(struct ProcNinianAppear * proc);
void NinianAppear_EndAnim1(struct ProcNinianAppear * proc);
void NinianAppear_Anim2(struct ProcNinianAppear * proc);
void NinianAppear_LoadUnit(struct ProcNinianAppear * proc);
void NinianAppear_End(struct ProcNinianAppear * proc);

extern struct ProcCmd const ProcScr_NinianAppearfx[];

extern u8 Img_NinianDispfx[];
extern u16 Pal_NinianDispfx[];
extern u16 SpritAnim_NinianDispfx[];
extern u8 gUnk_081AD68C[];
extern u8 gUnk_081AD6AC[];
extern u8 gUnk_081ADE60[];
extern u8 gUnk_081AE528[];
extern u8 gUnk_081AE64C[];
extern u8 gUnk_081AE770[];
extern u8 gUnk_081AE894[];
extern u8 gUnk_081AE9B8[];
extern u8 gUnk_081AEADC[];
extern u8 gUnk_081AEC00[];
extern u8 gUnk_081AED24[];
extern u8 gUnk_081AF718[];
extern u8 gUnk_081B0044[];
extern u8 gUnk_081B0168[];
extern u8 gUnk_081B028C[];
extern u8 gUnk_081B03B0[];
extern u8 gUnk_081B04D4[];
extern u8 gUnk_081B05F8[];
extern u8 gUnk_081B10CC[];
extern u8 gUnk_081B1660[];
extern u8 gUnk_081B1784[];
extern u8 gUnk_081B18A8[];
extern u8 gUnk_081B19CC[];
extern u8 gUnk_081B23C8[];
extern u8 gUnk_081B2AD8[];
extern u8 gUnk_081B2BFC[];
extern u8 gUnk_081B2D20[];
extern u8 gUnk_081B2E44[];
extern u8 gUnk_081B36D8[];
extern u8 gUnk_081B3A88[];
extern u8 gUnk_081B3BAC[];
extern u8 gUnk_081B3CD0[];
