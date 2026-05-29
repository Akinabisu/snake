#pragma once
#include "common.h"
#include "console_flow_controller.h"
#include "direction_controller.h"

class ConsoleDirectionController : public DirectionController {
   private:
    const ConsoleFlowController& _flow_controller;

   public:
    ConsoleDirectionController(const ConsoleFlowController& fc);

    void updateDirection() override;
};