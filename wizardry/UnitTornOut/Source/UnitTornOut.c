#include "gbafe.h"

void UnitTornOutExt(ProcPtr parent)
{
    sub_80859D0(gActiveUnit, parent);
}

static const struct ProcCmd ProcScr_UnitTornOut[] = {
    PROC_CALL(UnitTornOutExt),
    PROC_SLEEP(64),
    PROC_END
};

void StartUnitTornOut(ProcPtr parent)
{
    if (parent)
        Proc_StartBlocking(ProcScr_UnitTornOut, parent);
    else
        Proc_Start(ProcScr_UnitTornOut, PROC_TREE_3);
}
