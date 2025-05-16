#!/usr/bin/python3
# -*- coding: UTF-8 -*-

import sys
from local_util import *

class SongHeader:
	def __init__(self, rom_data, addr):
		self.trackCount = rom_data[addr + 0]
		self.blockCount = rom_data[addr + 1]
		self.priority = rom_data[addr + 2]
		self.reverb = rom_data[addr + 3]
		self.tone = int.from_bytes(rom_data[addr + 4:addr + 8], 'little')

		self.tracks = {}
		self.tracks[0] = int.from_bytes(rom_data[addr + 0x08:addr + 0x0C], 'little')
		self.tracks[1] = int.from_bytes(rom_data[addr + 0x0C:addr + 0x10], 'little')
		self.tracks[2] = int.from_bytes(rom_data[addr + 0x10:addr + 0x14], 'little')
		self.tracks[3] = int.from_bytes(rom_data[addr + 0x14:addr + 0x18], 'little')
		self.tracks[4] = int.from_bytes(rom_data[addr + 0x18:addr + 0x1C], 'little')
		self.tracks[5] = int.from_bytes(rom_data[addr + 0x1C:addr + 0x20], 'little')
		self.tracks[6] = int.from_bytes(rom_data[addr + 0x20:addr + 0x24], 'little')
		self.tracks[7] = int.from_bytes(rom_data[addr + 0x24:addr + 0x28], 'little')

class ToneData:
	def __init__(self, rom_data, addr):
		self.type = rom_data[addr + 0]
		self.key = rom_data[addr + 1]
		self.length = rom_data[addr + 2]
		self.pan_sweep = rom_data[addr + 3]

		self.wav = int.from_bytes(rom_data[addr + 0x04:addr + 0x08], 'little')

		self.attack = rom_data[addr + 8]
		self.decay = rom_data[addr + 9]
		self.sustain = rom_data[addr + 10]
		self.release = rom_data[addr + 11]

class WaveData:
	def __init__(self, rom_data, addr):
		self.name = f"wav_0x{addr:08X}"
		self.addr = addr

		self.type = ReadU16(rom_data, addr + 0x00)
		self.status = ReadU16(rom_data, addr + 0x02)
		self.freq = ReadU32(rom_data, addr + 0x04)
		self.loopStart = ReadU32(rom_data, addr + 0x08)
		self.size = ReadU32(rom_data, addr + 0x0C)
		self.crc = crc16(rom_data, addr, self.size)

def find_wav_index_by_crc(wav_groups, crc):
	for i, wav in enumerate(wav_groups):
		if wav.crc == crc:
			return i

	return -1

def dump_all_wavs(rom_data, wav_groups):
	for wav in wav_groups:
		print(".align 4")
		print(f"{wav.name}: @ 0x{wav.addr:08X}")
		format_print(f".short 0x{wav.type:04X}", "type")
		format_print(f".short 0x{wav.status:04X}", "status")
		format_print(f".word  0x{wav.freq:08X}", "freq")
		format_print(f".word  0x{wav.loopStart:08X}", "loopStart")
		format_print(f".word  0x{wav.size:08X}", "size")

		print("    .byte ", end=' ')
		for i in range(wav.size):
			print(f"0x{rom_data[wav.addr + 0x10 + i]:02X}", end='')

			if (i + 1) % 16 == 0:
				print("")
				print("    .byte ", end=' ')
			else:
				print(",", end=' ')

		print("")
		print("")


def dump_tone_data(rom_data, addr, name, used_voices, wav_groups):
	# voice group

	addr = addr_filter(addr)

	for voice_idx in used_voices:
		voice = ToneData(rom_data, addr + voice_idx * 0xC)

		if is_rom_u32(voice.wav) and voice.type != 0x80: # voice_keysplit_all
			wav = WaveData(rom_data, addr_filter(voice.wav))

			wav_idx = find_wav_index_by_crc(wav_groups, wav.crc)
			if wav_idx < 0:
				wav_groups.append(wav)
			else:
				wav = wav_groups[wav_idx]

			wav_name = wav.name
		else:
			wav_name = f"0x{voice.wav:08X}"

		print(f"    tone_data 0x{voice.type:02X}, 0x{voice.key:02X}, 0x{voice.length:02X}, 0x{voice.pan_sweep:02X}, {wav_name}, 0x{voice.attack:02X}, 0x{voice.decay:02X}, 0x{voice.sustain:02X}, 0x{voice.release:02X} @ index={voice_idx}")

