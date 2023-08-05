#include "global.h"
#include "bmunit.h"
#include "bmitem.h"
#include "bmitemuse.h"
#include "constants/items.h"
#include "constants/characters.h"

#include "ClassChgExpansion.h"

bool CanUnitUsePromotionItemVanilla(struct Unit * unit, int item)
{
    #define CHECK_LIST(it)                       \
        while (*it)                              \
        {                                        \
            if (unit->pClassData->number == *it) \
                return true;                     \
            it++;                                \
        }                                        \

    const u8 * classList = NULL;

    if (unit->pCharacterData->number == CHARACTER_EIRIKA || unit->pCharacterData->number == CHARACTER_EPHRAIM)
    {
        switch (GetItemIndex(item))
        {

        case ITEM_LUNARBRACE:
            classList = gItemUseJidList_LunarBrace;
            break;

        case ITEM_SOLARBRACE:
            classList = gItemUseJidList_SolarBrace;
            break;

        } // switch (GetItemIndex(item))

        if (classList)
            CHECK_LIST(classList);
    }

    if (unit->level < 10)
        return false;

    switch (GetItemIndex(item))
    {

    case ITEM_HEROCREST:
        classList = gItemUseJidList_HeroCrest;
        break;

    case ITEM_KNIGHTCREST:
        classList = gItemUseJidList_KnightCrest;
        break;

    case ITEM_ORIONSBOLT:
        classList = gItemUseJidList_OrionsBolt;
        break;

    case ITEM_ELYSIANWHIP:
        classList = gItemUseJidList_ElysianWhip;
        break;

    case ITEM_GUIDINGRING:
        classList = gItemUseJidList_GuidRing;
        break;

    case ITEM_MASTERSEAL:
        classList = gItemUseJidList_MasterSeal;
        break;

    case ITEM_LUNARBRACE:
        classList = gItemUseJidList_LunarBrace;
        break;

    case ITEM_SOLARBRACE:
        classList = gItemUseJidList_SolarBrace;
        break;

    case ITEM_HEAVENSEAL:
        classList = gItemUseJidList_HeavenSeal;
        break;

    case ITEM_UNK_C1:
        classList = gItemUseJidList_C1;
        break;

    case ITEM_OCEANSEAL:
        classList = gItemUseJidList_OceanSeal;
        break;

    } // switch (GetItemIndex(item))

    CHECK_LIST(classList);

    return false;

    #undef CHECK_LIST
}

/* LynJump! */
bool CanUnitUsePromotionItem(struct Unit * unit, int item)
{
    u8 tmp_buf[0x10];

    if (GetClasschgList(unit, item, tmp_buf, UNIT_PROMOT_LIST_MAX) > 0)
        return true;

    return false;
}
