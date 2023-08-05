#include "global.h"
#include "constants/characters.h"
#include "constants/classes.h"

#include "ClassChgExpansion.h"

/* Magic string for FEBuilder patch */
const char PromoJidLutExpaMagic[] = "PromoJidLutExpa";
const u8 gPromoJidLutExpa[0x100][0x4] = {
    [CLASS_MAGE] = {
        CLASS_DRUID,
    },

    [CLASS_EIRIKA_LORD] = {
        CLASS_DRUID
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

static const struct TraineeData gTraineesRe[] = {
    { CHARACTER_ROSS,   10, CLASS_JOURNEYMAN },
    { CHARACTER_AMELIA, 10, CLASS_RECRUIT },
    { CHARACTER_EWAN,   10, CLASS_PUPIL },
    {0}
};

/* Magic string for FEBuilder patch */
const char TraineesReMagic[] = "TraineesRee";
struct TraineeData const * const gpTraineesRe = gTraineesRe;
