.thumb

.global RemoveHack_B51244
.type RemoveHack_B51244, %function
RemoveHack_B51244:
    ldr r2, =gpRemoveCounter
    ldr r2, [r2]
    ldrb r1, [r2]
    add r1, #1
    strb r1, [r2]
    cmp r1, #5
    bge 1f

    ldr r0, [r4,#0x0C]
    mov r1, #0x42
    mvn r1, r1
    and r0, r1
    str r0, [r4,#0x0C]

    ldr r0, =0x8B5124D
    bx r0

1:
    ldr r0, =0x8B51269
    bx r0
