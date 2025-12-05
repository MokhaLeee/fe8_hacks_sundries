#include "gbafe.h"

struct ProcEkrTriangleRe {
	PROC_HEADER;

	u8 timer;
	struct Anim *anim;

	struct AnimBuffer desc;
};

void EkrTriangleRework_Init(struct ProcEkrTriangleRe * proc)
{
	struct AnimBuffer *desc = &proc->desc;

	desc->genericPalId = 0;
	desc->xPos = proc->anim->xPosition;
	desc->yPos = proc->anim->yPosition;
	desc->animId = 0;
	desc->charPalId = -1;
	desc->roundType = ANIM_ROUND_HIT_CLOSE;
	desc->state2 = 1;
	desc->oam2Tile = VRAMOFF_BANIM_SPELL_OBJ / 0x20;
	desc->oam2Pal = OBJPAL_BANIM_SPELL_OBJ;

	desc->pImgSheetBuf = gSpellAnimBgfx;
	desc->unk_20 = gBuf_Banim; // pal
	desc->unk_24 = gEkrKakudaiSomeBufLeft; // oam
	desc->unk_28 = gEkrKakudaiSomeBufRight; // scr

	desc->unk_30 = NULL; // magicfx_desc

	NewEkrUnitMainMini(&proc->desc);
	proc->timer = 0;
}

void EkrTriangleRework_Loop(struct ProcEkrTriangleRe * proc)
{
	proc->timer++;

	if (proc->timer == 5) {
		sub_805A990(&proc->desc);
		return;
	}

	if (proc->timer > 200) {
		sub_805AA28(&proc->desc);
		Proc_Break(proc);

		gEkrTriangleInvalid = true;
		return;
	}
}

const struct ProcCmd ProcScr_EkrTriangleRework[] = {
	PROC_NAME("ETriangleRe"),
	PROC_YIELD,
	PROC_CALL(EkrTriangleRework_Init),
	PROC_REPEAT(EkrTriangleRework_Loop),
	PROC_END,
};

/* LynJump */
void NewEkrTriangle(struct Anim *anim)
{
	struct ProcEkrTriangleRe *proc;

	proc = Proc_Start(ProcScr_EkrTriangleRework, PROC_TREE_3);

	proc->anim = anim;

	gEkrTriangleInvalid = false;
}

void ekrBattleExecTriangleAtk(struct ProcEkrBattle *proc)
{
	NewEkrTriangle(gAnims[2]);
	proc->proc_idleCb = (ProcFunc)ekrBattleWaitTriangleIdle;
}

extern SpellAnimFunc const *const pr_ClassReelSpellAnimFuncLut;

void StartClassReelSpellAnim(struct Anim * anim)
{
	int index;
    struct AnimMagicFxBuffer * magicFx = GetMagicEffectBufferFor(anim);

	if (magicFx == NULL)
		index = 0;
	else
		index = magicFx->magicFuncIdx;

    pr_ClassReelSpellAnimFuncLut[index](anim);
}
