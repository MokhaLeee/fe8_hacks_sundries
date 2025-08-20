#include "gbafe.h"

static bool IsMultiPaletteAnim1(int pos)
{
	int i;
	const u32 *scr_base;
	const u8 *oam_base;

	if (pos == POS_L) {
		scr_base = (const u32 *)gBanimScrLeft;
		oam_base = (const u8 *)gBanimOaml;
	} else {
		scr_base = (const u32 *)gBanimScrRight;
		oam_base = (const u8 *)gBanimOamr2;
	}

	for (i = 0; ; i++) {
		const u32 *scr_cur = scr_base + 3 * i;
		u32 inst = scr_cur[0];

		if (ANINS_GET_TYPE(inst) == ANIM_INS_TYPE_FRAME) {
			// Found it!
			int oam_offset = scr_cur[2];
			const u16 *frame_oam = (const u16 *)(oam_base + oam_offset);

			// We need to make sure all pal are 0
			int j;

			for (j = 0; ; j = j + 6) {
				int oam2, oam2_pal;

				if (frame_oam[j + 0] == 1)
					break;

				oam2 = frame_oam[j + 2];
				oam2_pal = oam2 >> 12;

				if (oam2_pal == 1)
					return true;
			}
			return false;
		}
	}

	return false;
}

#if 0
static bool IsMultiPaletteAnim2(int pos)
{
	int i;
	const u16 *oam_base;

	if (pos == POS_L)
		oam_base = (const u16 *)gBanimOaml;
	else
		oam_base = (const u16 *)gBanimOamr2;

	for (i = 0; ; i++) {
		const u16 *oam_cur = oam_base + i * 6;
		u16 oam0 = oam_cur[0];
		u16 oam1 = oam_cur[1];

		// ANIM_SPRITE_END
		if (oam0 == 1)
			continue;

		// ANIM_SPRITE_AFFIN
		if (oam1 == 0xFFFF)
			continue;

		if (oam0 & OAM0_256COLORS)
			return true;
		else
			return false;
	}

	return false;
}
#endif

extern const u16 MultiPalList[];

static bool IsMultiPaletteAnim3(int pos)
{
	int i;
	int bid = gBanimIdx[pos];

	for (i = 0; MultiPalList[i] != 0; i++) {
		if (bid == (MultiPalList[i] - 1))
			return true;
	}

	return false;
}

bool IsMultiPaletteAnim(int pos)
{
	bool ret;
	// return IsMultiPaletteAnim2(pos);
	ret = IsMultiPaletteAnim1(pos);
	if (ret == true)
		return true;

	ret = IsMultiPaletteAnim3(pos);
	if (ret == true)
		return true;

	return false;
}
