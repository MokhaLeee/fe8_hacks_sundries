#include "gbafe.h"
#include "niniandisp.h"

extern struct BmBgxConf BmBgfxConf_NinianDisp[];

void NinianAppear_Init(struct ProcNinianAppear * proc)
{
    proc->timer = 0;

    gLCDControlBuffer.bg0cnt.priority = 0;
    gLCDControlBuffer.bg1cnt.priority = 1;
    gLCDControlBuffer.bg2cnt.priority = 0;
    gLCDControlBuffer.bg3cnt.priority = 3;

    SetBlendAlpha(0x10, 0x10);
    SetBlendTargetA(0, 0, 1, 0, 0);
    SetBlendTargetB(0, 0, 0, 1, 1);
}

void NinianDisp_FadeIn_Unused(struct ProcNinianAppear * proc)
{
    proc->timer++;
    WriteFadedPaletteFromArchive(
        0x100 - proc->timer,
        0x100 - proc->timer,
        0x100 - proc->timer,
        0xFFFFBFFF);

    if (proc->timer == 0x40)
    {
        proc->timer = 0;
        Proc_Break(proc);
    }
}

void NinianDisp_FadeOut_Unused(struct ProcNinianAppear * proc)
{
    proc->timer++;
    WriteFadedPaletteFromArchive(
        proc->timer + 0xC0,
        proc->timer + 0xC0,
        proc->timer + 0xC0,
        0xFFFFBFFF);

    if (proc->timer == 0x40)
    {
        proc->timer = 0;
        Proc_Break(proc);
    }
}

void NinianDisp_AnimLoopEnd_Unused(struct ProcNinianAppear * proc)
{
    if (++proc->timer == 1000)
    {
        BmBgfxSetLoopEN(false);
        Proc_Break(proc);
    }
}

void NinianAppear_Anim1(struct ProcNinianAppear * proc)
{
    int i;
    // int ix = OAM1_X(SCREEN_TILE_IX(proc->x) - 0x28);
    // int iy = OAM0_Y(SCREEN_TILE_IY(proc->y) - 0x28);

    Decompress(Img_NinianDispfx, OBJ_VRAM0 + OBCHR_NINIANDISP * CHR_SIZE);
    ApplyPalette(Pal_NinianDispfx, 0x10 + OBPAL_NINIANDISP);

    for (i = 0; i < 8; i++)
        proc->approc[i] = APProc_Create(
                            SpritAnim_NinianDispfx,
                            20,
                            0,
                            OAM2_CHR(OBCHR_NINIANDISP) + OAM2_PAL(OBPAL_NINIANDISP),
                            0,
                            4);

    proc->timer = 0;
}

void NinianAppear_LoopAnim1(struct ProcNinianAppear * proc)
{
    int i, ix, iy;
    int frc, terminator;
    int val1, val2, base_angle;

    terminator = 0xA0;

    ++proc->timer;
    ix = OAM1_X(SCREEN_TILE_IX(proc->x) + 8);
    iy = OAM0_Y(SCREEN_TILE_IY(proc->y) + 8);
    frc = 160 - proc->timer;
    val1 = (frc * 120 * frc) / 0x6400;
    val2 = (frc * 256 * frc) / 0x6400;

    base_angle = 272 - val2;
    for (i = 0; i < 8; i++)
    {
        int angle = (base_angle + 0x20 * i);
        int _x = 120 - ((COS(angle & 0xFF) * val1) >> 0xC);
        int _y = 80 - ((SIN(angle) * val1) >> 0xC);

        APProc_SetParameters(
            proc->approc[i],
            OAM1_X(_x),
            OAM0_Y(_y) + OAM0_BLEND,
            -1
        );
    }

    if (proc->timer == (terminator / 3))
        APProc_Create(
            SpritAnim_NinianDispfx,
            ix,
            iy + OAM0_BLEND,
            OAM2_CHR(OBCHR_NINIANDISP) + OAM2_PAL(OBPAL_NINIANDISP),
            1,
            4);

    if (proc->timer == terminator)
        Proc_Break(proc);
}

void NinianAppear_EndAnim1(struct ProcNinianAppear * proc)
{
    int i;
    for (i = 0; i < 8; i++)
        APProc_Delete(proc->approc[i]);
}

void NinianAppear_Anim2(struct ProcNinianAppear * proc)
{
    int ix = OAM1_X(SCREEN_TILE_IX(proc->x) - 0x28);
    int iy = OAM0_Y(SCREEN_TILE_IY(proc->y) - 0x28);

    StartBmBgfx(
        BmBgfxConf_NinianDisp,
        BG_2,
        ix, iy,
        0,
        0x2000,
        BGPAL_NINIANDISP,
        NULL,
        proc
    );

    proc->timer = 0;
}

void NinianAppear_LoadUnit(struct ProcNinianAppear * proc)
{
    proc->timer++;

#if 0
    if (proc->timer == 20)
    {
        EventLoadUnit(
            0xDC, // todo: pid
            0x40, // todo: jid
            proc->x,
            proc->y,
            proc->x,
            proc->y,
            FACTION_ID_GREEN,
            NULL
        );
    }
#endif

    if (proc->timer == 0x28)
    {
        proc->timer = 0;
        BmBgfxSetLoopEN(false);
        Proc_Break(proc);
    }
}

void NinianAppear_End(struct ProcNinianAppear * proc)
{
    SetBlendNone();
    InitBmBgLayers();
}

struct ProcCmd const ProcScr_NinianAppearfx[] = {
    PROC_YIELD,
    PROC_CALL(NinianAppear_Init),
    PROC_CALL(NinianAppear_Anim1),
    PROC_REPEAT(NinianAppear_LoopAnim1),
    PROC_CALL(NinianAppear_EndAnim1),
    PROC_CALL(NinianAppear_Anim2),
    PROC_REPEAT(NinianAppear_LoadUnit),
    PROC_WHILE(CheckBmBgfxDone),
    PROC_CALL(NinianAppear_End),
    PROC_END,
};

void StartNinianDisp(ProcPtr parent, int x, int y)
{
    struct ProcNinianAppear * procfx;
    procfx = Proc_StartBlocking(ProcScr_NinianAppearfx, parent);
    procfx->x = x;
    procfx->y = y;
}

void NinianDispTest(ProcPtr proc)
{
    StartNinianDisp(proc, 6, 5);
}
