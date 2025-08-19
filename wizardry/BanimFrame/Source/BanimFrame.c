#include "gbafe.h"

extern struct BattleAnim const *const pr_BattleAnimTable; // pointer to banim_data
extern struct BattleAnimCharaPal const *const pr_CharaPalTable; // pointer to character_battle_animation_palette_table

extern const u16 MultiPalList[];

static bool IsMultiPaletteAnim(int pos)
{
	int i;
	int bid = gBanimIdx[pos];

	for (i = 0; MultiPalList[i] != 0; i++) {
		if (bid == (MultiPalList[i] - 1))
			return true;
	}

	return false;
}

static int GetUnitStatusIndex(struct Unit *unit)
{
	return unit->statusIndex;
}

void UpdateBanimFrame(void)
{
	const u16 *pal_src;
	int debuff;
	bool is_multi_pal;
	int bid, bid_pal, chara_pal;
	const struct BattleAnimCharaPal *cbapt = pr_CharaPalTable;
	const struct BattleAnim *banim = pr_BattleAnimTable;

	gpImgSheet[1] = NULL;
	gpImgSheet[0] = NULL;

	if (gBanimValid[EKR_POS_L] == true) {
		bid = gBanimIdx[EKR_POS_L];
		bid_pal = gBanimFactionPal[EKR_POS_L];
		is_multi_pal = IsMultiPaletteAnim(EKR_POS_L);

		LZ77UnCompWram(banim[bid].script, gBanimScrLeft);
		gpBanimModesLeft = banim[bid].modes;

		pal_src = (const u16 *)banim[GetBanimPalette(bid, EKR_POS_L)].pal;
		LZ77UnCompWram(pal_src, gBanimPaletteLeft);

		if (is_multi_pal) {
			gpEfxUnitPaletteBackup[EKR_POS_L] = gBanimPaletteLeft;
			CpuFastCopy(gBanimPaletteLeft, PAL_OBJ(OBPAL_EFX_UNIT_L), 0x40);
		} else {
			chara_pal = gBanimUniquePal[EKR_POS_L];
			if (chara_pal != -1) {
				LZ77UnCompWram(cbapt[chara_pal].pal, gBanimPaletteLeft);
				ApplyBanimUniquePalette((u32 *)gBanimPaletteLeft, EKR_POS_L);
			}

			gpEfxUnitPaletteBackup[EKR_POS_L] = &PAL_BUF_COLOR(gBanimPaletteLeft, bid_pal, 0);
			CpuFastCopy(&PAL_BUF_COLOR(gBanimPaletteLeft, bid_pal, 0), PAL_OBJ(OBPAL_EFX_UNIT_L), 0x20);
			CpuFastCopy(gBanimTriAtkPalettes[0], PAL_OBJ(OBPAL_EFX_UNIT_L + 1), 0x20);
		}

		debuff = GetUnitStatusIndex(&gpEkrBattleUnitLeft->unit);
		if (debuff == UNIT_STATUS_PETRIFY || debuff == UNIT_STATUS_13)
			EfxPalModifyPetrifyEffect(gPaletteBuffer, OBPAL_EFX_UNIT_L, is_multi_pal ? 2 : 1);

		EnablePaletteSync();
		LZ77UnCompWram(banim[bid].oam_l, gBanimOaml);
		gBanimOaml[0x57F0 / 4] = 1;
	}

	if (gBanimValid[EKR_POS_R] == true) {
		bid = gBanimIdx[EKR_POS_R];
		bid_pal = gBanimFactionPal[EKR_POS_R];
		chara_pal = gBanimUniquePal[EKR_POS_R];
		is_multi_pal = IsMultiPaletteAnim(EKR_POS_R);

		LZ77UnCompWram(banim[bid].script, gBanimScrRight);
		gpBanimModesRight = banim[bid].modes;

		pal_src = (const u16 *)banim[GetBanimPalette(bid, EKR_POS_R)].pal;
		LZ77UnCompWram(pal_src, gBanimPaletteRight);

		if (is_multi_pal) {
			gpEfxUnitPaletteBackup[EKR_POS_R] = gBanimPaletteRight;
			CpuFastCopy(gBanimPaletteRight, PAL_OBJ(OBPAL_EFX_UNIT_R), 0x40);
		} else {
			if (chara_pal != -1) {
				LZ77UnCompWram(cbapt[chara_pal].pal, gBanimPaletteRight);
				ApplyBanimUniquePalette((u32 *)gBanimPaletteRight, EKR_POS_R);
			}

			gpEfxUnitPaletteBackup[EKR_POS_R] = &PAL_BUF_COLOR(gBanimPaletteRight, bid_pal, 0);
			CpuFastCopy(&PAL_BUF_COLOR(gBanimPaletteRight, bid_pal, 0), PAL_OBJ(OBPAL_EFX_UNIT_R), 0x20);
			CpuFastCopy(gBanimTriAtkPalettes[1], PAL_OBJ(OBPAL_EFX_UNIT_R + 1), 0x20);
		}

		debuff = GetUnitStatusIndex(&gpEkrBattleUnitRight->unit);
		if (debuff == UNIT_STATUS_PETRIFY || debuff == UNIT_STATUS_13)
			EfxPalModifyPetrifyEffect(gPaletteBuffer, OBPAL_EFX_UNIT_R, is_multi_pal ? 2 : 1);

		EnablePaletteSync();
		LZ77UnCompWram(banim[bid].oam_r, gBanimOamr2);
		gBanimOamr2[0x57F0 / 4] = 1;
	}
}
