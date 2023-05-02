#pragma once

#include "global.h"
#include "anime.h"

extern struct Anim *gAnims[];

struct EkrDragonFrameLut {
    u8 fbanim_intro;
    u8 fbanim_main;
    u8 fbanim_exit;
};

struct EkrDragonHandler {
    u8 type;
    u8 class;

    u16 config;

    void (*intro)(struct Anim *anim, u32 priv);
    u32 priv;
};

enum EkrDragonHandler_config {
    EKRDRAGON_CONFIG_COMMON = (1 << 0),
    EKRDRAGON_CONFIG_UNIQUE_INTRO = (1 << 1),
};

extern struct EkrDragonHandler EkrDragonSpecialRountineHook[];
