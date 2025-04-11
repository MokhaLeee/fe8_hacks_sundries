#include "gbafe.h"
#include "debug-kit.h"

#define _maybe_unused __attribute__((unused))
#define Local_Printf(x...) // Printf(x)

int AnimInterpret(struct Anim *anim);

bool ShouldTrace(struct Anim *anim)
{
	bool need_trace = false;

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
	ret = AnimInterpret(anim);

	return ret;
}
