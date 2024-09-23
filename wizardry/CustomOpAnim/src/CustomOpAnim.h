#pragma once

#include "gbafe.h"

#ifndef EfxAnimConf
struct EfxAnimConf {
    /**
     * If you want FEB identify your efxanim conf
     * then you have to add this unused header (dump from skillanimtemplate.dmp)
     */
    u8 _unused_header[0x150];

    const s16 * frame_confs;
    u16 const * const * tsas;
    u16 const * const * imgs;
    u16 const * const * pals;
    u8 _pad_[4];
};
#endif // EfxAnimConf

extern struct EfxAnimConf const * const gpOpAnimFrames;

struct ProcCustomOpAnim {
    PROC_HEADER;

    s16 timer;
    u32 frame;

    const u16 * const * imgs;
    const u16 * const * pals;
    const u16 * const * tsas;
    const s16 * frames;
};

void OpAnimfx_WirteBgMap(const u16 * src);
void OpAnimfx_WirteBgGfx(const u16 * src);
void OpAnimfx_WriteBgPal(const u16 * src);
