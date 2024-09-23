MK_PATH   := $(abspath $(lastword $(MAKEFILE_LIST)))
MK_DIR    := $(dir $(MK_PATH))

OPANIM_DIR := wizardry/CustomOpAnim
OPANIMTOR  := python3 $(OPANIM_DIR)/script/custom-opanim-creator.py

OPANIM_SCRIPTS  := $(shell find $(OPANIM_DIR) -type f -name '*.opanim.txt')
OPANIM_SCR_DEPS := $(OPANIM_SCRIPTS:.opanim.txt=.opanim.txt.d)
OPANIM_TARGET   := $(OPANIM_SCRIPTS:.opanim.txt=.opanim.event)

%.opanim.event: %.opanim.txt
	@echo "[GEN]	$@"
	@$(OPANIMTOR) $< > $@

%.opanim.txt.d: %.opanim.txt
	@echo -n "$(patsubst %.opanim.txt, %.opanim.event, $<): " > $@
	@$(OPANIMTOR) $< --list-files >> $@

-include $(OPANIM_SCR_DEPS)

CLEAN_FILES += $(OPANIM_SCR_DEPS) $(OPANIM_TARGET)

clean:
	rm -f $(CLEAN_FILES)
