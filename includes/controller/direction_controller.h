#pragma once
#include "common.h"

class DirectionController {
   protected:
    Direction _current_direction = Direction::Right;

   public:
    virtual ~DirectionController() = default;

    Direction currentDirection();
    virtual void updateDirection() = 0;
    void setDirection(Direction new_direction);
};