#include "global.h"
#include "anime.h"
#include "ekrbattle.h"
#include "efxbattle.h"
#include "ekrdragon.h"
#include "proc.h"
#include "bmlib.h"
#include "hardware.h"

#include "BanimUtils.h"

void EfxCalDumaBaseHide(struct ProcEfxBmExpa * proc)
{
    NewEkrDragonBaseHide(proc->anim);
}

void EfxCalDumaCustomBgFadeIn(struct ProcEfxBmExpa * proc)
{
    int ret = Interpolate(INTERPOLATE_SQUARE, 4, 0x10, proc->timer, 8);
    EkrUpdateSomePalMaybe(ret);
    if (++proc->timer == 0x9)
    {
        proc->timer = 0;
        Proc_Break(proc);
    }
}

void EfxCalDumaPrepare(struct ProcEfxBmExpa * proc)
{
    SetEkrDragonStatusType(gAnims[0], EKRDRGON_TYPE_DEMON_KING);
    // EkrDragonBgSetPostion(gEkrBgXOffset, 0);
    EfxDragonSetBgPriorityASM(0, 1, 3, 2);
}

void EfxCalDumaMain(struct ProcEfxBmExpa * proc)
{
    if (proc->timer == 0x2)
    {
        Fill16_EkrTsaBuffer_(1);
        sub_80559D0(0x60016001);
        BG_Fill(gBG3TilemapBuffer, 1);
        BG_EnableSyncByMask(BG3_SYNC_BIT);
        Decompress(ImgLut_Duma[13], (void *)0x06008000);
        Decompress(TsaLut_Duma[13], gEkrTsaBuffer);
        sub_806FBB8();

        CpuFastCopy(PalLut_Duma[13], PAL_BG(6), 0x20);
        EnablePaletteSync();
    }

    if (++proc->timer == 0x7E)
        Proc_Break(proc);
}

void EfxCalDumaOnEnd(struct ProcEfxBmExpa * proc)
{
    struct Anim * anim = proc->anim;
    struct Anim * anim1 = gAnims[GetAnimPosition(anim) * 2];
    struct Anim * anim2 = gAnims[GetAnimPosition(anim) * 2 + 1];

    SetAnimStateUnfrozen(anim);
    SetAnimStateUnfrozen(anim1);
    SetAnimStateUnfrozen(anim2);
}

const struct ProcCmd ProScr_EfxCalDuma[] = {
    PROC_NAME("efxCallDuma"),
    PROC_YIELD,
    PROC_CALL(EfxCalDumaBaseHide),
    PROC_REPEAT(EfxCalDumaCustomBgFadeIn),
    PROC_REPEAT(EfxCalDumaMain),
    PROC_CALL(EfxCalDumaOnEnd),
    PROC_END
};

void NewEfxCalDuma(struct Anim * anim)
{
    struct ProcEfxBmExpa * proc;
    struct Anim * anim1, * anim2;
    proc = Proc_Start(ProScr_EfxCalDuma, PROC_TREE_3);
    proc->anim = anim;
    proc->timer = 0;

    anim1 = gAnims[GetAnimPosition(anim) * 2];
    anim2 = gAnims[GetAnimPosition(anim) * 2 + 1];

    SetAnimStateFrozen(anim);
    SetAnimStateFrozen(anim1);
    SetAnimStateFrozen(anim2);
}

void BanimCmd_CallDuma(struct Anim * anim)
{
    anim->pScrCurrent = anim->pScrCurrent - 1;

    if (!(anim->state3 & ANIM_BIT3_BLOCKING))
    {
        anim->state3 |= ANIM_BIT3_BLOCKING;
        if (GetAISLayerId(anim) == 0)
            NewEfxCalDuma(anim);
    }
    else
    {
        if (anim->state3 & ANIM_BIT3_BLOCKEND)
        {
            anim->state3 &= ~ANIM_BIT3_BLOCKING;
            anim->state3 &= ~ANIM_BIT3_BLOCKEND;
            anim->pScrCurrent = anim->pScrCurrent + 1;
        }
    }
}
