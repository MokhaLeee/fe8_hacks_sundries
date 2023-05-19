#include "global.h"
#include "proc.h"

int BmMain_UpdateTraps(ProcPtr proc);
void PrePhaseUseBuffItem(void);

int PostPhaseHook(ProcPtr proc)
{
    PrePhaseUseBuffItem();
    return BmMain_UpdateTraps(proc);
}
