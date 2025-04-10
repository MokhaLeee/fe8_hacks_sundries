.syntax unified
.include "macros.inc"

THUMB_FUNC_START KakudaiFix
KakudaiFix:
@ 0x56984
ldr r1, =BanimDefaultModeConfig
lsls r0, r2, #2
adds r0, r0, r1
ldrb r6, [r0]

@ switch mode
cmp r6, #8
beq 1f
cmp r6, #9
beq 1f
cmp r6, #10
beq 1f
b 2f

1:
movs r6, #8

2:
ldr r0, =0x0805698D
bx r0
