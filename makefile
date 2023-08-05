CACHE_DIR := .cache_dir
$(shell mkdir -p $(CACHE_DIR) > /dev/null)

FE8_DIR := tools/fe8
FE8_GBA := $(FE8_DIR)/fireemblem8.gba
FE8_ELF := $(FE8_DIR)/fireemblem8.elf
FE8_REF := $(CACHE_DIR)/fe8-ref.s
EXT_REF := lib/fe8-expa.s
FE8_SYM := $(CACHE_DIR)/fe8.sym

MAIN    := wizardry.event
FE8_CHX := fe8-chax.gba

CLEAN_FILES :=
CLEAN_DIRS  := $(CACHE_DIR)
CLEAN_DIRS  += data/Banims/scripts/__pycache__

WIZARDRY_DIR := wizardry
SPRITANS_DIR :=
WRITANS_DIR  :=
GAMEDATA_DIR :=
HACK_DIRS    := $(WIZARDRY_DIR) $(SPRITANS_DIR) $(WRITANS_DIR) $(GAMEDATA_DIR)

# =========
# = Tools =
# =========
TOOLCHAIN ?= $(DEVKITARM)
ifneq (,$(TOOLCHAIN))
  export PATH := $(TOOLCHAIN)/bin:$(PATH)
endif

EXE :=

ifeq ($(shell python3 -c 'import sys; print(int(sys.version_info[0] > 2))'),1)
  PYTHON3 := python3
else
  PYTHON3 := python
endif

PREFIX ?= arm-none-eabi-
CC  := $(PREFIX)gcc
CPP := $(PREFIX)cpp
AS  := $(PREFIX)as
OBJCOPY := $(PREFIX)objcopy

EA_DIR := tools/ea
EA := $(EA_DIR)/ColorzCore$(EXE)

PARSEFILE         := $(EA_DIR)/Tools/ParseFile$(EXE)
PORTRAITFORMATTER := $(EA_DIR)/Tools/PortraitFormatter$(EXE)
PNG2DMP           := $(EA_DIR)/Tools/Png2Dmp$(EXE)
COMPRESS          := $(EA_DIR)/Tools/compress$(EXE)
LYN               := $(EA_DIR)/Tools/lyn$(EXE) -longcalls
EA_DEP            := $(EA_DIR)/ea-dep$(EXE)

PORTRAIT_PROCESS  := $(PYTHON3) tools/pytools/portrait-process.py
TEXT_PROCESS      := $(PYTHON3) tools/pytools/text-process-classic.py
C2EA              := $(PYTHON3) tools/pytools/NMM2CSV/c2ea.py
TMX2EA            := $(PYTHON3) tools/pytools/TMX2EA/tmx2ea.py

ELF2REF           := $(PYTHON3) tools/scripts/elf2ref.py
ELF2SYM           := $(PYTHON3) tools/scripts/elf2sym.py

GRIT              := $(DEVKITPRO)/tools/bin/grit$(EXE)

NOTIFY_PROCESS = @echo "$(notdir $<) => $(notdir $@)"


# ========
# = Main =
# ========
MAIN_DEPS := $(shell $(EA_DEP) $(MAIN) -I $(EA_DIR) --add-missings)

$(FE8_CHX): $(MAIN) $(FE8_GBA) $(FE8_SYM) $(MAIN_DEPS)
	@echo "[GEN]	$@"
	@cp -f $(FE8_GBA) $(FE8_CHX)
	@$(EA) A FE8 -input:$(MAIN) -output:$(FE8_CHX) --nocash-sym || rm -f $(FE8_CHX)
	@cat $(FE8_SYM) >> $(FE8_CHX:.gba=.sym)

CLEAN_FILES += $(FE8_CHX)  $(FE8_CHX:.gba=.sym)


# ==========
# = DECOMP =
# ==========
$(FE8_ELF): FORCE
	@echo "[GEN]	$@"
	@$(MAKE) -s -C $(FE8_DIR)

$(FE8_REF): $(FE8_ELF) $(EXT_REF)
	@echo "[GEN]	$@"
	@$(ELF2REF) $(FE8_ELF) > $(FE8_REF)
	@cat $(EXT_REF) >> $(FE8_REF)

