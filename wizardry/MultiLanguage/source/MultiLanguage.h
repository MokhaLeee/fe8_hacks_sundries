#pragma once

#include "global.h"
#include "fontgrp.h"

enum text_types {
    TEXT_TYPE_SYSTEM,
    TEXT_TYPE_TALK,
};

enum multi_language_index {
    MULTI_LANG_JAPANSE = 0,
    MULTI_LANG_ENGLISH,
    MULTI_LANG_CHINESE,
};

int DecodeUtf8(const char * str, u32 * unicode_out, int * len);
struct Glyph * GetCharGlyphUnicode(u32 unicode_ch, struct Font * font);

/* Port from vanilla fontgrp.c */
#define CHAR_NEWLINE 0x01
extern struct Font * gActiveFont;
