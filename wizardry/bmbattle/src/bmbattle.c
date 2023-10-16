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

void BattleGenerateHitAttributesLoop_DmgHandlerItem(struct BattleUnit *attacker, struct BattleUnit *defender, struct BattleHit* hit, struct BattleStats *bstat)
{
    /* Dmg-handler item */
    if (bstat->damage > gItemDmgHandlerMaxDmg) {
        if (JudgeBmBattleItemEffect(defender, gItemIndex_DmgHandler)) {

            if (!(hit->attributes & BATTLE_HIT_ATTR_SURESHOT)) {
                hit->attributes |= BATTLE_HIT_ATTR_GREATSHLD;
                ((u8 *)hit)[4] = gSkillId_DmgHandlerItemAct;
            }

            bstat->damage = gItemDmgHandlerMaxDmg;
        }
    }
}

void BattleGenerateHitHack_802B894(struct BattleUnit *attacker, struct BattleUnit *defender)
{
    if (gBattleStats.config & BATTLE_CONFIG_SIMULATE)
        return;

    /* initialize */
    *gpBmBattleGlobalFlag &= ~CHAX_BMBATTLE_GLBFLG_INORI_ITEM_ACTIVE;
    *gpBmBattleInoriPid = 0;

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
