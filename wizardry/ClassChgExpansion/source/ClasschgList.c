#include "global.h"
#include "bmunit.h"
#include "constants/classes.h"

#include "ClassChgExpansion.h"

int GetClasschgList(struct Unit * unit, u16 item, u8 * out, int len)
{
    int i, ret, amt = 0;
    const GetClasschgListFunc_t * it;
    u8 tmp_list[0x10];
    u8 * cur;

    if (!UNIT_IS_VALID(unit))
        return 0;

    CpuFill16(0, tmp_list, sizeof(tmp_list));

    for (it = gGetClasschgListFuncs, cur = tmp_list; *it; it++)
    {
        ret = (*it)(unit, item, cur, len);

        if (ret > len)
            ret = len;

        amt += ret;
        cur += ret;

        len -= ret;
        if (len <= 0)
            break;
    }

    if (out)
    {
        if (amt > len)
            amt = len;

        for (i = 0; i < amt; i++)
            out[i] = tmp_list[i];
    }

    return amt;
}

int GetClasschgListPadFunc(struct Unit * unit, u16 item, u8 * out, int len)
{
    return 0;
}
