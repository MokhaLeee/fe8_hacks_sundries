#include "global.h"
#include "bmunit.h"
#include "bmbattle.h"
#include "bmitem.h"

static void (*replaced_func)(struct BattleUnit *bu1, struct BattleUnit *bu2) = (void *)0x8B51B41;
// static int (*MgGetter)(struct Unit *unit) = (void *)0x080191B9;

enum buff_item_list {
    BUFF_ITEM_ATK,
    BUFF_ITEM_MAG,
    BUFF_ITEM_DEF,
    BUFF_ITEM_RES,
    BUFF_ITEM_HIT,
    BUFF_ITEM_AVO,
    BUFF_ITEM_CRT,
    BUFF_ITEM_MOV,
    BUFF_ITEM_AS,
    BUFF_ITEM_MAX
};
extern u8 gBuffItemLut[9];
extern s8 gBuffItemVal[9];

static inline bool checkUnitHandleItem(struct Unit *unit, int item)
{
    int i;
    for (i = 0; i < UNIT_ITEM_COUNT; i++) {
        if (ITEM_INDEX(unit->items[i]) == item)
            return true;
    }

    return false;
}

void PostInitializePreBattleLoop(struct BattleUnit *bu1, struct BattleUnit *bu2)
{
    replaced_func(bu1, bu2);

    if (GetItemAttributes(bu1->weapon) & (IA_MAGICDAMAGE | IA_MAGIC)) {
        /* MAG */
        if (checkUnitHandleItem(&bu1->unit, gBuffItemLut[BUFF_ITEM_MAG]))
            bu1->battleAttack += gBuffItemVal[BUFF_ITEM_MAG];
    } else {
        /* ATK */
        if (checkUnitHandleItem(&bu1->unit, gBuffItemLut[BUFF_ITEM_ATK]))
            bu1->battleAttack += gBuffItemVal[BUFF_ITEM_ATK];
    }

    if (GetItemAttributes(bu2->weapon) & (IA_MAGICDAMAGE | IA_MAGIC)) {
        /* RES */
        if (checkUnitHandleItem(&bu1->unit, gBuffItemLut[BUFF_ITEM_RES]))
            bu1->battleDefense += gBuffItemVal[BUFF_ITEM_RES];
    } else {
        /* DEF */
        if (checkUnitHandleItem(&bu1->unit, gBuffItemLut[BUFF_ITEM_DEF]))
            bu1->battleDefense += gBuffItemVal[BUFF_ITEM_DEF];
    }

    /* HIT */
    if (checkUnitHandleItem(&bu1->unit, gBuffItemLut[BUFF_ITEM_HIT]))
        bu1->battleHitRate += gBuffItemVal[BUFF_ITEM_HIT];

    /* AVO */
    if (checkUnitHandleItem(&bu1->unit, gBuffItemLut[BUFF_ITEM_AVO]))
        bu1->battleAvoidRate += gBuffItemVal[BUFF_ITEM_AVO];

    /* CRT */
    if (checkUnitHandleItem(&bu1->unit, gBuffItemLut[BUFF_ITEM_CRT]))
        bu1->battleCritRate += gBuffItemVal[BUFF_ITEM_CRT];
    
    if (checkUnitHandleItem(&bu1->unit, gBuffItemLut[BUFF_ITEM_AS]))
        bu1->battleSpeed += gBuffItemVal[BUFF_ITEM_AS];
}

static int (*prRallyMov)(int stat, struct Unit *unit) = (void *)0x8B5F859;

int PostRallyMov(int stat, struct Unit *unit)
{
    stat =  prRallyMov(stat, unit);

    if (checkUnitHandleItem(unit, gBuffItemLut[BUFF_ITEM_MOV]))
        stat += gBuffItemVal[BUFF_ITEM_MOV];

    return stat;
}

void UseBuffItem(struct Unit *unit, int item)
{
    int i;
    for (i = 0; i < UNIT_ITEM_COUNT; i++)
        if (ITEM_INDEX(unit->items[i]) == item)
            unit->items[i] = GetItemAfterUse(unit->items[i]);

    UnitRemoveInvalidItems(unit);
}

void PrePhaseUseBuffItem(void)
{
    int i, j;
    for (i = 0; i < 0x100; i++) {
        struct Unit *unit = gUnitLookup[i];

        if (!UNIT_IS_VALID(unit))
            continue;
        
        if (UNIT_FACTION(unit) != gPlaySt.faction)
            continue;

        for (j = 0; j < BUFF_ITEM_MAX; j++)
            UseBuffItem(unit, gBuffItemLut[j]);
    }
}
