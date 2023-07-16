#include "global.h"
#include "anime.h"
#include "ekrbattle.h"
#include "efxbattle.h"
#include "hardware.h"
#include "mu.h"
#include "bmudisp.h"
#include "bmmap.h"

struct EfxStatusReConfig {
    u32 index;
    int red;
    int green;
    int blue;
    int speed;
};

extern const struct EfxStatusReConfig EfxUnitDebuffPalConfigTable[];

const s16 EfxStatusUnitTimingLut0[] = {
    0x10, 0x100,
    0xFFFE
};

const s16 EfxStatusUnitTimingLut1[] = {
    0x0,  0x28,
    0x4,  0xC,
    0x8,  0xA,
    0x10, 0x28,
    0xC,  0xC,
    0x8,  0xA,
    0x4,  0xC,
    0xFFFE
};

const s16 EfxStatusUnitTimingLut2[] = {
    0x0,  0x14,
    0x4,  0x6,
    0x8,  0x5,
    0xC,  0x6,
    0x10, 0x14,
    0xC,  0x6,
    0x8,  0x5,
    0x4,  0x6,
    0xFFFE
};

const s16 EfxStatusUnitTimingLut3[] = {
    0x0,  0xA,
    0x4,  0x3,
    0x8,  0x2,
    0xC,  0x3,
    0x10, 0xA,
    0xC,  0x3,
    0x8,  0x2,
    0x4,  0x3,
    0xFFFE
};


s16 const * const EfxStatusUnitFlashTiming[] = {
    EfxStatusUnitTimingLut0,
    EfxStatusUnitTimingLut1,
    EfxStatusUnitTimingLut2,
    EfxStatusUnitTimingLut3
};

void EfxStatusUnitMain(struct ProcEfxStatusUnit *proc)
{
    int ret, speed;
    const struct EfxStatusReConfig *it;

    if (proc->invalid == true)
        return;

    if (proc->debuff != proc->debuf_bak) {
        proc->timer = 0;
        proc->frame = 0;
        proc->debuf_bak = proc->debuff;
    }

    for (it = &EfxUnitDebuffPalConfigTable[0]; it->index != 0xFFFFFFFF; it++)
        if (it->index == proc->debuff)
            break;

    if (it->index == 0xFFFFFFFF)
        return;

    speed = it->speed;
    LIMIT_AREA(speed, 0, 3);

    ret = EfxAdvanceFrameLut (
        (void *)&proc->timer,
        (void *)&proc->frame,
        EfxStatusUnitFlashTiming[speed]
    );

    if (ret > 0) {
        proc->red = it->red * ret / 0x10;
        proc->green = it->green * ret / 0x10;
        proc->blue = it->blue * ret / 0x10;
    }

    switch (proc->debuff) {
    case UNIT_STATUS_PETRIFY:
    case UNIT_STATUS_13:
        if (GetAnimPosition(proc->anim) == EKR_POS_L)
            sub_80715F4(gUnknown_02022B88, gUnknown_020222A8, &gUnknown_020222A8[0x30],
                        &gUnknown_020222A8[0x180], 16, proc->red, 16);
        else
            sub_80715F4(gUnknown_02022BC8, gUnknown_02022308, &gUnknown_02022308[0x30],
                        &gUnknown_02022308[0x2A0], 16, proc->red, 16);

        RefreshEntityBmMaps();
        RefreshUnitSprites();
        MU_EndAll();
        break;

    default:
        EfxStatusUnitSomePalModify(proc->anim, proc->red, proc->green, proc->blue);
        break;
    }

    EnablePaletteSync();
}
