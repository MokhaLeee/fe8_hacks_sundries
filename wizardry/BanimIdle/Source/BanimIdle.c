#include "gbafe.h"
#include "debug-kit.h"

#define _maybe_unused __attribute__((unused))
#define Local_Printf(x...) // Printf(x)

void Banim_C01(struct Anim *anim);
bool ShouldTrace(struct Anim *anim);

void AnimMoveBackToCommand(struct Anim *anim, int cmd)
{
	const u32 *history;
	const u32 *pre, *cur;

	history = anim->pScrCurrent;
	pre = cur = anim->pScrStart;

	while (1) {
		u32 inst = ANINS_GET_TYPE(*cur);

		if (cur == history)
			break;

		if (inst == ANIM_INS_TYPE_STOP) {
			pre = cur;
			cur -= 3;
			break;
		}

		if (inst == ANIM_INS_TYPE_COMMAND) {
			int this_cmd = ANINS_COMMAND_GET_ID(*cur);

			if (this_cmd == cmd) {
				cur = pre;
				break;
			}

			pre = cur;
			cur += 1;
		}

		if (inst == ANIM_INS_TYPE_FRAME) {
			pre = cur;
			cur += 3;
		}
	}
	anim->pScrCurrent = cur;
}

bool Banim_C10(struct Anim *anim)
{
	return false;
}

bool Banim_C11(struct Anim *anim)
{
	switch (BanimDefaultModeConfig[anim->currentRoundType * 4 + 0]) {
	case BANIM_MODE_STANDING:
	case BANIM_MODE_STANDING2:
	case BANIM_MODE_RANGED_STANDING:
		break;

	default:
		return false;
	}

	if (C01_BLOCKING_PRE_BATTLE(anim)) {
		AnimMoveBackToCommand(anim, 0x10);
		return false;
	}

	if (!(anim->state3 & ANIM_BIT3_TAKE_BACK_ENABLE))
		return false;

	if (C01_BLOCKING_IN_BATTLE(anim)) {
		if (GetAnimNextRoundType(anim) == ANIM_ROUND_INVALID && GetAnimRoundType(GetAnimAnotherSide(anim)) == ANIM_ROUND_INVALID)
			return false;

		if (anim->state3 & ANIM_BIT3_HIT_EFFECT_APPLIED)
			return false;
	}

	AnimMoveBackToCommand(anim, 0x10);
	return false;
}
