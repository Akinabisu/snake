#pragma once
#include "common.h"
#include "direction_controller.h"

class ConsoleDirectionController : public DirectionController {
   public:
    void updateDirection() override;
};