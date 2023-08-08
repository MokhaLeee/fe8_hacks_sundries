#include "global.h"
#include "fontgrp.h"

#include "MultiLanguage.h"

const char * GetCharTextLen(const char * str, u32 * width)
{
    struct Glyph * glyph;
    u32 unicod;
    int ret, decode_len;

    ret = DecodeUtf8(str, &unicod, &decode_len);
    if (ret)
        return GetCharTextLen("?", width);

    glyph = GetCharGlyphUnicode(unicod, gActiveFont);
    if (glyph == NULL)
        return GetCharTextLen("?", width);

    *width = glyph->width;
    return str + decode_len;
}

int GetStringTextLen(const char * str)
{
    u32 _wid;
    int width = 0;
    while (*str != 0 && *str != CHAR_NEWLINE)
    {
        str = GetCharTextLen(str, &_wid);
        width += _wid;
    }
    return width;
}

const char * Text_DrawCharacter(struct Text * text, const char * str)
{
    struct Glyph * glyph;
    u32 unicod;
    int ret, decode_len;

    ret = DecodeUtf8(str, &unicod, &decode_len);
    if (ret)
        goto goto_err;

    glyph = GetCharGlyphUnicode(unicod, gActiveFont);
    if (glyph == NULL)
        goto goto_err;

    gActiveFont->drawGlyph(text, glyph);
    return str + decode_len;

goto_err:
    return Text_DrawCharacter(text, "?\0");
}

void Text_DrawString(struct Text * text, const char * str)
{
    while (*str != 0 && *str != CHAR_NEWLINE)
        str = Text_DrawCharacter(text, str);
}
