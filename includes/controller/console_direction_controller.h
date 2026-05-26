#pragma once
#include "common.h"
#include "console_flow_controller.h"
#include "direction_controller.h"

class ConsoleDirectionController : public DirectionController {
   private:
    const ConsoleFlowController& _flow;

   public:
    ConsoleDirectionController(const ConsoleFlowController& flow_controller);
    void updateDirection() override;
};