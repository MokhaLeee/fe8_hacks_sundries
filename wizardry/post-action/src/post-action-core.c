#include "global.h"
#include "post-action.h"
#include "bmunit.h"
#include "bmtrap.h"
#include "proc.h"

enum {
    POST_ACTION_PROC_LABEL_LOOP,
    POST_ACTION_PROC_LABEL_END
};

const PostActionFunc PostActionFuncLut[] = {
    PostActionExecInoriItem,

    (PostActionFunc)HandlePostActionTraps,
    NULL,
};

void Exec_PostActionHooks(struct ProcPostAction *proc)
{
    PostActionFunc it = PostActionFuncLut[proc->num++];

    if (!it) {
        Proc_Goto(proc, POST_ACTION_PROC_LABEL_END);
        return;
    }

    it(proc);
}

const struct ProcCmd ProcScr_PostActionHook[] = {
    PROC_YIELD,

PROC_LABEL(POST_ACTION_PROC_LABEL_LOOP),
    PROC_CALL(Exec_PostActionHooks),
    PROC_YIELD,
    PROC_GOTO(POST_ACTION_PROC_LABEL_LOOP),

PROC_LABEL(POST_ACTION_PROC_LABEL_END),
    PROC_END
};

void PostActionHook(ProcPtr parent)
{
    struct ProcPostAction *proc = Proc_StartBlocking(ProcScr_PostActionHook, parent);
    proc->num = 0;
}
