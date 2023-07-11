mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))

AAA := python3 $(mkfile_dir)/scripts/AAA.py

SOURCE_DIR := source
ALL_SOURCE_BANIM := $(shell find $(SOURCE_DIR) -type f -name '*.txt')
ALL_TARGET_BANIM := $(ALL_SOURCE_BANIM:.txt=Installer.event)

all: $(ALL_TARGET_BANIM)

%Installer.event: %.txt
	$(AAA) $<

clean:
	rm -f $(ALL_TARGET_BANIM)
