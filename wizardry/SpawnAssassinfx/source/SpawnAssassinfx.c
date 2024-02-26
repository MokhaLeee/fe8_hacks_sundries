#include "gbafe.h"

extern const u8 Img_EventSpriteAnim_SpawnAssassin[];
extern const u8 ApConf_EventSpriteAnim_SpawnAssassin[];

const struct EventSpriteAnimConf EventSpriteAnimConf_SpawnAssassin = {
    .pal = NULL,
    .img = Img_EventSpriteAnim_SpawnAssassin,
    .ap_conf = ApConf_EventSpriteAnim_SpawnAssassin,
    .oam0 = 0x0000,
    .oam2 = 0x0200,
    .pal_bank = 0xB,
    .pal_size = 1
};

void StartSpawnAssassinfx(ProcPtr proc, int x, int y)
{
    struct ProcEventSpriteAnim * procfx;
    if (proc)
        procfx = Proc_StartBlocking(ProcScr_EventSpriteAnim, proc);
    else
        procfx = Proc_Start(ProcScr_EventSpriteAnim, PROC_TREE_3);

    procfx->x = x;
    procfx->y = y;
    procfx->priv = &EventSpriteAnimConf_SpawnAssassin;
}
