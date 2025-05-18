.macro music_player info_struct, track_struct, unknown_1, unknown_2
.4byte \info_struct
.4byte \track_struct
.byte \unknown_1
.space 1
.2byte \unknown_2
.endm

	.equiv TRACK_SIZE, 0x50
	.equiv NUM_TRACKS_BGM1, 8
	.equiv NUM_TRACKS_BGM2, 8
	.equiv NUM_TRACKS_SE1_SYS1, 2
	.equiv NUM_TRACKS_SE2_SYS2, 2
	.equiv NUM_TRACKS_SE3_BMP1, 4
	.equiv NUM_TRACKS_SE4_BMP2, 4
	.equiv NUM_TRACKS_SE5_BMP3, 5
	.equiv NUM_TRACKS_SE6_BMP4, 4
	.equiv NUM_TRACKS_SE7_EVT, 2

	.section .rodata

	.align 2
	.global reloc_gMPlayTable
reloc_gMPlayTable:
	music_player gMPlayInfo_BGM1, gMPlayTrack_BGM1, NUM_TRACKS_BGM1, 0
	music_player gMPlayInfo_BGM2, gMPlayTrack_BGM2, NUM_TRACKS_BGM2, 0
	music_player gMPlayInfo_SE1_SYS1, gMPlayTrack_SE1_SYS1, NUM_TRACKS_SE1_SYS1, 1
	music_player gMPlayInfo_SE2_SYS2, gMPlayTrack_SE2_SYS2, NUM_TRACKS_SE2_SYS2, 1
	music_player gMPlayInfo_SE3_BMP1, gMPlayTrack_SE3_BMP1, NUM_TRACKS_SE3_BMP1, 1
	music_player gMPlayInfo_SE4_BMP2, gMPlayTrack_SE4_BMP2, NUM_TRACKS_SE4_BMP2, 1
	music_player gMPlayInfo_SE5_BMP3, gMPlayTrack_SE5_BMP3, NUM_TRACKS_SE5_BMP3, 1
	music_player gMPlayInfo_SE6_BMP4, gMPlayTrack_SE6_BMP4, NUM_TRACKS_SE6_BMP4, 1
	music_player gMPlayInfo_SE7_EVT, gMPlayTrack_SE7_EVT, NUM_TRACKS_SE7_EVT, 1
