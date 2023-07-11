.thumb

.include "macros.inc"

THUMB_FUNC_START C0E_Hook
C0E_Hook:
    mov r0, r7
    blh BanimCmd_FakeHitRed
    ldr r0, =0x080596CC + 1
    bx r0

THUMB_FUNC_START C0F_Hook
C0F_Hook:
    mov r0, r7
    blh BanimCmd_FakeHitBlack
    ldr r0, =0x080596CC + 1
    bx r0

THUMB_FUNC_START C16_Hook
C16_Hook:
    mov r0, r7
    blh BanimCmd_CallDK
    ldr r0, =0x080596CC + 1
    bx r0

THUMB_FUNC_START C17_Hook
C17_Hook:
    mov r0, r7
    blh BanimCmd_CallDuma
    ldr r0, =0x080596CC + 1
    bx r0
