.thumb

.macro blh to, reg=r4
	ldr \reg, =\to
	mov r14, \reg
	.short 0xF800
.endm

.global BattleGenerateHit_802B894
.type BattleGenerateHit_802B894, %function
BattleGenerateHit_802B894:
    mov r0, r4
    mov r1, r5
    blh BattleGenerateHitHack_802B894, r2
    ldr r4, =gBattleHitIterator
    ldr r0, =0x802B909
    bx r0

.global Wrapper_8B62884
.type Wrapper_8B62884, %function
Wrapper_8B62884:
    mov r0, #0x0 
    strh r0, [r6,#0x4]
    ldr r0, =BattleGenerateHitAttributesLoop_rpt
    mov r7, r0
    ldr r0, =0x8B6288F
    bx r0
