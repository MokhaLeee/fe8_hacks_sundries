#include "global.h"
#include "bmunit.h"
#include "proc.h"
#include "playerphase.h"

void PlayerPhase_CancelAction(ProcPtr proc);

struct PreActionCancelConf {
    u8 action, bm_mask;
};

extern struct PreActionCancelConf const * const gpPreActionCancelTable;

bool PreActionRework(ProcPtr proc)
{
    u8 * taken_action = &gBmSt.unk3D/* &gBmSt.taken_action */;
    const struct PreActionCancelConf * it;

    if (gActionData.unitActionType == 0 && *taken_action != 0)
        goto vanilla;

    for (it = gpPreActionCancelTable; it->action != 0; it++)
    {
        if (gActionData.unitActionType != it->action)
            continue;

        *taken_action |= it->bm_mask;
        PlayerPhase_CancelAction(proc);
        return true;
    }

vanilla:
    return PlayerPhase_PrepareAction(proc);
}
