#include "gbafe.h"
#include "CustomOpAnim.h"

void CustomOpAnim_Init(struct ProcCustomOpAnim * proc)
{
    Sound_FadeOutBGM(SONG_01);
    SetupBackgrounds(NULL);
    SetPrimaryHBlankHandler(NULL);

    gLCDControlBuffer.dispcnt.mode = 0;

    SetBackgroundTileDataOffset(BG_0, 0x0000);
    SetBackgroundTileDataOffset(BG_1, 0x4000);
    SetBackgroundTileDataOffset(BG_2, 0x8000);
    SetBackgroundTileDataOffset(BG_3, 0x0000);

    SetBackgroundMapDataOffset(BG_0, 0xD800);
    SetBackgroundMapDataOffset(BG_1, 0xE800);
    SetBackgroundMapDataOffset(BG_2, 0xF000);
    SetBackgroundMapDataOffset(BG_3, 0xF800);

    SetBackgroundScreenSize(BG_0, 0);
    SetBackgroundScreenSize(BG_1, 0);
    SetBackgroundScreenSize(BG_2, 0);
    SetBackgroundScreenSize(BG_3, 0);

    BG_SetPosition(BG_0, 0, 0);
    BG_SetPosition(BG_1, 0, 0);
    BG_SetPosition(BG_2, 0, 0);
    BG_SetPosition(BG_3, 0, 0);

    gLCDControlBuffer.bg0cnt.priority = 0;
    gLCDControlBuffer.bg1cnt.priority = 1;
    gLCDControlBuffer.bg2cnt.priority = 2;
    gLCDControlBuffer.bg3cnt.priority = 3;

    SetDispEnable(0, 0, 0, 1, 0);
    SetBlendConfig(1, 0x10, 0x10, 0);
    SetBlendTargetA(0, 1, 0, 0, 0);
    SetBlendTargetB(0, 0, 1, 1, 1);
    SetWinEnable(1, 0, 0);
    SetWin0Box(0, 0, 0xF0, 0xA0);
    SetWin0Layers(1, 1, 1, 1, 1);
    SetWOutLayers(1, 0, 1, 1, 1);

    gLCDControlBuffer.wincnt.win0_enableBlend = 1;
    gLCDControlBuffer.wincnt.wout_enableBlend = 0;
    gLCDControlBuffer.bldcnt.target2_bd_on = 1;

    proc->timer = 0;
    proc->frame = 0;

    CpuFastFill16(0xFFFF, OBJ_VRAM0 + 0x7800, 0x800);
    SetNextGameActionId(GAME_ACTION_PLAYED_THROUGH);
    NewOpAnimfxTerminator(proc);
}

void CustomOpAnim_Initfx(struct ProcCustomOpAnim * proc)
{
    proc->imgs = gpOpAnimFrames->imgs;
    proc->pals = gpOpAnimFrames->pals;
    proc->tsas = gpOpAnimFrames->tsas;
    proc->frames = gpOpAnimFrames->frame_confs;

    StartBgmExt(SONG_01, 0, NULL);
}

void CustomOpAnim_Loop(struct ProcCustomOpAnim * proc)
{
    int ret = EfxAdvanceFrameLut((void *)&proc->timer, (void *)&proc->frame, proc->frames);
    if (ret >= 0)
    {
        Decompress(proc->imgs[ret], gSpellAnimBgfx);
        RegisterDataMove(gSpellAnimBgfx, (void *)BG_VRAM + GetBackgroundTileDataOffset(BG_3), 0x6000);

        Decompress(proc->tsas[ret], gBG3TilemapBuffer);
        BG_EnableSyncByMask(BG3_SYNC_BIT);

        ApplyPalette(proc->pals[ret], 0);
        EnablePaletteSync();
    }

    if (ret == -1)
    {
        CpuFastFill16(0, gBG1TilemapBuffer, 0x800);
        BG_EnableSyncByMask(BG1_SYNC_BIT);
        SetBlendNone();
        Proc_Break(proc);
    }
}

void CustomOpAnim_End(struct ProcCustomOpAnim * proc)
{
    EndAllProcChildren(proc);
    EndProc08AA6D04();
    SetPrimaryHBlankHandler(NULL);
    EndOpAnimfxTerminator();

    gLCDControlBuffer.dispcnt.obj1dMap = 0;

    gPaletteBuffer[0] = gOpAnimSt.pal;
    EnablePaletteSync();

    SetDispEnable(0, 0, 0, 0, 0);
}

const struct ProcCmd ProcScr_CustomOpAnim[] = {
    PROC_CALL(CustomOpAnim_Init),
    PROC_YIELD,
    PROC_CALL(CustomOpAnim_Initfx),
    PROC_YIELD,
    PROC_REPEAT(CustomOpAnim_Loop),
    PROC_YIELD,
PROC_LABEL(99),
    PROC_CALL(CustomOpAnim_End),
    PROC_SLEEP(1),
    PROC_END
};
