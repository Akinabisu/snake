#pragma once
#include "common.h"
#include "game_flow_controller.h"

class ConsoleFlowController : public GameFlowController {
    int _last_key_pressed = -1;

   public:
    int getLastKeyPressed() const;

    void updateEvents() override;
    void exit() override;
};