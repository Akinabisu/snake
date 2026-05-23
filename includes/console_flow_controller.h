#pragma once
#include "common.h"
#include "game_flow_controller.h"

class ConsoleFlowController : public GameFlowController {
   public:
    bool wantsToExit() override;

    bool wantsToRestart() override;
};