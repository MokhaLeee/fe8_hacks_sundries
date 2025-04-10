#include "gbafe.h"
#include "debug-kit.h"

void AnimInsert(struct Anim *anim);
int AnimInterpret(struct Anim *anim);

void Banim_C10(struct Anim *anim)
{
	if (anim->unk13 > 0)
		anim->unk13--;

	if (anim->state3 & ANIM_BIT3_HIT_EFFECT_APPLIED)
		return;

	if (anim->unk13 != 0)
		anim->pScrCurrent--;
}

void Banim_C11(struct Anim *anim)
{
	anim->pScrCurrent = anim->pScrStart;

	while (1) {
		u32 inst = ANINS_GET_TYPE(*anim->pScrCurrent);

		if (inst == ANIM_INS_TYPE_STOP) {
			anim->pScrCurrent -= 3;
			return;
		} else if (inst == ANIM_INS_TYPE_COMMAND) {
			switch (ANINS_COMMAND_GET_ID(inst)) {
			case 0x10:
			case 0x11:
				anim->unk13 = 0x20;
				return;

			default:
				break;
			}
			anim->pScrCurrent += 1;
		} else if (inst == ANIM_INS_TYPE_FRAME)
			anim->pScrCurrent += 3;
	}
}

static bool ShouldTrace(struct Anim *anim)
{
	bool need_trace = true;

	if (anim == gAnims[0])
		need_trace = true;

	if (anim == gAnims[2])
		need_trace = true;

	return need_trace;
}

int AnimTrace_AnimInterpret(struct Anim *anim)
{
	int ret;
	bool need_trace = ShouldTrace(anim);

	if (need_trace) {
		int layer = GetAISLayerId(anim);
		int pos = GetAnimPosition(anim);
		int type = anim->currentRoundType;
		int frame = BanimDefaultModeConfig[4 * type + layer * 2];

		Printf("[anim=%p] layer=%d, pos=%d, type=%d(%d), diff=%d, inst=[0x%X 0x%X 0x%X]",
			anim, layer, pos, type, frame,
			anim->pScrCurrent - anim->pScrStart,
			anim->pScrCurrent[0], anim->pScrCurrent[1], anim->pScrCurrent[2]
		);
	}
	ret = AnimInterpret(anim);

	return ret;
}
