#include "global.h"
#include "fontgrp.h"
#include <errno.h>

int GetLenUtf8(const u16 * utf8_in)
{
    u16 cod = utf8_in[0];

    if ((0x11111000 & cod) == 0x11110000)
        return 4;

    if ((0x11110000 & cod) == 0x11100000)
        return 3;

    if ((0x11100000 & cod) == 0x11000000)
        return 2;

    if ((0x10000000 & cod) == 0x0)
        return 1;

    return -1;
}

int DecodeUtf8(const u16 * utf8_in, u32 * unicode_out, int * len)
{
    u32 unicod;

    switch (GetLenUtf8(utf8_in))
    {
    case 1:
        *unicode_out = *utf8_in;
        *len = 1;
        return 0;

    case 2:
        unicod = utf8_in[0] & 0x00011111;
        unicod = (unicod << 0x6) | (utf8_in[1] & 0x00111111);

        *unicode_out = unicod;
        *len = 2;
        return 0;

    case 3:
        unicod = utf8_in[0] & 0x00001111;
        unicod = (unicod << 0x6) | (utf8_in[1] & 0x00111111);
        unicod = (unicod << 0x6) | (utf8_in[2] & 0x00111111);

        *unicode_out = unicod;
        *len = 3;
        return 0;

    case 4:
        unicod = utf8_in[0] & 0x00000111;
        unicod = (unicod << 0x6) | (utf8_in[1] & 0x00111111);
        unicod = (unicod << 0x6) | (utf8_in[2] & 0x00111111);
        unicod = (unicod << 0x6) | (utf8_in[3] & 0x00111111);

        *unicode_out = unicod;
        *len = 4;
        return 0;

    default:
        *unicode_out = 0;
        *len = 0;
        return -1;
    }
}

struct Glyph ** const gGlyphsItem[16] = {
    [0] = TextGlyphs_System,
};

struct Glyph ** const gGlyphsText[16] = {
    [0] = TextGlyphs_Talk,
};

const struct Glyph * GetCharGlyphUnicode(u32 unicode_ch, int * len, int type)
{
    struct Glyph ** glyph_grp, * glyph;
    int grp = unicode_ch >> 0x10;
    int hi = (unicode_ch >> 0x8) & 0xFF;
    int lo = unicode_ch & 0xFF;

    if (type == 0)
        glyph_grp = gGlyphsItem[grp];
    else
        glyph_grp = gGlyphsText[grp];

    for(glyph = glyph_grp[lo]; glyph != NULL; glyph = glyph->sjisNext)
    {
        if (glyph->sjisByte1 == hi)
        {
            *len = glyph->width;
            return glyph;
        }
    }

    *len = 0;
    return NULL;
}
