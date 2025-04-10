.syntax unified
.include "macros.inc"

THUMB_FUNC_START AnimCreateHook
AnimCreateHook:
	movs r0, r4
	movs r1, #0
	strb r1, [r0, #0x13]
	movs r0, r4
	ldr r1, =AnimInsert
	bl bx_r1
	ldr r1, =0x8004FA7
	bx r1

bx_r1:
	bx r1
