#!/usr/bin/python3
# -*- coding: UTF-8 -*-

rom = "fe8.gba"

def debug_print(fmt):
	# print(fmt)
	pass

def format_print(fmt, comment):
	print("    " + f"{fmt}".ljust(32) + f"@ {comment}")

def ReadU32(rom_data, addr):
	b0 = rom_data[addr + 0]
	b1 = rom_data[addr + 1]
	b2 = rom_data[addr + 2]
	b3 = rom_data[addr + 3]
	return (b0 | (b1 << 8) | (b2 << 16) | (b3 << 24))

def ReadU16(rom_data, addr):
	b0 = rom_data[addr + 0]
	b1 = rom_data[addr + 1]
	return (b0 | (b1 << 8))

def addr_filter(addr):
	return addr & 0x07FFFFFF

def is_rom_u32(addr):
	if addr < 0x08000000:
		return False

	if addr > 0x0A000000:
		return False

	if (addr & 0x03) != 0:
		return False

	return True

def crc16(rom_data, addr, size):
	off = 0

	add_acc = 0
	xor_acc = 0

	while True:
		left = size - off

		if left == 1:
			data = rom_data[addr + off]
		else:
			data = ReadU16(rom_data, addr + off)

		add_acc = add_acc + data
		xor_acc = xor_acc ^ data

		off = off + 2
		if off >= size:
			break

	return (add_acc + xor_acc)


_MML = {
	0x80: "W00",
	0x81: "W01",
	0x82: "W02",
	0x83: "W03",
	0x84: "W04",
	0x85: "W05",
	0x86: "W06",
	0x87: "W07",
	0x88: "W08",
	0x89: "W09",
	0x8A: "W10",
	0x8B: "W11",
	0x8C: "W12",
	0x8D: "W13",
	0x8E: "W14",
	0x8F: "W15",
	0x90: "W16",
	0x91: "W17",
	0x92: "W18",
	0x93: "W19",
	0x94: "W20",
	0x95: "W21",
	0x96: "W22",
	0x97: "W23",
	0x98: "W24",
	0x99: "W28",
	0x9A: "W30",
	0x9B: "W32",
	0x9C: "W36",
	0x9D: "W40",
	0x9E: "W42",
	0x9F: "W44",
	0xA0: "W48",
	0xA1: "W52",
	0xA2: "W54",
	0xA3: "W56",
	0xA4: "W60",
	0xA5: "W64",
	0xA6: "W66",
	0xA7: "W68",
	0xA8: "W72",
	0xA9: "W76",
	0xAA: "W78",
	0xAB: "W80",
	0xAC: "W84",
	0xAD: "W88",
	0xAE: "W90",
	0xAF: "W92",
	0xB0: "W96",
	0xB1: "FINE",
	0xB2: "GOTO",
	0xB3: "PATT",
	0xB4: "PEND",
	0xB5: "REPT",
	0xB9: "MEMACC",
	0xBA: "PRIO",
	0xBB: "TEMPO",
	0xBC: "KEYSH",
	0xBD: "VOICE",
	0xBE: "VOL",
	0xBF: "PAN",
	0xC0: "BEND",
	0xC1: "BENDR",
	0xC2: "LFOS",
	0xC3: "LFODL",
	0xC4: "MOD",
	0xC5: "MODT",
	0xC8: "TUNE",
	0xCD: "XCMD",
	0x08: "xIECV",
	0x09: "xIECL",
	0xCE: "EOT",
	0xCF: "TIE",
	0xD0: "N01",
	0xD1: "N02",
	0xD2: "N03",
	0xD3: "N04",
	0xD4: "N05",
	0xD5: "N06",
	0xD6: "N07",
	0xD7: "N08",
	0xD8: "N09",
	0xD9: "N10",
	0xDA: "N11",
	0xDB: "N12",
	0xDC: "N13",
	0xDD: "N14",
	0xDE: "N15",
	0xDF: "N16",
	0xE0: "N17",
	0xE1: "N18",
	0xE2: "N19",
	0xE3: "N20",
	0xE4: "N21",
	0xE5: "N22",
	0xE6: "N23",
	0xE7: "N24",
	0xE8: "N28",
	0xE9: "N30",
	0xEA: "N32",
	0xEB: "N36",
	0xEC: "N40",
	0xED: "N42",
	0xEE: "N44",
	0xEF: "N48",
	0xF0: "N52",
	0xF1: "N54",
	0xF2: "N56",
	0xF3: "N60",
	0xF4: "N64",
	0xF5: "N66",
	0xF6: "N68",
	0xF7: "N72",
	0xF8: "N76",
	0xF9: "N78",
	0xFA: "N80",
	0xFB: "N84",
	0xFC: "N88",
	0xFD: "N90",
	0xFE: "N92",
	0xFF: "N96"
}

def MML(cmd):
	if cmd in _MML:
		return _MML[cmd]

	return f"0x{cmd:02X}"
