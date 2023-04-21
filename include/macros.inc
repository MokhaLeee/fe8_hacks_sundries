#ifndef WIZARDRY_MACRO
#define WIZARDRY_MACRO

.macro blh to, reg=r4
	ldr \reg, =\to
	mov r14, \reg
	.short 0xF800
.endm

#endif
