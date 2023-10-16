#include "global.h"
#include "bmbattle.h"
#include "mu.h"
#include "bmudisp.h"
#include "bmmap.h"
#include "bmbattle-chax.h"
#include "post-action.h"
#include "manims.h"

/* HideUnitSMS */
void sub_8028100(void);

void PostActionExecInoriItem(struct ProcPostAction *proc)
{
    struct Unit *unit = GetUnit(*gpBmBattleInoriPid);

    if (*gpBmBattleGlobalFlag & CHAX_BMBATTLE_GLBFLG_INORI_ITEM_ACTIVE && unit) {
        SetUnitHp(unit, GetUnitMaxHp(unit));

        // MU_End(MU_GetByUnit(&gBattleTarget.unit));
	    // RefreshUnitSprites();
	    ExecManim_up(proc, unit);
    }

    /* Clear bitfile */
    *gpBmBattleInoriPid = 0;
    *gpBmBattleGlobalFlag &= ~CHAX_BMBATTLE_GLBFLG_INORI_ITEM_ACTIVE;
}
