#include "gbafe.h"
#include "debug-kit.h"

void AnimInsert(struct Anim *anim);
int AnimInterpret(struct Anim *anim);

void Banim_C01(struct Anim *anim);

static bool ShouldTrace(struct Anim *anim)
{
	bool need_trace = false;

	if (anim == gAnims[0])
		need_trace = false;

	if (anim == gAnims[2])
		need_trace = true;

	return need_trace;
}

void AnimMoveBackToCommand(struct Anim *anim, int cmd)
{
	const u32 *history = anim->pScrCurrent;

	anim->pScrCurrent = anim->pScrStart;

	while (1) {
		u32 inst = ANINS_GET_TYPE(*anim->pScrCurrent);

		if (anim->pScrCurrent == history)
			break;

		if (inst == ANIM_INS_TYPE_STOP) {
			anim->pScrCurrent -= 3;
			break;
		}

		if (inst == ANIM_INS_TYPE_COMMAND) {
			int this_cmd = ANINS_COMMAND_GET_ID(inst);

			if (this_cmd == cmd)
				break;

			anim->pScrCurrent += 1;
		}

		if (inst == ANIM_INS_TYPE_FRAME)
			anim->pScrCurrent += 3;
	}
}

void Banim_C10(struct Anim *anim)
{
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

	; // pass
}

void Banim_C11(struct Anim *anim)
{
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

	if (!C01_BLOCKING_PRE_BATTLE(anim) && !C01_BLOCKING_IN_BATTLE(anim)) {
		if (anim->state3 & ANIM_BIT3_HIT_EFFECT_APPLIED) {
			return;
		}
	}

	AnimMoveBackToCommand(anim, 0x10);
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
