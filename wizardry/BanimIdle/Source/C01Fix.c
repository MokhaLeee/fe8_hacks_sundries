#include "gbafe.h"
#include "debug-kit.h"

void AnimMoveBackToCommand(struct Anim *anim, int cmd);

void Banim_C01(struct Anim *anim)
{
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

#if 0
	if (anim->state3 & (ANIM_BIT3_NEW_ROUND_START | ANIM_BIT3_NEXT_ROUND_START))
		return;

	AnimMoveBackToCommand(anim, 0x10);
	// anim->timer = 0x20;
#endif
}
