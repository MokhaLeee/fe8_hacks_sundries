#include "gbafe.h"

const struct MenuItemDef sDebugMenuItems[] = {
	{ NULL, 0x69A, 0x6DF, 0, 0x6e, MenuAlwaysEnabled, 0, MapMenu_UnitCommand, 0, 0, 0},
	{ NULL, 0x69A, 0x6DF, 0, 0x6e, MenuAlwaysEnabled, 0, MapMenu_UnitCommand, 0, 0, 0},
	{ NULL, 0x69A, 0x6DF, 0, 0x6e, MenuAlwaysEnabled, 0, MapMenu_UnitCommand, 0, 0, 0},
	{ NULL, 0x69A, 0x6DF, 0, 0x6e, MenuAlwaysEnabled, 0, MapMenu_UnitCommand, 0, 0, 0},
	{ NULL, 0x69A, 0x6DF, 0, 0x6e, MenuAlwaysEnabled, 0, MapMenu_UnitCommand, 0, 0, 0},

	{ NULL, 0x69A, 0x6DF, 0, 0x6e, MenuAlwaysEnabled, 0, MapMenu_UnitCommand, 0, 0, 0},
	{ NULL, 0x69A, 0x6DF, 0, 0x6e, MenuAlwaysEnabled, 0, MapMenu_UnitCommand, 0, 0, 0},
	{ NULL, 0x69A, 0x6DF, 0, 0x6e, MenuAlwaysEnabled, 0, MapMenu_UnitCommand, 0, 0, 0},
	{ NULL, 0x69A, 0x6DF, 0, 0x6e, MenuAlwaysEnabled, 0, MapMenu_UnitCommand, 0, 0, 0},
	{ NULL, 0x69A, 0x6DF, 0, 0x6e, MenuAlwaysEnabled, 0, MapMenu_UnitCommand, 0, 0, 0},
	{ NULL, 0x69A, 0x6DF, 0, 0x6e, MenuAlwaysEnabled, 0, MapMenu_UnitCommand, 0, 0, 0},
    MenuItemsEnd
};

const struct MenuDef sDebugMenuDef = {
	{1, 1, 0xE, 0},
	0,
	sDebugMenuItems,
	0, 0, 0,
	ItemMenu_ButtonBPressed,
	MenuAutoHelpBoxSelect,
	MenuStdHelpBox
};

/**
 * LynJump
 */
u8 ItemCommandEffect(struct MenuProc *menu, struct MenuItemProc *menuItem)
{
	if (menuItem->availability == MENU_DISABLED)
		return MENU_ACT_SND6B;

	ResetIconGraphics();
	LoadIconPalettes(4);

	StartOrphanMenu(&sDebugMenuDef);
	return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SND6A | MENU_ACT_CLEAR;
}
