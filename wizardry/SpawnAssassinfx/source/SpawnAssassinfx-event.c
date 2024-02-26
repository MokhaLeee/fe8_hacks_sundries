#include "gbafe.h"

void StartSpawnAssassinfx(ProcPtr proc, int x, int y);

void CallEvent_SpawnAssassinfx(struct EventEngineProc * proc)
{
    int x, y;
    x = gEventSlots[3] * 16 - gBmSt.camera.x;
    y = gEventSlots[4] * 16 - gBmSt.camera.y;

    StartSpawnAssassinfx(proc, x, y);
}
