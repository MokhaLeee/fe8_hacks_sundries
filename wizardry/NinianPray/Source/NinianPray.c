#include "gbafe.h"

extern const u16 Pal_NinianPrayfx[];
extern const u8 Img_NinianPrayfx[];
extern const u8 SpritAnim_NinianPrayfx[];

const struct EventSpriteAnimConf EventSpriteAnimConf_NinianPray = {
    .pal = Pal_NinianPrayfx,
    .img = Img_NinianPrayfx,
    .ap_conf = SpritAnim_NinianPrayfx,
    .oam0 = 0x0000,
    .oam2 = 0x0280,
    .pal_bank = 5,
    .pal_size = 1
};

void StartNinianPrayfx(ProcPtr proc, int x, int y)
{
    struct ProcEventSpriteAnim * procfx;
    if (proc)
        procfx = Proc_StartBlocking(ProcScr_EventSpriteAnim, proc);
    else
        procfx = Proc_Start(ProcScr_EventSpriteAnim, PROC_TREE_3);

    procfx->x = x;
    procfx->y = y;
    procfx->priv = &EventSpriteAnimConf_NinianPray;
}

void CallEvent_NinianPrayfx(struct EventEngineProc * proc)
{
    int x, y;
    x = gEventSlots[3] * 16 - gBmSt.camera.x;
    y = gEventSlots[4] * 16 - gBmSt.camera.y;

    StartNinianPrayfx(proc, x, y);
}
