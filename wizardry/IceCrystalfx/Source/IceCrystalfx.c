#include "gbafe.h"

void sub_80857F4(ProcPtr parent);
void sub_808581C(ProcPtr parent);

void FE7J_HBlank_Scanline_8078098(void);
void FE7J_sub_80780E0(int a, int b);

struct ProcIceCrystal {
    PROC_HEADER;
    s16 timer;
    int bg2_offset;
};

extern struct BmBgxConf BmBgfxConf_IceCrystal[];

void IceCrystalfx_Start(struct ProcIceCrystal * proc)
{
    ArchiveCurrentPalettes();
    proc->timer = 0;

    SetBlendAlpha(0x10, 0x10);
    SetBlendTargetA(0, 0, 1, 0, 0);
    SetBlendTargetB(1, 1, 1, 1, 1);

    InitScanline();
    FE7J_sub_80780E0(0, 0);

    SetPrimaryHBlankHandler(NULL);
    SetPrimaryHBlankHandler(FE7J_HBlank_Scanline_8078098);

    gLCDControlBuffer.bg0cnt.priority = 0;
    gLCDControlBuffer.bg2cnt.priority = 1;
    gLCDControlBuffer.bg1cnt.priority = 1;
    gLCDControlBuffer.bg3cnt.priority = 3;

    StartBmBgfx(
        BmBgfxConf_IceCrystal,
        BG_2,
        0, 0,
        0x1000,
        0x2000,
        0,
        NULL, proc
    );

    BG_EnableSyncByMask(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT);

    PlaySoundEffect(0x2FA);
}

void IceCrystalfx_ResetPalette(struct ProcIceCrystal * proc)
{
    proc->timer = 0x100;
    ArchiveCurrentPalettes();

    // StartEventHorizontalQuakefxViolentlyNoSound(proc);
    sub_80857F4(proc);
}

void IceCrystalfx_RefrainPalette(struct ProcIceCrystal * proc)
{
    proc->timer += 0x10;

    WriteFadedPaletteFromArchive(proc->timer, proc->timer, proc->timer, 1);

    if (proc->timer == 0x200)
    {
        // StartEventHorizontalQuakefxSlightlyNoSound(proc);
        sub_808581C(proc);

        proc->timer = 0;
        Proc_Break(proc);
    }
}

void IceCrystalfx_Paluse(struct ProcIceCrystal * proc)
{
    int time = ++proc->timer >> 2;
    SetBlendAlpha(0x10 - time, 0x10);

    if (time == 0x10)
    {
        BG_Fill(gBG2TilemapBuffer, 0);
        BG_EnableSyncByMask(BG2_SYNC_BIT);

        gLCDControlBuffer.bg0cnt.priority = 0;
        gLCDControlBuffer.bg2cnt.priority = 1;
        gLCDControlBuffer.bg1cnt.priority = 2;
        gLCDControlBuffer.bg3cnt.priority = 3;

        SetPrimaryHBlankHandler(NULL);
        Proc_Break(proc);
    }
}

const struct ProcCmd ProcScr_IceCrystalfx[] = {
    PROC_YIELD,
    PROC_CALL(IceCrystalfx_Start),
    PROC_WHILE(CheckBmBgfxDone),
    PROC_SLEEP(40),
    PROC_CALL(IceCrystalfx_ResetPalette),
    PROC_REPEAT(IceCrystalfx_RefrainPalette),
    PROC_REPEAT(IceCrystalfx_Paluse),
    PROC_END,
};

void StartLoadIceCrystal(ProcPtr proc)
{
    Proc_StartBlocking(ProcScr_IceCrystalfx, proc);
}
