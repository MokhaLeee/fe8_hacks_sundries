#include "gbafe.h"
#include "CustomOpAnim.h"

enum videos {
    BGPAL_OPANIMBG = 0x0,
    VRAMOFF_OPANIMBG = 0x0,
};

void OpAnimfx_WirteBgMap(const u16 * src)
{
    // LZ77UnCompWram(src, gEkrTsaBuffer);
    // EfxTmCpyBG(gEkrTsaBuffer, gBG1TilemapBuffer, 30, 20, OBJPAL_BANIM_SPELL_BG, 0x100);
    Decompress(src, gBG1TilemapBuffer);
    BG_EnableSyncByMask(BG1_SYNC_BIT);
}

void OpAnimfx_WirteBgGfx(const u16 * src)
{
    LZ77UnCompWram(src, gSpellAnimBgfx);
    RegisterDataMove(gSpellAnimBgfx, (void *)BG_VRAM + 0, 0x2000);
}

void OpAnimfx_WriteBgPal(const u16 * src)
{
    CpuFastCopy(src, PAL_BG(0), 0x20);
    EnablePaletteSync();
}
