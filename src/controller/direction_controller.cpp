#include "direction_controller.h"

Direction DirectionController::currentDirection() { return _current_direction; }

void DirectionController::setDirection(Direction new_direction) {
    _current_direction = new_direction;
}
