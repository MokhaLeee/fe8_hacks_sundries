    .section .rodata
    .align 2, 0

	.global ProcScr_SwingSwordfx
ProcScr_SwingSwordfx:	@ 0x08C02FC8
        @ PROC_CALL
        .short 0x2, 0x0
        .word SwingSwordfx_Init
        @ PROC_SLEEP
        .short 0xe, 0x6
        .word 0x0
        @ PROC_REPEAT
        .short 0x3, 0x0
        .word SwingSwordfx_Loop
        @ PROC_CALL
        .short 0x2, 0x0
        .word StartMidFadeFromBlack
        @ PROC_REPEAT
        .short 0x3, 0x0
        .word WaitForFade
        @ PROC_CALL
        .short 0x2, 0x0
        .word SwingSwordfx_End
        @ PROC_END
        .short 0x0, 0x0
        .word 0x0

	.global gUnk_081C9422
gUnk_081C9422:	@ 0x081C9422
	.incbin "gUnk_081C9422.bin"

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
