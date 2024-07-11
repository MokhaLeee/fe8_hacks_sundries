#include "gbafe.h"

void UnitTornOutExt(ProcPtr parent)
{
    StartUnitTornOut(gActiveUnit, parent);
}

static const struct ProcCmd ProcScr_EventUnitTornOut[] = {
    PROC_CALL(UnitTornOutExt),
    PROC_SLEEP(64),
    PROC_END
};

void EventStartUnitTornOut(ProcPtr parent)
{
    if (parent)
        Proc_StartBlocking(ProcScr_EventUnitTornOut, parent);
    else
        Proc_Start(ProcScr_EventUnitTornOut, PROC_TREE_3);
}
