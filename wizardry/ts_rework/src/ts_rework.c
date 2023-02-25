#include "global.h"
#include "mapselect.h"
#include "proc.h"
#include "unit.h"
#include "hardware.h"
#include "uimenu.h"
#include "uiutils.h"
#include "item.h"

extern struct ProcScr ProcCmd_NewTargetSelection[];

ProcPtr StartNewTargetSelection(const struct SelectInfo* selectInfo){
    
    struct SelectTargetProc* proc;

    LockGameLogic();
    proc = SpawnProc(ProcCmd_NewTargetSelection, PROC_TREE_3);

    proc->flags = TARGETSELECTION_FLAG_GAMELOCK;
    proc->selectRoutines = selectInfo;
    proc->currentTarget = GetFirstTargetPointer();
    proc->onAPress = 0;

    if (proc->selectRoutines->on_init) {
        proc->selectRoutines->on_init(proc);
    }

    if (proc->selectRoutines->onUnk08) {
        proc->selectRoutines->onUnk08(proc);
    }

    if (proc->selectRoutines->on_switch_in) {
        proc->selectRoutines->on_switch_in(proc, proc->currentTarget);
    }

    gKeySt->pressed = 0;

    return proc;
    
}

u8 UnknownMenu_Selected(struct MenuProc* menu, struct MenuItemProc* menu_item){
    
    extern const struct SelectInfo gUnknown_0859D3F8;
    u16 weapon = gActiveUnit->items[menu_item->itemNumber];

    UnitEquipItemSlot(gActiveUnit, menu_item->itemNumber);
    gAction.itemSlotIndex = 0;

    ClearBg0Bg1();
    MakeTargetListForWeapon(gActiveUnit, weapon);
    
    // reworked a new CTS
    StartNewTargetSelection(&gUnknown_0859D3F8);

    return MENU_ACT_ENDFACE | MENU_ACT_CLEAR | MENU_ACT_SND6A | MENU_ACT_END | MENU_ACT_SKIPCURSOR;
}
