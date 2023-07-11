.thumb

.include "macros.inc"

THUMB_FUNC_START EfxDragonSetBgPriorityASM
EfxDragonSetBgPriorityASM:
    push {lr}
    ldr r2, =gLCDControlBuffer

    @ gLCDControlBuffer.bg0cnt.priority = 0;
    ldr r0, [r2, #0xC]
    ldr r1, =0xFFFFFFFC
    and r0, r0, r1
    str r0, [r2, #0xC]

    @ gLCDControlBuffer.bg1cnt.priority = 1;
    ldr r0, [r2, #0x10]
    ldr r1, =0xFFFFFFFC
    and r0, r0, r1
    mov r1, #0x1
    orr r0, r0, r1
    str r0, [r2, #0x10]

    @ gLCDControlBuffer.bg2cnt.priority = 3;
    ldr r0, [r2, #0x14]
    ldr r1, =0xFFFFFFFC
    and r0, r0, r1
    mov r1, #0x3
    orr r0, r0, r1
    str r0, [r2, #0x14]

    @ gLCDControlBuffer.bg3cnt.priority = 2;
    ldr r0, [r2, #0x18]
    ldr r1, =0xFFFFFFFC
    and r0, r0, r1
    mov r1, #0x2
    orr r0, r0, r1
    str r0, [r2, #0x18]

    pop {pc}
