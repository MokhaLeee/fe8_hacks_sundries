#include "gbafe.h"
#include <string.h>
bool LoadBonusContentData(void *buf);

void EventGiveBonusClaimItem(struct EventEngineProc * proc)
{
    struct BonusClaimEnt * buf = (void *)gGenericBuffer;
    u16 bonus_item = ITEM_INDEX(gEventSlots[EVT_SLOT_B]);
    int i, ret = LoadBonusContentData(buf);
    if (ret == false)
        return;

    for (i = 0; i < 0x10; i++)
    {
        if (buf[i].unseen == true)
            continue;

        buf[i].unseen = true;
        buf[i].kind = BONUSKIND_ITEM0;
        buf[i].itemId = bonus_item;

        memset(buf[i].str, 0, sizeof(buf[i].str));
        break;
    }
    SaveBonusContentData(buf);
}

void EventGiveBonusClaimMoney(struct EventEngineProc * proc)
{
    struct BonusClaimEnt * buf = (void *)gGenericBuffer;
    u16 bonus_money = gEventSlots[EVT_SLOT_B];
    int i, ret = LoadBonusContentData(buf);
    if (ret == false)
        return;

    for (i = 0; i < 0x10; i++)
    {
        if (buf[i].unseen == true)
            continue;

        buf[i].unseen = true;
        buf[i].kind = BONUSKIND_MONEY;
        buf[i].itemId = bonus_money;

        memset(buf[i].str, 0, sizeof(buf[i].str));
        break;
    }
    SaveBonusContentData(buf);
}
