.thumb

.macro blh to, reg=r4
	push {\reg}
	ldr \reg, =\to
	mov r14, \reg
	pop {\reg}
	.short 0xF800
.endm

.global BattleGenerateHit_802B894
.type BattleGenerateHit_802B894, %function
BattleGenerateHit_802B894:
    mov r0, r4
    mov r1, r5
    blh BattleGenerateHitHack

    ldr r4, =gBattleHitIterator
    ldr r0, =0x802B909
    bx r0
