#include "game_flow_controller.h"

bool GameFlowController::wantsToExit() const { return _wants_to_exit; }

bool GameFlowController::wantsToRestart() const { return _wants_to_restart; }
