#include "global.h"
#include "bmlib.h"
#include "hardware.h"
#include "statscreen.h"
#include "bmlib.h"
#include "ctc.h"
#include "bmunit.h"
#include "mu.h"
#include "sysutil.h"
#include "uiutils.h"

#include "statscreenfx.h"

extern const u8 Tsa_StatScreenBg1Left[];
extern const u8 Img_StatScreenUI[];

static void LoadStatScreenUiFrame(void)
{
    Decompress(Img_StatScreenUI, BG_CHAR_ADDR(0));
    UnpackLegacyUiFramePalette(-1);
}

static void LoadStatScreenMuAreaBackGround(void)
{
    Decompress(Img_StatScreenMuAreaBg, gGenericBuffer);
    Copy2dChr(gGenericBuffer, OBJ_VRAM0 + STATSCREEN_MUAREA_CHR_BASE, 10, 4);
    ApplyPalette(Pal_StatScreenMuAreaBg, 0x10 + STATSCREEN_MUAREA_PAL_BASE);
}

/* LynJump */
void PageNumCtrl_DisplayMuPlatform(struct StatScreenPageNameProc * proc)
{
    SetBlendTargetA(0, 0, 1, 0, 0);
    SetBlendTargetB(0, 0, 0, 1, 0);
    SetBlendAlpha(6, 8);

    PutSprite(12,
        gStatScreen.xDispOff,
        gStatScreen.yDispOff,
        Sprite_StatScreenMuAreaBackground,
        OAM2_CHR(STATSCREEN_MUAREA_CHR_BASE / 0x20) +
        OAM2_PAL(STATSCREEN_MUAREA_PAL_BASE) +
        OAM2_LAYER(3));

    PutSprite(11,
        gStatScreen.xDispOff + 64,
        gStatScreen.yDispOff + 131,
        gObject_32x16, TILEREF(0x28F, STATSCREEN_OBJPAL_4) + OAM2_LAYER(3));
}

static void StatScreenDisplayBG1(int page)
{
    CallARM_FillTileRect(gUiTmScratchB, TsaLut_StatScreenBg1[page], TILEREF(0, 1));
}

static void StatScreenNewCallBack(ProcPtr proc)
{
    EndMuralBackground();
}

void StatScreen_InitDisplayRework(ProcPtr proc)
{
    StatScreen_InitDisplay(proc);

    /* Remove hallo */
    CpuFastFill16(0, (void *)0x06004400, 0x1400);

    /* Remove BG3 */
    TileMap_FillRect(gBG3TilemapBuffer + TILEMAP_INDEX(0, 0), 32, 30, 0);

    /* Set left BG */
    LoadStatScreenMuAreaBackGround();
    LoadStatScreenUiFrame();
    CallARM_FillTileRect(gBG1TilemapBuffer, Tsa_StatScreenBg1Left, TILEREF(0, 1));

    /* Set right BG */
    StatScreenDisplayBG1(gStatScreen.page);
    TileMap_CopyRect(
        gUiTmScratchB,
        gBG1TilemapBuffer + 0 + TILEMAP_INDEX(12, 2),
        18, 18);
    BG_EnableSyncByMask(BG1_SYNC_BIT);

    StartMuralBackground(NULL, (void *)VRAM + 0xB000, -1);
    Proc_SetEndCb(proc, StatScreenNewCallBack);


}

void PageSlide_OnLoopRework(struct StatScreenEffectProc * proc)
{
    int off;
    int len, dstOff, srcOff;
    off = sPageSlideOffsetLut[proc->timer];

    /* Vanilla */
    PageSlide_OnLoop(proc);

    off = sPageSlideOffsetLut[proc->timer];

    if (off == INT8_MAX)
    {
        TileMap_FillRect(gBG1TilemapBuffer + TILEMAP_INDEX(12, 2), 18, 18, 0);
        StatScreenDisplayBG1(proc->newItem);
        off = sPageSlideOffsetLut[proc->timer];
    }

    if (proc->key & DPAD_LEFT)
        off = -off;

    len = 18 - abs(off);

    if (off < 0)
    {
        dstOff = 0;
        srcOff = -off;
    }
    else
    {
        dstOff = off;
        srcOff = 0;
    }

    TileMap_CopyRect(
        gUiTmScratchB + srcOff,
        gBG1TilemapBuffer + dstOff + TILEMAP_INDEX(12, 2),
        len, 18);

    BG_EnableSyncByMask(BG1_SYNC_BIT);
}

/* LynJump */
void UnitSlide_SetNewUnit(struct StatScreenEffectProc* proc)
{
    gStatScreen.unit = GetUnit(proc->newItem);

    StatScreen_Display(Proc_Find(gProcScr_StatScreen));
    Proc_Break(proc);

#if 0
    CallARM_FillTileRect(gBG1TilemapBuffer, Tsa_StatScreenBg1Left, TILEREF(0, 1));
    StatScreenDisplayBG1(gStatScreen.page);
    TileMap_CopyRect(
        gUiTmScratchB,
        gBG1TilemapBuffer + 0 + TILEMAP_INDEX(12, 2),
        18, 18);

    BG_EnableSyncByMask(BG1_SYNC_BIT);
#endif

    /**
     * I have no idea, but the BG1 is disabled
     */
    SetDispEnable(1, 1, 1, 1, 1);
}
