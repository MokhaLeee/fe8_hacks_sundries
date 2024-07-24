    .section .rodata
    .align 2, 0

    .align 2, 0
	.global Img_SwingSword
Img_SwingSword:	@ 0x081BEF28
	.incbin "gfx.bin", 0x1BEF28 - 0x1BEF28, 0x1BF2E0 - 0x1BEF28

	.global Pal_SwingSword
Pal_SwingSword:	@ 0x081BF2E0
	.incbin "gfx.bin", 0x1BF2E0 - 0x1BEF28, 0x1BF4E0 - 0x1BF2E0

	.global Tsa_SwingSword
Tsa_SwingSword:	@ 0x081BF4E0
	.incbin "gfx.bin", 0x1BF4E0 - 0x1BEF28, 0x1BF61C - 0x1BF4E0
