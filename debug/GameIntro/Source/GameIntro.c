#include "gbafe.h"

void OpAnimfxTerminatorMain(struct Proc *proc)
{
	if (1) {
		SetNextGameActionId(GAME_ACTION_USR_SKIPPED);
		gOpAnimSt.pal = 0;
		Proc_Goto(proc->proc_parent, 99);
	}
}
