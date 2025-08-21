#!/bin/python3

import os, sys, struct
import array
from PIL import Image
import lzss_lib

BANIM_MODES = {
	0: "NORMAL_ATK",
	1: "NORMAL_ATK_PRIORITY_L",
	2: "CRIT_ATK",
	3: "CRIT_ATK_PRIORITY_L",
	4: "RANGED_ATK",
	5: "RANGED_CRIT_ATK",
	6: "CLOSE_DODGE",
	7: "RANGED_DODGE",
	8: "STANDING",
	9: "STANDING2",
	10: "RANGED_STANDING",
	11: "MISSED_ATK"
}

def main(args):
	try:
		rom  = args[1]
		addr = eval(args[2])
	except IndexError:
		sys.exit(f"Usage: {args[0]} rom addr")

	off = addr & 0x01FFFFFF

	with open(rom, 'rb') as f:
		f.seek(addr)
		data = f.read(32)

	abbr, modes, script, oam_r, oam_l, pal = struct.unpack('12s 5I', data)

	print(f"abbr={abbr}, mode=0x{modes:08X}, script=0x{script:08X}, oam_r=0x{oam_r:08X}, oam_l=0x{oam_l:08X}, pal=0x{pal:08X}")

if __name__ == '__main__':
	main(sys.argv)