class SoundTrackCmd:
	def __init__(self, addr, cmd):
		self.addr = addr
		self.cmd  = f"{cmd}"

def get_sorted_voice_index(voices, index):
	for i, voice in enumerate(voices):
		if index == voice:
			return i

	return -1

def dump_sound_track(rom_data, addr, max_len, name, used_voices):

	# print(f"addr=0x{addr:08X}, max_len={max_len:X}")

	cmds = []

	label_index = 0
	labels = {}

	prev = 0

	off = 0
	while True:
		cmd = rom_data[addr + off]

		# https://loveemu.github.io/vgmdocs/Summary_of_GBA_Standard_Sound_Driver_MusicPlayer2000.html

		if cmd < 0x80 and prev > 0:
			cmd = prev
			off = off - 1

		if cmd >= 0x00 and cmd <= 0x7F: # n/a
			cmds.append(SoundTrackCmd(addr + off, f".byte {MML(cmd)}"))
			off = off + 1
		elif cmd >= 0x80 and cmd <= 0xB0: # W00 ～ W96
			cmds.append(SoundTrackCmd(addr + off, f".byte {MML(cmd)}"))
			off = off + 1
		elif cmd == 0xB1: # FINE
			cmds.append(SoundTrackCmd(addr + off, f".byte {MML(cmd)}"))
			off = off + 1
		elif cmd == 0xB2 or cmd == 0xB3 or cmd == 0xB5: # GOTO/PATT/REPT
			if cmd == 0xB2:
				cmds.append(SoundTrackCmd(addr + off, ".byte GOTO"))
			elif cmd == 0xB3:
				cmds.append(SoundTrackCmd(addr + off, ".byte PATT"))
			elif cmd == 0xB5:
				cmds.append(SoundTrackCmd(addr + off, ".byte REPT"))
				off = off + 1

			_adr = addr_filter(ReadU32(rom_data, addr + off + 1))
			if _adr not in labels:
				labels[_adr] = f"label_{name}_{label_index}"
				label_index = label_index + 1

			cmds.append(SoundTrackCmd(addr + off + 1, f".word {labels[_adr]}"))
			off = off + 5
		elif cmd == 0xB4: # PEND
			cmds.append(SoundTrackCmd(addr + off, f".byte {MML(cmd)}"))
			off = off + 1
		elif cmd == 0xB9: # MEMACC
			mem_set = rom_data[addr + off + 1]
			adr = rom_data[addr + off + 2]
			dat = rom_data[addr + off + 3]
			cmds.append(SoundTrackCmd(addr + off, f".byte {MML(cmd)}, {mem_set}, {adr}, {dat}"))
			off = off + 4
			if mem_set > 5:
				dest = ReadU32(addr + off + 4)
				cmds.append(SoundTrackCmd(addr + off, f".word 0x{dest:08X}"))
				off = off + 4
		elif cmd >= 0xBA and cmd <= 0xC8:
			_arg = rom_data[addr + off + 1]

			if cmd == 0xBD: # VOICE
				if get_sorted_voice_index(used_voices, _arg) < 0:
					used_voices.append(_arg)

				_arg = get_sorted_voice_index(used_voices, _arg)

			cmds.append(SoundTrackCmd(addr + off, f".byte {MML(cmd)}, {_arg}"))
			off = off + 2

		elif cmd == 0xCD: # XCMD
			sub_cmd = rom_data[addr + off + 1]
			_arg = rom_data[addr + off + 2]
			cmds.append(SoundTrackCmd(addr + off, f".byte {MML(cmd)}, {sub_cmd}, {_arg}"))
			off = off + 3
		elif cmd == 0xCE: # EOT
			_key = rom_data[addr + off + 1]
			if _key >= 0x80:
				cmds.append(SoundTrackCmd(addr + off, f".byte {MML(cmd)}"))
				off = off + 1
			else:
				cmds.append(SoundTrackCmd(addr + off, f".byte {MML(cmd)}, {_key}"))
				off = off + 2

		elif cmd == 0xCF: # TIE
			_key = rom_data[addr + off + 1]
			velo = rom_data[addr + off + 2]

			if _key >= 0x80:
				cmds.append(SoundTrackCmd(addr + off, f".byte {MML(cmd)}"))
				off = off + 1
			elif velo >= 0x80:
				cmds.append(SoundTrackCmd(addr + off, f".byte {MML(cmd)}, {_key}"))
				off = off + 2
			else:
				cmds.append(SoundTrackCmd(addr + off, f".byte {MML(cmd)}, {_key}, {velo}"))
				off = off + 3

		elif cmd >= 0xD0 and cmd <= 0xFF:
			_key = rom_data[addr + off + 1]
			velo = rom_data[addr + off + 2]
			_gtp = rom_data[addr + off + 3]

			if _key >= 0x80:
				cmds.append(SoundTrackCmd(addr + off, f".byte {MML(cmd)}"))
				off = off + 1
			elif velo >= 0x80:
				cmds.append(SoundTrackCmd(addr + off, f".byte {MML(cmd)}, {_key}"))
				off = off + 2
			elif _gtp >= 0x80:
				cmds.append(SoundTrackCmd(addr + off, f".byte {MML(cmd)}, {_key}, {velo}"))
				off = off + 3
			else:
				cmds.append(SoundTrackCmd(addr + off, f".byte {MML(cmd)}, {_key}, {velo}, {_gtp}"))
				off = off + 4

		if max_len > 0 and off >= max_len:
			break
		elif cmd == 0xB1: # FINE
			break

	for cmd in cmds:
		if cmd.addr in labels:
			print(f"{labels[cmd.addr]}:")
		print(f"    {cmd.cmd}")

	return used_voices

