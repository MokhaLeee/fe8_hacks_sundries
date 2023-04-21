#include "global.h"
#include "bmunit.h"
#include "bmitem.h"
#include "bmbattle.h"
#include "bmbattle-chax.h"

void BattleGenerateHitAttributes(struct BattleUnit* attacker, struct BattleUnit* defender);

bool JudgeBmBattleItemEffect(struct BattleUnit *bu, int item_id)
{
    int i;
    for (i = 0; i < UNIT_ITEM_COUNT; i++) {
        u16 item = bu->unit.items[i];

        if (ITEM_INDEX(item) == item_id && ITEM_USES(item) != 0) {
            UnitUpdateUsedItem(&bu->unit, i);
            return true;
        }
    }

    return false;
}

void BattleGenerateHitHack_802B874(struct BattleUnit *attacker, struct BattleUnit *defender)
{
    BattleGenerateHitAttributes(attacker, defender);

    /* Dmg-handler item */
    if (gBattleStats.damage > gItemDmgHandlerMaxDmg) {
        if (JudgeBmBattleItemEffect(defender, gItemIndex_DmgHandler)) {

            if (!(gBattleHitIterator->attributes & BATTLE_HIT_ATTR_SURESHOT)) {
                gBattleHitIterator->attributes |= BATTLE_HIT_ATTR_GREATSHLD;
                ((u8 *)gBattleHitIterator)[4] = gSkillId_DmgHandlerItemAct;
            }

            gBattleStats.damage = gItemDmgHandlerMaxDmg;
        }
    }
}

void BattleGenerateHitHack_802B894(struct BattleUnit *attacker, struct BattleUnit *defender)
{
    /* initialize */
    *gpBmBattleGlobalFlag &= ~CHAX_BMBATTLE_GLBFLG_INORI_ITEM_ACTIVE;

    /* Inori item */
    if (defender->unit.curHP == 0) {
        if (JudgeBmBattleItemEffect(defender, gItemIndex_Inori)) {
            *gpBmBattleGlobalFlag |= CHAX_BMBATTLE_GLBFLG_INORI_ITEM_ACTIVE;
            *gpBmBattleInoriPid = defender->unit.index;

            gBattleHitIterator->attributes &= ~BATTLE_HIT_ATTR_SURESHOT;
            gBattleHitIterator->attributes |= BATTLE_HIT_ATTR_GREATSHLD;
            ((u8 *)gBattleHitIterator)[4] = gSkillId_InoriItemAct;

            defender->unit.curHP = 1;

            if (gBattleStats.damage > 0)
                gBattleStats.damage--;

            gBattleHitIterator->hpChange = gBattleStats.damage;
        } else {
            attacker->wexpMultiplier++;
        }
    }

    /* vanilla */
    gBattleHitIterator->info |= BATTLE_HIT_INFO_FINISHES;

    if (gBattleTarget.unit.curHP == 0)
        gBattleHitIterator->info |= BATTLE_HIT_INFO_KILLS_TARGET;
}
