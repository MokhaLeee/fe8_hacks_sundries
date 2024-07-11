	.include "macros.inc"
	.syntax unified

    .section .text

	thumb_func_start SwingSwordfx_Init
SwingSwordfx_Init: @ 0x080215E0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r3, _08021610 @ =gPaletteBuffer
	ldr r2, _08021614 @ =0x00007FFF
	adds r1, r3, #0
	adds r1, #0x42
	movs r0, #0xe
_080215EE:
	strh r2, [r1]
	adds r1, #2
	subs r0, #1
	cmp r0, #0
	bge _080215EE
	movs r4, #0
	ldr r0, _08021614 @ =0x00007FFF
	strh r0, [r3]
	blh EnablePaletteSync
	adds r0, r5, #0
	adds r0, #0x4c
	strh r4, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08021610: .4byte gPaletteBuffer
_08021614: .4byte 0x00007FFF

	thumb_func_start SwingSwordfx_Loop
SwingSwordfx_Loop: @ 0x08021618
	push {r4, r5, r6, lr}
	sub sp, #0x50
	adds r5, r0, #0
	ldr r1, _08021670 @ =gUnk_081C9422
	mov r0, sp
	movs r2, #0x50
	blh memcpy
	ldr r1, _08021674 @ =gPaletteBuffer
	movs r0, #0
	strh r0, [r1]
	movs r2, #1
	adds r4, r5, #0
	adds r4, #0x4c
	adds r3, r4, #0
	adds r1, #0x5e
_08021638:
	movs r6, #0
	ldrsh r0, [r3, r6]
	adds r0, r0, r2
	subs r0, #1
	lsls r0, r0, #1
	add r0, sp
	ldrh r0, [r0]
	strh r0, [r1]
	subs r1, #2
	adds r2, #1
	cmp r2, #0xf
	ble _08021638
	blh EnablePaletteSync
	ldrh r0, [r4]
	adds r0, #3
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc
	ble _08021668
	adds r0, r5, #0
	blh Proc_Break
_08021668:
	add sp, #0x50
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08021670: .4byte gUnk_081C9422
_08021674: .4byte gPaletteBuffer

	thumb_func_start SwingSwordfx_End
SwingSwordfx_End: @ 0x08021678
	push {lr}
	ldr r2, _0802169C @ =gLCDControlBuffer
	movs r0, #1
	ldrb r1, [r2, #1]
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	movs r1, #8
	orrs r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #1]
	blh ClearBg0Bg1
	pop {r0}
	bx r0
	.align 2, 0
_0802169C: .4byte gLCDControlBuffer

	thumb_func_start StartSwingSwordfx
StartSwingSwordfx: @ 0x080216A0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08021728 @ =Img_SwingSword
	ldr r1, _0802172C @ =0x06005000
	blh Decompress
	ldr r0, _08021730 @ =Pal_SwingSword
	movs r1, #0x40
	movs r2, #0x20
	blh CopyToPaletteBuffer
	ldr r0, _08021734 @ =Tsa_SwingSword
	ldr r4, _08021738 @ =gGenericBuffer
	adds r1, r4, #0
	blh Decompress
	ldr r0, _0802173C @ =gBG0TilemapBuffer + 0x4
	movs r2, #0x8a
	lsls r2, r2, #6
	adds r1, r4, #0
	blh CallARM_FillTileRect
	movs r0, #1
	blh BG_EnableSync
	ldr r3, _08021740 @ =gLCDControlBuffer
	movs r0, #1
	ldrb r1, [r3, #1]
	orrs r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #2
	ands r0, r1
	subs r1, #4
	ands r0, r1
	subs r1, #8
	ands r0, r1
	strb r0, [r3, #1]
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2]
	adds r1, r3, #0
	adds r1, #0x44
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	ldr r0, _08021744 @ =0x0000FFE0
	ldrh r1, [r3, #0x3c]
	ands r0, r1
	ldr r1, _08021748 @ =0x0000E0FF
	ands r0, r1
	strh r0, [r3, #0x3c]
	ldr r0, _0802174C @ =ProcScr_SwingSwordfx
	adds r1, r5, #0
	blh Proc_StartBlocking
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08021728: .4byte Img_SwingSword
_0802172C: .4byte 0x06005000
_08021730: .4byte Pal_SwingSword
_08021734: .4byte Tsa_SwingSword
_08021738: .4byte gGenericBuffer
_0802173C: .4byte gBG0TilemapBuffer + 0x4
_08021740: .4byte gLCDControlBuffer
_08021744: .4byte 0x0000FFE0
_08021748: .4byte 0x0000E0FF
_0802174C: .4byte ProcScr_SwingSwordfx
