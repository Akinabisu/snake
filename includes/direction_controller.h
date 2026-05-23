#pragma once
#include "common.h"

class DirectionController {
   protected:
    Direction _current_direction = Direction::Right;

   public:
    Direction currentDirection();
    virtual void updateDirection() = 0;
};