def dump_sound_header(rom_data, addr, name):
	song_header = SongHeader(rom_data, addr)

	format_print(f".byte 0x{song_header.trackCount:02X}", "trackCount")
	format_print(f".byte 0x{song_header.blockCount:02X}", "blockCount")
	format_print(f".byte 0x{song_header.priority:02X}", "priority")
	format_print(f".byte 0x{song_header.reverb:02X}", "reverb")

	# format_print(f".word 0x{song_header.tone:08X}", "tone")
	format_print(f".word {name}_tone", "tone")

	for i in range(song_header.trackCount):
		trace_name = f"{name}_track{i}"
		format_print(f".word {trace_name}", f"tracks 0x{song_header.tracks[i]:08X}")

	return song_header

def dump_one_song(rom_data, addr, name, wav_groups):
	whole_sound_used_voices = []

	print("@ ****************************** header ******************************")
	print(".align 2")
	print(f".global {name}")
	print(f"{name}:")
	song_header = dump_sound_header(rom_data, addr, name)
	print("")
	print("@ ****************************** tracks ******************************")

	for i in range(song_header.trackCount):
		max_len = 0
		if (i < (song_header.trackCount - 1)):
			max_len = song_header.tracks[i + 1] - song_header.tracks[i]

		trace_name = f"{name}_track{i}"

		print(".align 2")
		print(f"{trace_name}:")
		dump_sound_track(rom_data, addr_filter(song_header.tracks[i]), max_len, trace_name, whole_sound_used_voices)
		print("")

	print("@ **************************** voice_group ***************************")
	tone_name = f"{name}_tone"

	print(".align 4")
	print(f"{tone_name}:")
	dump_tone_data(rom_data, song_header.tone, tone_name, whole_sound_used_voices, wav_groups)


def main(args):
	addr = eval(args[0]) & 0x07FFFFFF

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

	sound_name = "this_song"

	dump_one_song(rom_data, addr, sound_name, wav_groups)
	print("")
	print("@ ******************************** WAVs ******************************")
	dump_all_wavs(rom_data, wav_groups)

if __name__ == '__main__':
	main(sys.argv[1:])
