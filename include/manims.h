#pragma once

#include "global.h"

enum{
	// Real VRAM Offset to uncompress: OBJ_VRAM0 + OBJ_MOKHA_VRAMOFF
	OBJ_VRAMOFF = 0x53C0, 
};

extern u16 Img_ManimGravity[];

void ExecManim_up(ProcPtr parent, struct Unit *unit);
