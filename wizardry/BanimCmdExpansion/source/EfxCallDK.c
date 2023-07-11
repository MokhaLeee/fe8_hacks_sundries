#include "global.h"
#include "anime.h"
#include "ekrbattle.h"
#include "efxbattle.h"
#include "ekrdragon.h"
#include "proc.h"
#include "bmlib.h"
#include "hardware.h"

#include "BanimUtils.h"

void EfxCalDkBaseHide(struct ProcEfxBmExpa * proc)
{
    NewEkrDragonBaseHide(proc->anim);
}

void EfxCalDkCustomBgFadeIn(struct ProcEfxBmExpa * proc)
{
    int ret = Interpolate(INTERPOLATE_SQUARE, 4, 0x10, proc->timer, 8);
    EkrUpdateSomePalMaybe(ret);
    if (++proc->timer == 0x9)
    {
        proc->timer = 0;
        Proc_Break(proc);
    }
}

void EfxCalDkMain(struct ProcEfxBmExpa * proc)
{
    if (proc->timer == 0x2)
    {
        SetEkrDragonStatusType(gAnims[0], EKRDRGON_TYPE_DEMON_KING);
        Fill16_EkrTsaBuffer_(1);
        sub_80559D0(0x60016001);
        BG_Fill(gBG3TilemapBuffer, 1);
        BG_EnableSyncByMask(BG3_SYNC_BIT);
        Decompress(Img_DemonKingBG, (void *)0x06008000);
        Decompress(Tsa_DemonKingBG1, gEkrTsaBuffer);
        sub_806FBB8();
        EkrDragonBgSetPostion(gEkrBgXOffset, 0);

        // Some align issue exits for C
        // why ?
        EfxDragonSetBgPriorityASM();

        CpuFastCopy(Pal_DemonKingBG, PAL_BG(6), 0x20);
        EnablePaletteSync();

        SetBlackPal(0x6);
        StartPalFade(Pal_DemonKingBG, 6, 0x78, proc);
    }

    if (++proc->timer == 0x7E)
        Proc_Break(proc);
}

void EfxCalDkOnEnd(struct ProcEfxBmExpa * proc)
{
    struct Anim * anim = proc->anim;
    struct Anim * anim1 = gAnims[GetAnimPosition(anim) * 2];
    struct Anim * anim2 = gAnims[GetAnimPosition(anim) * 2 + 1];

    SetAnimStateUnfrozen(anim);
    SetAnimStateUnfrozen(anim1);
    SetAnimStateUnfrozen(anim2);
}

const struct ProcCmd ProScr_EfxCalDk[] = {
    PROC_NAME("efxCallDK"),
    PROC_YIELD,
    PROC_CALL(EfxCalDkBaseHide),
    PROC_REPEAT(EfxCalDkCustomBgFadeIn),
    PROC_REPEAT(EfxCalDkMain),
    PROC_CALL(EfxCalDkOnEnd),
    PROC_END
};

void NewEfxCalDk(struct Anim * anim)
{
    struct ProcEfxBmExpa * proc;
    struct Anim * anim1, * anim2;
    proc = Proc_Start(ProScr_EfxCalDk, PROC_TREE_3);
    proc->anim = anim;
    proc->timer = 0;

    anim1 = gAnims[GetAnimPosition(anim) * 2];
    anim2 = gAnims[GetAnimPosition(anim) * 2 + 1];

    SetAnimStateFrozen(anim);
    SetAnimStateFrozen(anim1);
    SetAnimStateFrozen(anim2);
}

void BanimCmd_CallDK(struct Anim * anim)
{
    if (!(anim->state3 & ANIM_BIT3_BLOCKING))
    {
        anim->state3 |= ANIM_BIT3_BLOCKING;
        if (GetAISLayerId(anim) == 0)
            NewEfxCalDk(anim);
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
