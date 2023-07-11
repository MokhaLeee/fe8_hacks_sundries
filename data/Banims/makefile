mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))
build_dir := $(pwd)

AAA := python3 $(mkfile_dir)scripts/AAA.py

SOURCE_DIR := source
ALL_SOURCE_BANIM := $(shell find $(SOURCE_DIR) -type f -name '*.txt')
ALL_TARGET_BANIM := $(ALL_SOURCE_BANIM:.txt=Installer.event)

all: $(ALL_TARGET_BANIM)

%Installer.event: %.txt
	cd $(dir $<) && $(AAA) $(notdir $<) && cd $(build_dir)

clean:
	rm -f $(ALL_TARGET_BANIM)
