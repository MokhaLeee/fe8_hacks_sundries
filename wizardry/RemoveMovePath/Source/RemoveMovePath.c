#include "gbafe.h"

/* LynJump */
void PlayerPhase_DisplayUnitMovement(void)
{
#if 0
    GetMovementScriptFromPath();
#else
    GenerateBestMovementScript(gBmSt.playerCursor.x, gBmSt.playerCursor.y, gWorkingMovementScript);
#endif

    UnitApplyWorkingMovementScript(gActiveUnit, gActiveUnit->xPos, gActiveUnit->yPos);
    SetAutoMuMoveScript(gWorkingMovementScript);
}

/* LynJump */
void DrawUpdatedPathArrow(void) {
#if 0
    UpdatePathArrowWithCursor();
    DrawPathArrow();
#endif
}
