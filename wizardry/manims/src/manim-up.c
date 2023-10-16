#include "global.h"
#include "manims.h"
#include "bmunit.h"
#include "proc.h"
#include "bm.h"
#include "bmlib.h"
#include "ctc.h"
#include "soundwrapper.h"

struct ProcManimUp {
    PROC_HEADER;
    struct Unit *unit;
    int timer;
};

struct ProcManimUpSub {
    PROC_HEADER;
    int xPos, yPos;
    int timer;
    int xReal, yReal;
};

void ManimUpSubInit(struct ProcManimUpSub *proc)
{
	if(proc->xPos > 0xF0 || proc->yPos > 0xA0) {
		Proc_End(proc);
		return;
	}
	
	proc->xReal = (proc->xPos + 0x200) % 0x200;
	proc->yReal = (proc->yPos + 0x0FD) % 0x100 + 15;
	proc->timer = 0;
}

void ManimUpSubUpdate(struct ProcManimUpSub *proc)
{
    PutSprite(
		1, 
		proc->xReal, 
		proc->yReal,
		gObject_16x8, 
		OAM2_PAL(0) + OAM2_CHR(OBJ_VRAMOFF / 0x20) + OAM2_LAYER(0x1));
    
    proc->yReal--;
	
	if(++proc->timer > 0xF)
		Proc_Break(proc);
}

const struct ProcCmd ProcScr_ManimUpSubAnim[] = {
    PROC_CALL(ManimUpSubInit),
    PROC_YIELD,
    PROC_REPEAT(ManimUpSubUpdate),
    PROC_END
};

void ManimUpInit(struct ProcManimUp *proc)
{
    Decompress(Img_ManimGravity, OBJ_VRAM0 + OBJ_VRAMOFF);
    proc->timer = 0;
    PlaySoundEffect(0x8B);
}

void ManimUpStartSubAnim(struct ProcManimUp *proc)
{
    if (0 == proc->timer % 8) {
        struct ProcManimUpSub *child = Proc_Start(ProcScr_ManimUpSubAnim, PROC_TREE_3);
        child->xPos = proc->unit->xPos * 16 - gBmSt.camera.x;
		child->yPos = proc->unit->yPos * 16 - gBmSt.camera.y;
    }

    if(proc->timer > (3 * 8))
		Proc_Break(proc);

    proc->timer++;
}

void ManimUpStartSubAnimExist(struct ProcManimUp *proc)
{
    if(!Proc_Find(ProcScr_ManimUpSubAnim))
        Proc_Break(proc);
}

const struct ProcCmd ProcScr_ManimUp[] = {
    PROC_CALL(ManimUpInit),
    PROC_YIELD,
    PROC_REPEAT(ManimUpStartSubAnim),
    PROC_YIELD,
    PROC_REPEAT(ManimUpStartSubAnimExist),
    PROC_END
};

/* API */
void ExecManim_up(ProcPtr parent, struct Unit *unit)
{
    struct ProcManimUp *proc = Proc_StartBlocking(ProcScr_ManimUp, parent);
    proc->unit = unit;
}
