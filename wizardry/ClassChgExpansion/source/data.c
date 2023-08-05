#include "global.h"
#include "constants/characters.h"
#include "constants/classes.h"

#include "ClassChgExpansion.h"

/* Magic string for FEBuilder patch */
const char PromoJidLutExpaMagic[] = "PromoJidLutExpa";
const u8 gPromoJidLutExpa[0x100][0x4] = {
    [CLASS_JOURNEYMAN] = {
        CLASS_JOURNEYMAN_T1,
        CLASS_MAGE,
        CLASS_SHAMAN,
        CLASS_MONK,
    },

    [CLASS_RECRUIT] = {
        CLASS_RECRUIT_T1,
        CLASS_CAVALIER_F,
        CLASS_ARMOR_KNIGHT_F,
        CLASS_PEGASUS_KNIGHT
    },

    [CLASS_PUPIL] = {
        CLASS_PUPIL_T1,
        CLASS_FIGHTER,
        CLASS_BRIGAND
    },

    [CLASS_MAGE] = {
        CLASS_DRUID,
    },

    [CLASS_MAGE_F] = {
        CLASS_VALKYRIE,
    },

    [CLASS_EIRIKA_LORD] = {
        CLASS_SWORDMASTER_F
    },
};

static const struct ClassChgExpaMod gClassChgExpaMods[] = {
    {
        .jid_promo = CLASS_PEGASUS_KNIGHT,
        .jid_old = CLASS_JOURNEYMAN,
        .pid = CHARACTER_AMELIA,
        .item = 0,
        .flag = 0,
    },
    {0}
};

/* Magic string for FEBuilder patch */
const char ClassChgExpaModsMagic[] = "ClassChgExpaMod";
struct ClassChgExpaMod const * const gpClassChgExpaMods = gClassChgExpaMods;

static const struct TraineeDataRe gTraineesRe[] = {
    { CLASS_JOURNEYMAN, 10 },
    { CLASS_RECRUIT, 10 },
    { CLASS_PUPIL, 10 },
    {0}
};

/* Magic string for FEBuilder patch */
const char TraineesReMagic[] = "TraineesRee";
struct TraineeDataRe const * const gpTraineesRe = gTraineesRe;
