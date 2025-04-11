.syntax unified
.include "macros.inc"

THUMB_FUNC_START C10Hook
C10Hook:
	push {r3}
	movs r0, r7
	ldr r1, =Banim_C10
	bl bx_r1
	pop {r3}
	cmp r0, #0
	beq continue_loop
	b break_loop

THUMB_FUNC_START C11Hook
C11Hook:
	push {r3}
	movs r0, r7
	ldr r1, =Banim_C11
	bl bx_r1
	pop {r3}
	cmp r0, #0
	beq continue_loop
	b continue_loop @ break_loop

continue_loop:
	ldr r1, =0x080596CD
	bx r1
break_loop:
	ldr r1, =0x080596D7
	bx r1
bx_r1:
	bx r1
