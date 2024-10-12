#include "gbafe.h"

extern void * const prBattleHitArray;
extern u8 BattleHitArrayWidth;

void StartBattleAnimHitEffectsDefault(struct Anim * anim, int type)
{
    int round = anim->nextRoundId - 1;
    struct BattleHit * hit = (prBattleHitArray + BattleHitArrayWidth * round);

    if (hit->attributes & BATTLE_HIT_ATTR_HPSTEAL)
    {
        StartBattleAnimResireHitEffects(anim, type);
        return;
    }

    StartBattleAnimHitEffects(anim, type, 3, 4);
}
