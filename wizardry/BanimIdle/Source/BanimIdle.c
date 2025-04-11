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

	bool need_trace = false; // ShouldTrace(anim);

	if (need_trace) {
		_maybe_unused int layer = GetAISLayerId(anim);
		_maybe_unused int pos = GetAnimPosition(anim);
		_maybe_unused int type = anim->currentRoundType;
		_maybe_unused int frame = BanimDefaultModeConfig[4 * type + layer * 2];

		Local_Printf("[anim=%p] layer=%d, pos=%d, type=%d(%d), diff=%d, inst=[0x%X 0x%X 0x%X]",
			anim, layer, pos, type, frame,
			anim->pScrCurrent - anim->pScrStart,
			anim->pScrCurrent[0], anim->pScrCurrent[1], anim->pScrCurrent[2]
		);
	}

	while (1) {
		u32 inst = ANINS_GET_TYPE(*cur);

		if (need_trace) {
			Local_Printf("Trace move: cur=%d, inst=[0x%X 0x%X 0x%X]",
				cur - anim->pScrStart,
				cur[0], cur[1], cur[2]
			);
		}

		if (cur == history)
			break;

		if (inst == ANIM_INS_TYPE_STOP) {
			pre = cur;
			cur -= 3;
			break;
		}

		if (inst == ANIM_INS_TYPE_COMMAND) {
			int this_cmd = ANINS_COMMAND_GET_ID(*cur);

			if (need_trace) {
				Local_Printf("cur=%d, cmd=0x%X, inst=[0x%X 0x%X 0x%X]",
					cur - anim->pScrStart,
					this_cmd,
					anim->pScrCurrent[0], anim->pScrCurrent[1], anim->pScrCurrent[2]
				);
			}

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
	bool need_trace = ShouldTrace(anim);

	if (need_trace) {
		_maybe_unused int layer = GetAISLayerId(anim);
		_maybe_unused int pos = GetAnimPosition(anim);
		_maybe_unused int type = anim->currentRoundType;
		_maybe_unused int frame = BanimDefaultModeConfig[4 * type + layer * 2];

		Local_Printf("[anim=%p] layer=%d, pos=%d, type=%d(%d), diff=%d, inst=[0x%X 0x%X 0x%X]",
			anim, layer, pos, type, frame,
			anim->pScrCurrent - anim->pScrStart,
			anim->pScrCurrent[0], anim->pScrCurrent[1], anim->pScrCurrent[2]
		);
	}

	if (anim->state3 & ANIM_BIT3_NEXT_ROUND_START)
		return false;

	return false;
}

bool Banim_C11(struct Anim *anim)
{
	bool need_trace = ShouldTrace(anim);

	if (need_trace) {
		_maybe_unused int layer = GetAISLayerId(anim);
		_maybe_unused int pos = GetAnimPosition(anim);
		_maybe_unused int type = anim->currentRoundType;
		_maybe_unused int frame = BanimDefaultModeConfig[4 * type + layer * 2];

		Local_Printf("[anim=%p] layer=%d, pos=%d, type=%d(%d), diff=%d, inst=[0x%X 0x%X 0x%X]",
			anim, layer, pos, type, frame,
			anim->pScrCurrent - anim->pScrStart,
			anim->pScrCurrent[0], anim->pScrCurrent[1], anim->pScrCurrent[2]
		);
	}

	if (C01_BLOCKING_PRE_BATTLE(anim)) {
		AnimMoveBackToCommand(anim, 0x10);
		anim->timer = NextRN_N(20) + 10;
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
	// anim->timer = NextRN_N(20) + 10;
	return false;
}
