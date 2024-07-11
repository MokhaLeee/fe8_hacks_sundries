    .section .rodata

	.global Img_EventSnowStormfx
Img_EventSnowStormfx:	@ 0x08198D98
	.incbin "gfx.bin", 0x198D98 - 0x198D98, 0x199250 - 0x198D98

	.global Pal_EventSnowStormfx
Pal_EventSnowStormfx:	@ 0x08199250
	.incbin "gfx.bin", 0x199250 - 0x198D98, 0x199290 - 0x199250

	.global Tsa_EventSnowStormfx
Tsa_EventSnowStormfx:	@ 0x08199290
	.incbin "gfx.bin", 0x199290 - 0x198D98, 0x199A94 - 0x199290
