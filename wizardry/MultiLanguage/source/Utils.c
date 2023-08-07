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

int DecodeUtf8(const u16 * utf8_buf, u32 * out, int * len)
{
    u16 tmp[4];

    switch (GetLenUtf8(utf8_buf))
    {
    case 1:
        *out = *utf8_buf;
        *len = 1;
        return 0;

    case 2:
        tmp[0] = utf8_buf[0] & 0x00011111;
        tmp[1] = utf8_buf[1] & 0x00111111;

        *out = tmp[0];
        *out = (*out << 0x6) | tmp[1];
        *len = 2;
        return 0;

    case 3:
        tmp[0] = utf8_buf[0] & 0x00001111;
        tmp[1] = utf8_buf[1] & 0x00111111;
        tmp[2] = utf8_buf[2] & 0x00111111;

        *out = tmp[0];
        *out = (*out << 0x6) | tmp[1];
        *out = (*out << 0x6) | tmp[2];
        *len = 3;
        return 0;

    case 4:
        tmp[0] = utf8_buf[0] & 0x00000111;
        tmp[1] = utf8_buf[1] & 0x00111111;
        tmp[2] = utf8_buf[2] & 0x00111111;
        tmp[3] = utf8_buf[3] & 0x00111111;

        *out = tmp[0];
        *out = (*out << 0x6) | tmp[1];
        *out = (*out << 0x6) | tmp[2];
        *out = (*out << 0x6) | tmp[3];
        *len = 4;
        return 0;

    default:
        *out = 0;
        *len = 0;
        return -1;
    }
}

struct Glyph const * const gGlyphsItem[16] = {
    [0] = (void *)0x858C7EC,
};

struct Glyph const * const gGlyphsText[16] = {
    [0] = (void *)0x858F6F4,
};

const struct Glyph * GetCharGlyphUnicode(u32 unicode_ch, int * len, int type)
{
    struct Glyph const * glyph;
    int grp = unicode_ch >> 0x10;
    int hi = (unicode_ch >> 0x8) & 0xFF;
    int lo = unicode_ch & 0xFF;
    struct Glyph const * glyph_grp;
    
    if (type == 0)
        glyph_grp = gGlyphsItem[grp];
    else
        glyph_grp = gGlyphsText[grp];

    for(glyph = &glyph_grp[lo]; glyph != NULL; glyph = glyph->sjisNext)
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