$(FE8_SYM): $(FE8_ELF)
	@echo "[GEN]	$@"
	@$(ELF2SYM) $(FE8_ELF) > $(FE8_SYM)

$(FE8_GBA): $(FE8_ELF)
	@echo "[GEN]	$@"
	@touch $(FE8_GBA)


# ============
# = Wizardry =
# ============
INC_DIRS := include $(FE8_DIR)/include
INC_FLAG := $(foreach dir, $(INC_DIRS), -I $(dir))
LYN_REF := $(FE8_REF:.s=.o)

ARCH    := -mcpu=arm7tdmi -mthumb -mthumb-interwork
CFLAGS  := $(ARCH) $(INC_FLAG) -Wall -Wextra -Wno-unused-parameter -O2 -mtune=arm7tdmi -mlong-calls
ASFLAGS := $(ARCH) $(INC_FLAG)

CDEPFLAGS = -MMD -MT "$*.o" -MT "$*.asm" -MF "$(CACHE_DIR)/$(notdir $*).d" -MP
SDEPFLAGS = --MD "$(CACHE_DIR)/$(notdir $*).d"

%.lyn.event: %.o $(LYN_REF)
	@echo "[LYN]	$<"
	@$(LYN) $< $(LYN_REF) > $@

%.dmp: %.o
	@echo "[OPY]	$<"
	@$(OBJCOPY) -S $< -O binary $@

%.o: %.s
	@echo "[AS ]	$<"
	@$(AS) $(ASFLAGS) $(SDEPFLAGS) -I $(dir $<) $< -o $@

%.o: %.c
	@echo "[CC ]	$<"
	@$(CC) $(CFLAGS) $(CDEPFLAGS) -g -c $< -o $@

%.asm: %.c
	@echo "[CC ]	$<"
	@$(CC) $(CFLAGS) $(CDEPFLAGS) -S $< -o $@ -fverbose-asm

# Avoid make deleting objects it thinks it doesn't need anymore
# Without this make may fail to detect some files as being up to date
.PRECIOUS: %.o;

-include $(wildcard $(CACHE_DIR)/*.d)

CFILES := $(shell find $(HACK_DIRS) -type f -name '*.c')
CLEAN_FILES += $(CFILES:.c=.o) $(CFILES:.c=.asm) $(CFILES:.c=.dmp) # $(CFILES:.c=.lyn.event)

SFILES := $(shell find $(HACK_DIRS) -type f -name '*.s')
CLEAN_FILES += $(SFILES:.s=.o) $(SFILES:.s=.dmp) # $(SFILES:.s=.lyn.event)

# ============
# = Spritans =
# ============
%.4bpp: %.png
	@echo "[GEN]	$@"
	@$(PNG2DMP) $< -o $@

%.gbapal: %.png
	@echo "[GEN]	$@"
	@$(PNG2DMP) $< -po $@ --palette-only

%.lz: %
	@echo "[LZ ]	$<"
	@$(COMPRESS) $< $@

PNG_FILES := $(shell find $(HACK_DIRS) -type f -name '*.png')
# CLEAN_FILES += $(PNG_FILES:.png=.gbapal) $(PNG_FILES:.png=.4bpp) $(PNG_FILES:.png=.4bpp.lz)

# Grit related
%.img.bin %.map.bin %.pal.bin: %.png
	@echo "[GEN]	$@"
	@$(GRIT) $< -gB 4 -gzl -m -mLf -mR4 -mzl -pn 16 -ftb -fh! -o $@

# CLEAN_FILES += $(PNG_FILES:.png=.img.bin) $(PNG_FILES:.png=.map.bin) $(PNG_FILES:.png=.pal.bin)

# ==============
# = MAKE CLEAN =
# ==============
clean:
	@rm -f $(CLEAN_FILES)
	@rm -rf $(CLEAN_DIRS)
#	@$(MAKE) -s -C $(FE8_DIR) clean
	@echo "[RM]	$(CLEAN_FILES) $(CLEAN_DIRS)"

FORCE:
