#include "gbafe.h"

extern u8 Img_SwingSword[];
extern u16 Pal_SwingSword[];
extern u8 Tsa_SwingSword[];

static void SwingSwordfx_Init(struct ProcBmFx * proc)
{
    int i;
    for (i = 0x21; i <= 0x2F; i++)
        gPaletteBuffer[i] = RGB_WHITE;

    gPaletteBuffer[0] = RGB_WHITE;

    EnablePaletteSync();
    proc->counter = 0;
}

static void SwingSwordfx_Loop(struct ProcBmFx * proc)
{
    int i;
    static const u16 pals[] = {
        RGB_WHITE, RGB_WHITE, RGB_WHITE, RGB_WHITE,
        RGB_WHITE, RGB_WHITE, RGB_WHITE, RGB_WHITE,
        RGB_WHITE, RGB_WHITE, RGB_WHITE, RGB_WHITE,
        RGB_WHITE, RGB_WHITE, RGB_WHITE, RGB_WHITE,
        RGB_WHITE, RGB_WHITE, RGB_WHITE,
        RGB(27, 27, 31),
        RGB(23, 23, 31),
        RGB(15, 15, 31),
        RGB(8, 8, 31),
        RGB(5, 5, 21),
        RGB(2, 2, 10),
        RGB_BLACK, RGB_BLACK, RGB_BLACK,
        RGB_BLACK, RGB_BLACK, RGB_BLACK, RGB_BLACK,
        RGB_BLACK, RGB_BLACK, RGB_BLACK, RGB_BLACK,
        RGB_BLACK, RGB_BLACK, RGB_BLACK, RGB_BLACK,
    };

    gPaletteBuffer[0] = 0;

    for (i = 1; i <= 0xF; i++)
    {
        gPaletteBuffer[0x30 - i] = pals[proc->counter + i - 1];
    }

    EnablePaletteSync();

    proc->counter += 3;
    if (proc->counter > 12)
        Proc_Break(proc);
}

static void SwingSwordfx_End(struct ProcBmFx * proc)
{
    SetDispEnable(1, 1, 1, 1, 1);
    ClearBg0Bg1();
}

static const struct ProcCmd ProcScr_SwingSwordfx[] = {
    PROC_CALL(SwingSwordfx_Init),
    PROC_SLEEP(6),
    PROC_REPEAT(SwingSwordfx_Loop),
    PROC_CALL(StartMidFadeFromBlack),
    PROC_REPEAT(WaitForFade),
    PROC_CALL(SwingSwordfx_End),
    PROC_END,
};

void StartSwingSwordfx(ProcPtr proc)
{
    Decompress(Img_SwingSword, (void *)BG_VRAM + 0x5000);
    ApplyPalette(Pal_SwingSword, 2);
    Decompress(Tsa_SwingSword, gGenericBuffer);
    CallARM_FillTileRect(gBG0TilemapBuffer + 2, gGenericBuffer, 0x2280);
    BG_EnableSyncByMask(BG0_SYNC_BIT);

    SetDispEnable(1, 0, 0, 0, 0);
    SetBlendBrighten(0);
    SetBlendTargetA(0, 0, 0, 0, 0);
    SetBlendTargetB(0, 0, 0, 0, 0);

    Proc_StartBlocking(ProcScr_SwingSwordfx, proc);
}

