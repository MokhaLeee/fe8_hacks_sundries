#!/usr/bin/python3
# -*- coding: UTF-8 -*-

import sys
import symbols

# ========================================================================
elf = "fireemblem8.elf"
with open(elf, 'rb') as f:
	_symbols = { addr: name for addr, name in symbols.from_elf(f) }

def try_get_ptr_symbol(val):
	is_symbol = False

	ptr = val

	if ptr > 0x08000000 and ptr < 0x09000000:
		is_symbol = True
	if ptr > 0x02000000 and ptr < 0x02040000:
		is_symbol = True
	if ptr > 0x03000000 and ptr < 0x03008000:
		is_symbol = True

	if ptr not in _symbols:
		is_symbol = False

	if is_symbol == True:
		return _symbols[ptr]
	else:
		return f"0x{val:X}"

# ========================================================================

def dump_one_part(bin_data, offset):
	ToneData_type = bin_data[offset + 0]
	ToneData_key = bin_data[offset + 1]
	ToneData_length = bin_data[offset + 2]
	ToneData_sweep = bin_data[offset + 3]
	duty_cycle = bin_data[offset + 4]
	ToneData_attack = bin_data[offset + 8]
	ToneData_decay = bin_data[offset + 9]
	ToneData_sustain = bin_data[offset + 10]
	ToneData_release = bin_data[offset + 11]

	_ToneData_wav = int.from_bytes(bin_data[offset + 4:offset + 8], 'little')
	ToneData_wav = try_get_ptr_symbol(_ToneData_wav)

	if ToneData_type == 0:
		if (ToneData_length != 0):
			print("error")
		print(f"voice_directsound {ToneData_key}, {ToneData_sweep}, {ToneData_wav}, {ToneData_attack}, {ToneData_decay}, {ToneData_sustain}, {ToneData_release}")
	elif ToneData_type == 1:
		if ToneData_key != 60 or ToneData_length != 0:
			print("error")
		print(f"voice_square_1 {ToneData_sweep}, {duty_cycle}, {ToneData_attack}, {ToneData_decay}, {ToneData_sustain}, {ToneData_release}")
	elif ToneData_type == 0x80:
		print(f"voice_keysplit_all {ToneData_wav}")
	else:
		print(f"{ToneData_type}, {ToneData_key}, {ToneData_length}, {ToneData_sweep}, {ToneData_wav}, {ToneData_attack}, {ToneData_decay}, {ToneData_sustain}, {ToneData_release}")

def main(args):
	bin_fpath = args[0]

	offset = 0

	with open(bin_fpath, 'rb') as f:
		bin_data = f.read()

	while True:
		dump_one_part(bin_data, offset)

		offset = offset + 0xC
		if offset >= 0x600:
			break

if __name__ == '__main__':
	main(sys.argv[1:])
