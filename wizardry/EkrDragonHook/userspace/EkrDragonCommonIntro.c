#include "global.h"
#include "../core/EkrDragonRework.h"
#include "proc.h"
#include "hardware.h"
#include "banim_data.h"
#include "ekrbattle.h"
#include "efxbattle.h"
#include "ekrdragon.h"

struct ProcEkrDragonCommonIntro {
    struct ProcEkrDragon drgproc;
    u8 fbanim_intro;
    u8 fbanim_main;
    u8 fbanim_exit;
};

void EkrDragReComm_PrepareBanimfx(struct ProcEkrDragonCommonIntro *proc)
{
    struct Anim *anim = proc->drgproc.anim;
    proc->drgproc.timer = 0;

    EkrPrepareBanimfx(anim, proc->fbanim_intro);
    BanimPrepareSpecificScript(anim, 0);
    LZ77UnCompWram(banim_data[proc->fbanim_intro].pal, gPalBackupEkrUnitMaybe);

    if (GetAISSubjectId(anim) == EKR_BATTLE_LEFT)
        CpuFastCopy(gPalBackupEkrUnitMaybe, PAL_OBJ(0x7), 0x40);
    else
        CpuFastCopy(gPalBackupEkrUnitMaybe, PAL_OBJ(0x9), 0x40);

    EnablePaletteSync();
    Proc_Break(proc);
}

void EkrDragReComm_WaitForTransform(struct ProcEkrDragonCommonIntro *proc)
{
    struct Anim *anim = proc->drgproc.anim;

    if (++proc->drgproc.timer == 0x1A) {
        SomePlaySound_8071990(0xDC, 0x100);
        M4aPlayWithPostionCtrl(0xDC, anim->xPosition, 1);
    }

    if (ANINS_GET_TYPE(*anim->pScrCurrent) == ANIM_INS_TYPE_STOP) {
        SomePlaySound_8071990(0xDE, 0x100);
        M4aPlayWithPostionCtrl(0xDE, anim->xPosition, 1);
        EkrPrepareBanimfx(anim, proc->fbanim_main);

        proc->drgproc.timer = 0;
        Proc_Break(proc);
    }
}

void EkrDragReComm_OnBanimExit(struct ProcEkrDragonCommonIntro *proc)
{
    struct Anim *anim = proc->drgproc.anim;
    BattleAnim *banim = banim_data;

#if 0
    if (GetEfxHp(2 * gEfxPairHpBufOffset[GetAISSubjectId(anim)] + GetAISSubjectId(anim)) <= 0) {
        proc->drgproc.timer = 0;
        EkrPrepareBanimfx(anim, 0xC7 - 1);
        gEkrSpellAnimIndexLutMaybe[0] = -1;
        Proc_Break(proc);
        return;
    }
#endif

    SomePlaySound_8071990(0xDD, 0x100);
    M4aPlayWithPostionCtrl(0xDD, anim->xPosition, 1);

    EkrPrepareBanimfx(anim, proc->fbanim_exit);
    BanimPrepareSpecificScript(anim, 0);
    Proc_Break(proc);
    LZ77UnCompWram(banim[proc->fbanim_exit].pal, gPalBackupEkrUnitMaybe);

    if (GetAISSubjectId(anim) == EKR_BATTLE_LEFT)
        CpuFastCopy(gPalBackupEkrUnitMaybe, PAL_OBJ(0x7), 0x40);
    else
        CpuFastCopy(gPalBackupEkrUnitMaybe, PAL_OBJ(0x9), 0x40);

    EnablePaletteSync();
}

void EkrDragReComm_OnEkrExit(struct ProcEkrDragonCommonIntro *proc)
{
    struct Anim *anim = proc->drgproc.anim;
    if (ANINS_GET_TYPE(*anim->pScrCurrent) == ANIM_INS_TYPE_STOP) {
        EkrPrepareBanimfx(anim, proc->fbanim_exit);
        AddEkrDragonStatusAttr(proc->drgproc.anim, EKRDRGON_ATTR_END);

        if (GetAISSubjectId(anim) == EKR_BATTLE_LEFT)
            SetEkrDragonStatusType(gAnims[0], EKRDRGON_TYPE_NORMAL);
        else
            SetEkrDragonStatusType(gAnims[2], EKRDRGON_TYPE_NORMAL);

        Proc_Break(proc);
    }
}

const struct ProcCmd ProScr_EkrDragonReworkCommonIntro[] = {
    PROC_SLEEP(0x3C),
    PROC_REPEAT(EkrDragReComm_PrepareBanimfx),
    PROC_REPEAT(EkrDragReComm_WaitForTransform),

PROC_LABEL(0),
    PROC_REPEAT(EkrMyr_TrigerForPrepared),
    PROC_REPEAT(EkrMyr_InBattleIdle),

    PROC_REPEAT(EkrDragReComm_OnBanimExit),
    PROC_REPEAT(EkrDragReComm_OnEkrExit),
    PROC_END,
};

void EkrDragonCommonIntro(struct Anim *anim, u32 priv)
{
    struct EkrDragonFrameLut _priv = {
        .fbanim_intro = (priv & 0xFF),
        .fbanim_main = ((priv >> 8) & 0xFF),
        .fbanim_exit = ((priv >> 16) & 0xFF),
    };

    struct EkrDragonStatus *ekrsp = GetEkrDragonStatus(anim);
    struct ProcEkrDragonCommonIntro *proc = Proc_Start(ProScr_EkrDragonReworkCommonIntro, PROC_TREE_3);

    ekrsp->proc = proc;
    AddEkrDragonStatusAttr(anim, EKRDRGON_ATTR_START);
    ekrsp->anim = anim;
    proc->drgproc.anim = anim;
    proc->drgproc.timer = 0;

    proc->fbanim_intro = _priv.fbanim_intro;
    proc->fbanim_main = _priv.fbanim_main;
    proc->fbanim_exit = _priv.fbanim_exit;
}
