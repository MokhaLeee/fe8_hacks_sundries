#include "gbafe.h"
#include "debug-kit.h"

#define _maybe_unused __attribute__((unused))
#define Local_Printf(x...) // Printf(x)
bool ShouldTrace(struct Anim *anim);

void AnimMoveBackToCommand(struct Anim *anim, int cmd);

void Banim_C01(struct Anim *anim)
{
	struct ProcEkrBattle *ekrbattle = Proc_Find(gProc_ekrBattle);

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

	switch (BanimDefaultModeConfig[anim->currentRoundType * 4 + 0]) {
	case BANIM_MODE_STANDING:
	case BANIM_MODE_STANDING2:
	case BANIM_MODE_RANGED_STANDING:
		break;

	default:
		return;
	}

	if (
		ekrbattle->proc_idleCb == (ProcFunc)ekrBattleOnBattleEnd ||
		ekrbattle->proc_idleCb == (ProcFunc)ekrBattle_WaitForPostBattleAct ||
		ekrbattle->proc_idleCb == (ProcFunc)ekrBattleExecExpGain ||
		ekrbattle->proc_idleCb == (ProcFunc)ekrBattle_80508F0 ||
		ekrbattle->proc_idleCb == (ProcFunc)ekrBattle_8050940 ||
		ekrbattle->proc_idleCb == (ProcFunc)ekrBattleWaitExpBarIdle ||
		ekrbattle->proc_idleCb == (ProcFunc)ekrBattlePostExpBarIdle ||
		ekrbattle->proc_idleCb == (ProcFunc)ekrBattle_8050AB8 ||
		ekrbattle->proc_idleCb == (ProcFunc)ekrBattleLvupHanlder ||
		ekrbattle->proc_idleCb == (ProcFunc)ekrBattle_ExecEkrLvup ||
		ekrbattle->proc_idleCb == (ProcFunc)ekrBattle_WaitEkrLvupIdle ||
		ekrbattle->proc_idleCb == (ProcFunc)ekrNewEkrPopup ||
		ekrbattle->proc_idleCb == (ProcFunc)ekrBattle_WaitForPopup ||
		ekrbattle->proc_idleCb == (ProcFunc)ekrBattle_PostPopup ||
		0
	)
		goto goto_loop;

	if (anim->state3 & (ANIM_BIT3_NEW_ROUND_START | ANIM_BIT3_NEXT_ROUND_START)) {
		return;
	}

	if (ekrbattle->proc_idleCb == (ProcFunc)ekrBattleInRoundIdle &&
		GetAnimNextRoundType(anim) == ANIM_ROUND_INVALID &&
		gBanimDoneFlag[GetAnimPosition(GetAnimAnotherSide(anim))] == true) {
		return;
	}

goto_loop:
	AnimMoveBackToCommand(anim, 0x10);
	anim->timer = NextRN_N(20) + 10;
#endif
}
