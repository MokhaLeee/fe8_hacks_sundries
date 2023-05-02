#include "global.h"
#include "EkrDragonRework.h"
#include "ekrbattle.h"
#include "efxbattle.h"
#include "ekrdragon.h"

void ekrBattlePostEkrDragonIntro(struct ProcEkrBattle *proc);

struct EkrDragonHandler *GetEkrDragonReworkHandler(struct BattleUnit *bu)
{
    struct EkrDragonHandler *it;

    for (it = EkrDragonSpecialRountineHook; it->class != 0; it++) {
        if (it->type != 0 && it->intro) {
            if (it->class == bu->unit.pClassData->number)
                return it;
        }
    }

    return NULL;
}

void EkrSetupDragonStatusReworkInternal(void)
{
    struct EkrDragonHandler *it;

    it = GetEkrDragonReworkHandler(gpEkrBattleUnitLeft);
    if (it)
        SetEkrDragonStatusType(gAnims[0], it->type);

    it = GetEkrDragonReworkHandler(gpEkrBattleUnitRight);
    if (it) {
        /* It's better not to enable ally DemonKing and DrazoDragon banim */
        if (!(it->config & EKRDRAGON_CONFIG_UNIQUE_INTRO))
            SetEkrDragonStatusType(gAnims[2], it->type);
    }
}

/* 0x8070B3C */
void EkrSetupDragonStatusRework(void)
{
    switch (gEkrDistanceType) {
    case 0:
    case 1:
    case 2:
        EkrSetupDragonStatusReworkInternal();
        break;
    
    default:
        break;
    }
}

void ekrBattleDoSpeialClassIntroRework(struct ProcEkrBattle *proc)
{
    struct EkrDragonHandler *it;

    if (proc->counter == 2) {
        proc->proc_idleCb = (ProcFunc)ekrBattlePostEkrDragonIntro;
        return;
    }

    if (proc->side == EKR_BATTLE_LEFT) {
        proc->anim = gAnims[EKR_BATTLE_LEFT * 2];
        it = GetEkrDragonReworkHandler(gpEkrBattleUnitLeft);
        if (GetEkrDragonStatusType(proc->anim) && it->class != 0) {
            it->intro(proc->anim, it->priv);
            proc->proc_idleCb = (ProcFunc)ekrBattleWaitSpeialClassIntroAnimIdle;
        }

        proc->side = EKR_BATTLE_RIGHT;
    } else {
        proc->anim = gAnims[EKR_BATTLE_RIGHT * 2];
        it = GetEkrDragonReworkHandler(gpEkrBattleUnitRight);
        if (GetEkrDragonStatusType(proc->anim) && it->class != 0) {
            it->intro(proc->anim, it->priv);
            proc->proc_idleCb = (ProcFunc)ekrBattleWaitSpeialClassIntroAnimIdle;
        }

        proc->side = EKR_BATTLE_LEFT;
    }

    proc->counter++;
}
