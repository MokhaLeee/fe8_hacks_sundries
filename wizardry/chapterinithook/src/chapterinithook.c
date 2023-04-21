#include "global.h"

void BmMain_StartIntroFx(ProcPtr proc);

void ChapterInitHook(ProcPtr proc)
{
    BmMain_StartIntroFx(proc);
}
