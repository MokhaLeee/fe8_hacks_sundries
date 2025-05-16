#!/usr/bin/python3
# -*- coding: UTF-8 -*-

import sys
from local_util import *
from dump_sound import *

SONGTABLE_AMT = 0xE8
PR_SONGTABLE  = 0x224470

SKIPPED_SONGS = list(range(1, 0x47)) + [0x54, 0x55, 0x56]

class Song:
	def __init__(self, name, header, ms, me):
		self.header = header
		self.ms = ms
		self.me = me

if __name__ == '__main__':
	# addr = eval(sys.argv[1]) & 0x07FFFFFF

	wav_groups = []

	with open(rom, 'rb') as f:
		rom_data = f.read()

	print(".include \"MPlayDef.s\"")
	print(".section .rodata")

	print("")

	print(".macro tone_data type, key, length, pan_sweep, wav, attack, decay, sustain, release")
	print("    .byte \\type, \\key, \\length, \\pan_sweep")
	print("    .word \\wav")
	print("    .byte \\attack, \\decay, \\sustain, \\release")
	print(".endm")

	print("")

	for i in range(SONGTABLE_AMT):

		if i in SKIPPED_SONGS:
			song = Song("dummy_song", None, 0, 0)
		else:
			song_name = f"song_{i:03X}"
			song_addr   = PR_SONGTABLE + 8 * i

			header = dump_one_song(rom_data, ReadU32(rom_data, song_addr + 0), song_name, wav_groups)
			song = Song(song_name, header, ReadU16(rom_data, song_addr + 4), ReadU16(rom_data, song_addr + 6))

		print("")

	print("")
	print("@ ******************************** WAVs ******************************")
	dump_all_wavs(rom_data, wav_groups)
