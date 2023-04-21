#include "global.h"
#include "proc.h"
#include "bmmap.h"

extern u8 *gpRemoveCounter;
void ResetRemoveSkillCounter(void)
{
    *gpRemoveCounter = 0;
}

void PlayerPhaseHook(ProcPtr proc)
{
    ResetRemoveSkillCounter();
    RefreshEntityBmMaps();
}
