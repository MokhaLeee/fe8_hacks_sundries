#pragma once

#include "global.h"

enum gpBmBattleGlobalFlag_bitfile {
    CHAX_BMBATTLE_GLBFLG_INORI_ITEM_ACTIVE = 1 << 0,
    CHAX_BMBATTLE_GLBFLG_DMG_HANDLER_ITEM_ACTIVE = 1 << 1,
};

extern u16 gItemIndex_Inori;
extern u16 gItemIndex_DmgHandler;
extern u8 *gpBmBattleGlobalFlag;
