#pragma once

#include "global.h"
#include "bmunit.h"
#include "bmitem.h"

static inline s8 IsItemCoveringRange_hook(int item, int range, struct Unit *unit)
{
    return IsItemCoveringRange(item, range);
}
