.syntax unified
.include "macros.inc"

THUMB_FUNC_START FE7J_sub_80780E0
FE7J_sub_80780E0:
	push {r7, lr}
	sub sp, #0xc
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
	movs r0, #0
	str r0, [r7, #8]
_080780EE:
	ldr r0, [r7, #8]
	cmp r0, #0x9f
	ble _080780F6
	b _08078124
_080780F6:
	ldr r0, [r7, #8]
	adds r1, r0, #0
	lsls r0, r1, #1
	ldr r2, _08078120 @ =gManimActiveScanlineBuf
	ldr r1, [r2]
	adds r0, r0, r1
	ldr r2, [r7, #8]
	adds r1, r2, #0
	movs r2, #1
	ands r1, r2
	ldr r3, [r7, #8]
	asrs r2, r3, #1
	adds r1, r1, r2
	adds r2, r1, #0
	rsbs r1, r2, #0
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, [r7, #8]
	adds r1, r0, #1
	str r1, [r7, #8]
	b _080780EE
	.align 2, 0
_08078120: .4byte gManimActiveScanlineBuf
_08078124:
	blh SwapScanlineBufs
	add sp, #0xc
	pop {r7}
	pop {r0}
	bx r0

	thumb_func_start FE7J_HBlank_Scanline_8078098
FE7J_HBlank_Scanline_8078098: @ 0x08078098
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	adds r0, r7, #0
	ldr r1, _080780D4 @ =0x04000006
	ldrh r2, [r1]
	adds r1, r2, #1
	adds r2, r1, #0
	strh r2, [r0]
	adds r0, r7, #0
	ldrh r1, [r0]
	cmp r1, #0x9f
	bls _080780B8
	adds r0, r7, #0
	movs r1, #0
	strh r1, [r0]
_080780B8:
	ldr r0, _080780D8 @ =0x0400001A
	adds r1, r7, #0
	ldrh r2, [r1]
	adds r3, r2, #0
	lsls r1, r3, #1
	ldr r3, _080780DC @ =gManimActiveScanlineBuf
	ldr r2, [r3]
	adds r1, r1, r2
	ldrh r2, [r1]
	strh r2, [r0]
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
_080780D4: .4byte 0x04000006
_080780D8: .4byte 0x0400001A
_080780DC: .4byte gManimActiveScanlineBuf
