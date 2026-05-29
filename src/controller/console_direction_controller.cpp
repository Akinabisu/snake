#include "console_direction_controller.h"

#include <ctype.h>
#include <ncurses.h>

ConsoleDirectionController::ConsoleDirectionController(const ConsoleFlowController& fc)
    : _flow_controller(fc) {}

void ConsoleDirectionController::updateDirection() {
    int key = _flow_controller.getLastKeyPressed();

    if (key == -1) return;

    if (key >= 0 && key <= 255) {
        key = tolower(key);
    }

    switch (key) {
        case 'd':
        case KEY_RIGHT:
            if (_current_direction != Direction::Left) _current_direction = Direction::Right;
            break;
        case 's':
        case KEY_DOWN:
            if (_current_direction != Direction::Up) _current_direction = Direction::Down;
            break;
        case 'a':
        case KEY_LEFT:
            if (_current_direction != Direction::Right) _current_direction = Direction::Left;
            break;
        case 'w':
        case KEY_UP:
            if (_current_direction != Direction::Down) _current_direction = Direction::Up;
            break;
    }
}