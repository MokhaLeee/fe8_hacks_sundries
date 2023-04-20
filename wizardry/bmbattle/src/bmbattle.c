#include "global.h"
#include "bmunit.h"
#include "bmitem.h"
#include "bmbattle.h"
#include "bmbattle-chax.h"

static bool JudgeInoriItemEffect(struct BattleUnit *bu)
{
    int i;
    struct Unit *unit = GetUnit(bu->unit.index);

    for (i = 0; i < UNIT_ITEM_COUNT; i++) {
        u16 item = bu->unit.items[i];

        if (ITEM_INDEX(item) == gItemIndex_Inori && ITEM_USES(item) > 0) {
            UnitUpdateUsedItem(unit, i);
            UnitUpdateUsedItem(&bu->unit, i);
            return true;
        }
    }

    return false;
}

bool BattleGenerateHitHack(struct BattleUnit *attacker, struct BattleUnit *defender)
{
    /* initialize */
    *gpBmBattleGlobalFlag &= ~CHAX_BMBATTLE_GLBFLG_INORI_ITEM_ACTIVE;

    if (defender->unit.curHP == 0) {
        if (JudgeInoriItemEffect(defender)) {
            *gpBmBattleGlobalFlag |= CHAX_BMBATTLE_GLBFLG_INORI_ITEM_ACTIVE;

            gBattleHitIterator->attributes |= BATTLE_HIT_ATTR_GREATSHLD;

            /* Setup skill activate anim index */
            ((u8 *)gBattleHitIterator)[4] = 0x25;

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
    
    return true;
}
