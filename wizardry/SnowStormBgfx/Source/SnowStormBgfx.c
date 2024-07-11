#include "gbafe.h"

extern u8 Img_EventSnowStormfx[];
extern u16 Pal_EventSnowStormfx[];
extern u8 Tsa_EventSnowStormfx[];

struct ProcEventSnowStormfx {
    PROC_HEADER;

    /* 2C */ int paluse_duration;
    /* 30 */ int timer;
    /* 34 */ int bg_offset;

    STRUCT_PAD(0x38, 0x3C);

    /* 3C */ int x, y;
};

static void EventSnowStormfx_Init(struct ProcEventSnowStormfx * proc)
{
    SetBlendAlpha(0x0, 0x10);
    SetBlendTargetA(0, 0, 1, 0, 0);
    SetBlendTargetB(0, 0, 0, 1, 1);

    Decompress(Img_EventSnowStormfx, (void *)BG_VRAM + 0x1000);
    ApplyPalette(Pal_EventSnowStormfx, 15);
    CallARM_FillTileRect(gBG2TilemapBuffer, Tsa_EventSnowStormfx, 0xF080);
    BG_EnableSyncByMask(BG2_SYNC_BIT);

    StartMixPalette(
        Pal_EventSnowStormfx,
        Pal_EventSnowStormfx + 0x10,
        0x20,
        15,
        1,
        proc
    );

    proc->timer = 0;
    proc->bg_offset = 0x20;

    proc->x = 0;
    proc->y = 0;

    BG_SetPosition(2, 0, 0);
}

static void EventSnowStormfx_Loop1(struct ProcEventSnowStormfx * proc)
{
    int bg_offset, time = ++proc->timer >> 1;

    SetBlendAlpha(time, (0x10 - time) >= 0xD ? 0x10 - time : 0xD);

    if (time == 0x10)
    {
        proc->timer = 0;
        Proc_Break(proc);
    }

    bg_offset = ++proc->bg_offset;

    proc->x += bg_offset * 3;
    proc->y += bg_offset;

    BG_SetPosition(BG_2, -(proc->x >> 5), -(proc->y >> 5));
}

static void EventSnowStormfx_Loop2(struct ProcEventSnowStormfx * proc)
{
    int bg_offset;

    if (++proc->timer >= proc->paluse_duration)
    {
        proc->timer = 0;
        Proc_Break(proc);
    }

    bg_offset = proc->bg_offset;
    proc->x += bg_offset * 3;
    proc->y += bg_offset;

    BG_SetPosition(BG_2, -(proc->x >> 5), -(proc->y >> 5));
}

static void EventSnowStormfx_Loop3(struct ProcEventSnowStormfx * proc)
{
    int bg_offset, time = ++proc->timer >> 3;

    SetBlendAlpha(0x10 - time, (time + 0xD) >= 0x10 ? 0x10 : time + 0xD);

    bg_offset = proc->bg_offset;
    proc->x += bg_offset * 3;
    proc->y += bg_offset;

    BG_SetPosition(BG_2, -(proc->x >> 5), -(proc->y >> 5));

    if (time == 0x10)
        Proc_Break(proc);
}

static void EventSnowStormfx_End(struct ProcEventSnowStormfx * proc)
{
    BG_Fill(gBG2TilemapBuffer, 0);
    BG_EnableSync(BG2_SYNC_BIT);
    SetBlendConfig(BLEND_EFFECT_NONE, 0, 0x10, 0);
}

static struct ProcCmd CONST_DATA ProcScr_EventSnowStormfx[] = {
    PROC_YIELD,
    PROC_CALL(EventSnowStormfx_Init),
    PROC_YIELD,
    PROC_REPEAT(EventSnowStormfx_Loop1),
    PROC_REPEAT(EventSnowStormfx_Loop2),
    PROC_REPEAT(EventSnowStormfx_Loop3),
    PROC_CALL(EventSnowStormfx_End),
    PROC_END,
};

void StartSnowStormfx(ProcPtr proc)
{
    struct ProcEventSnowStormfx * procfx;
    procfx = Proc_StartBlocking(ProcScr_EventSnowStormfx, proc);
    procfx->paluse_duration = 60;
}
