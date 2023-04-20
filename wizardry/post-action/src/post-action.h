#pragma once

#include "global.h"
#include "proc.h"

struct ProcPostAction {
    PROC_HEADER;
    int num;
};

typedef void (*PostActionFunc)(struct ProcPostAction *proc);

void PostActionExecInoriItem(struct ProcPostAction *proc);
