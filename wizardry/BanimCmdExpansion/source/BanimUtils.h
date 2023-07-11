#pragma once

#include "global.h"
#include "proc.h"
#include "anime.h"

struct ProcEfxBmExpa {
    PROC_HEADER;

    short timer;
    struct Anim * anim;
};

void SetAnimStateFrozen(struct Anim *anim);
void SetAnimStateUnfrozen(struct Anim *anim);
void EfxDragonSetBgPriorityASM(void);

extern const u16 FrameLut_Duma[];
extern u16 const * const ImgLut_Duma[15];
extern u16 const * const TsaLut_Duma[15];
extern u16 const * const PalLut_Duma[15];

extern struct Anim * gAnims[4];
