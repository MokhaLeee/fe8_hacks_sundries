#include "gbafe.h"
#include "debug-kit.h"

#define _maybe_unused __attribute__((unused))
#define Local_Printf(x...) // Printf(x)
bool ShouldTrace(struct Anim *anim);

void AnimMoveBackToCommand(struct Anim *anim, int cmd);

void Banim_C01(struct Anim *anim)
{
	bool need_trace = ShouldTrace(anim);

	if (need_trace) {
		_maybe_unused int layer = GetAISLayerId(anim);
		_maybe_unused int pos = GetAnimPosition(anim);
		_maybe_unused int type = anim->currentRoundType;
		_maybe_unused int frame = BanimDefaultModeConfig[4 * type + layer * 2];

		Printf("[anim=%p] layer=%d, pos=%d, type=%d(%d), diff=%d, inst=[0x%X 0x%X 0x%X]",
			anim, layer, pos, type, frame,
			anim->pScrCurrent - anim->pScrStart,
			anim->pScrCurrent[0], anim->pScrCurrent[1], anim->pScrCurrent[2]
		);
	}

	if (C01_BLOCKING_PRE_BATTLE(anim)) {
#if 1
		; // pass
#elif 1
		anim->pScrCurrent = anim->pScrCurrent + 1;
#else
		anim->pScrCurrent = anim->pScrStart;
#endif
	} else if (!C01_BLOCKING_IN_BATTLE(anim)) {
		anim->pScrCurrent = anim->pScrCurrent + 1;
	} else if (anim->state3 & ANIM_BIT3_HIT_EFFECT_APPLIED) {
		/* Release the anim lock after battle hitting */
		if (CheckEkrHitDone() == true) {
			anim->state3 &= ~(ANIM_BIT3_TAKE_BACK_ENABLE |
							  ANIM_BIT3_C01_BLOCKING_IN_BATTLE |
							  ANIM_BIT3_HIT_EFFECT_APPLIED);

			anim->pScrCurrent = anim->pScrCurrent + 1;

			if (Get0201FAC8() != 0)
				Set0201FAC8(0);
		}
	}

#if 1
	if (need_trace) {
		Printf("round=%d, type=%d/%d/%d, state3=0x%X done=%d/%d",
			anim->nextRoundId,
			anim->currentRoundType,
			GetAnimNextRoundType(anim),
			GetAnimRoundTypeAnotherSide(anim),
			anim->state3,
			gBanimDoneFlag[0], gBanimDoneFlag[1]
		);
	}

	switch (BanimDefaultModeConfig[anim->currentRoundType * 4 + 0]) {
	case BANIM_MODE_STANDING:
	case BANIM_MODE_STANDING2:
	case BANIM_MODE_RANGED_STANDING:
		break;

	default:
		return;
	}

	if (anim->state3 & (ANIM_BIT3_NEW_ROUND_START | ANIM_BIT3_NEXT_ROUND_START)) {
		Printf("return %d", 1);
		return;
	}

	if (GetAnimNextRoundType(anim) == ANIM_ROUND_INVALID &&
		gBanimDoneFlag[GetAnimPosition(GetAnimAnotherSide(anim))] == true &&
		gEkrDeadEventExist != false) {
		Printf("return %d", 2);
		return;
	}

	AnimMoveBackToCommand(anim, 0x10);
	anim->timer = NextRN_N(20) + 10;
#endif
}
