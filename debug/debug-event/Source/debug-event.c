#include "gbafe.h"

static const struct UnitDefinition UnitDef_Ally[] = {
	{
		.charIndex = CHARACTER_SETH,
		.classIndex = CLASS_PALADIN,
		.allegiance = FACTION_ID_BLUE,
		.level = 10,
		.xPosition = 8,
		.yPosition = 5,
		.items = {
			ITEM_SWORD_STEEL,
			ITEM_LANCE_BRAVE,
			ITEM_SWORD_RUNESWORD,
			ITEM_VULNERARY,
		},
	},
	{
		.charIndex = CHARACTER_EIRIKA,
		.classIndex = CLASS_EIRIKA_LORD,
		.allegiance = FACTION_ID_BLUE,
		.level = 10,
		.xPosition = 3,
		.yPosition = 4,
		.items = {
			ITEM_SWORD_BRAVE,
			ITEM_SWORD_RAPIER,
			ITEM_VULNERARY,
		},
	},
	{
		.charIndex = CHARACTER_NEIMI,
		.classIndex = CLASS_RANGER,
		.allegiance = FACTION_ID_BLUE,
		.level = 10,
		.xPosition = 4,
		.yPosition = 4,
		.items = {
			ITEM_BOW_IRON,
			ITEM_VULNERARY,
		},
	},
	{
		.charIndex = CHARACTER_NATASHA,
		.classIndex = CLASS_CLERIC,
		.allegiance = FACTION_ID_BLUE,
		.level = 10,
		.xPosition = 5,
		.yPosition = 4,
		.items = {
			ITEM_STAFF_HEAL,
			ITEM_VULNERARY,
		},
	},
	{
		.charIndex = CHARACTER_LUTE,
		.classIndex = CLASS_MAGE,
		.allegiance = FACTION_ID_BLUE,
		.level = 10,
		.xPosition = 5,
		.yPosition = 5,
		.items = {
			ITEM_ANIMA_FIRE,
			ITEM_VULNERARY,
		},
	},
	{
		.charIndex = CHARACTER_ARTUR,
		.classIndex = CLASS_MAGE,
		.allegiance = FACTION_ID_BLUE,
		.level = 10,
		.xPosition = 5,
		.yPosition = 5,
		.items = {
			ITEM_ANIMA_FIRE,
			ITEM_VULNERARY,
		},
	},
	{}
};

static const struct UnitDefinition UnitDef_Enemy[] = {
	{
		.charIndex = CHARACTER_ONEILL,
		.classIndex = CLASS_RANGER,
		.allegiance = FACTION_ID_RED,
		.level = 4,
		.xPosition = 3,
		.yPosition = 3,
		.items = {
			ITEM_SWORD_IRON,
			ITEM_BOW_IRON,
		},
		.ai = { 0, 4, 9, 0 },
	},
	{
		.charIndex = CHARACTER_GLEN,
		.classIndex = CLASS_RANGER,
		.allegiance = FACTION_ID_RED,
		.level = 4,
		.xPosition = 9,
		.yPosition = 5,
		.items = {
			ITEM_SWORD_IRON,
			// ITEM_BOW_IRON,
		},
		.ai = { 0, 4, 9, 0 },
	},
	{
		.charIndex = CHARACTER_ZONTA,
		.classIndex = CLASS_RANGER,
		.allegiance = FACTION_ID_RED,
		.level = 4,
		.xPosition = 8,
		.yPosition = 6,
		.items = {
			ITEM_SWORD_IRON,
			// ITEM_BOW_IRON,
		},
		.ai = { 0, 4, 9, 0 },
	},
	{}
};

static void set_unit_status(void)
{
	struct Unit *unit;
	
	unit = GetUnitFromCharId(CHARACTER_EIRIKA);
	if (unit) {
		unit->ranks[ITYPE_SWORD] = WPN_EXP_A;
		unit->pow = 10;
		unit->maxHP = 70;
		unit->curHP = 30;
	}

	unit = GetUnitFromCharId(CHARACTER_SETH);
	if (unit) {
		unit->pow = 2;
		unit->maxHP = 70;
		unit->curHP = 70;
		unit->spd = 25;
	}

	unit = GetUnitFromCharId(CHARACTER_NEIMI);
	if (unit) {
		unit->pow = 10;
		unit->maxHP = 70;
		unit->curHP = 30;
	}

	unit = GetUnitFromCharId(CHARACTER_ONEILL);
	if (unit) {
		unit->pow = 0;
		unit->maxHP = 70;
		unit->curHP = 30;
	}
}

static const EventScr EventScr_Beginning[] = {
	LOAD1(0x1, UnitDef_Ally)
	ENUN
	LOAD1(0x1, UnitDef_Enemy)
	ENUN

	FADU(16)

	ASMC(set_unit_status)

	NoFade
	ENDA
};

static const EventScr EventScr_Ending[] = {
	MNC4
	ENDA
};

static const EventListScr EventListScr_Turn[] = {
	END_MAIN
};

static const EventListScr EventListScr_Character[] = {
	END_MAIN
};

static const EventListScr EventListScr_Location[] = {
	END_MAIN
};

static const EventListScr EventListScr_Misc[] = {
	DefeatAll(EventScr_Ending)
	CauseGameOverIfLordDies
	END_MAIN
};

static const EventListScr EventListScr_SelectUnit[] = {
	END_MAIN
};

static const EventListScr EventListScr_SelectDestination[] = {
	END_MAIN
};

static const EventListScr EventListScr_UnitMove[] = {
	END_MAIN
};

static void const * const EventListScr_Tutorial[] = {
	NULL
};

static const u8 TrapData_ThisEvent[] = {
	TRAP_NONE
};

static const u8 TrapData_ThisEventHard[] = {
	TRAP_NONE
};

const struct ChapterEventGroup ThisEvent = {
	.turnBasedEvents               = EventListScr_Turn,
	.characterBasedEvents          = EventListScr_Character,
	.locationBasedEvents           = EventListScr_Location,
	.miscBasedEvents               = EventListScr_Misc,
	.specialEventsWhenUnitSelected = EventListScr_SelectUnit,
	.specialEventsWhenDestSelected = EventListScr_SelectDestination,
	.specialEventsAfterUnitMoved   = EventListScr_UnitMove,
	.tutorialEvents                = EventListScr_Tutorial,

	.traps            = TrapData_ThisEvent,
	.extraTrapsInHard = TrapData_ThisEventHard,

	.playerUnitsInNormal = UnitDef_Ally,
	.playerUnitsInHard   = UnitDef_Ally,

	.playerUnitsChoice1InEncounter = NULL,
	.playerUnitsChoice2InEncounter = NULL,
	.playerUnitsChoice3InEncounter = NULL,

	.enemyUnitsChoice1InEncounter = NULL,
	.enemyUnitsChoice2InEncounter = NULL,
	.enemyUnitsChoice3InEncounter = NULL,

	.beginningSceneEvents = EventScr_Beginning,
	.endingSceneEvents    = EventScr_Ending,
};
