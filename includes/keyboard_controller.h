#pragma once
#include "common.h"

class KeyboardController {
   private:
    Direction _current_direction =
        Direction::Right;  // dont like handling direction in keyboard controller
   public:
    Direction currentDirection();
    void keyListener();
};