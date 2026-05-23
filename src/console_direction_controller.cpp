#include "console_direction_controller.h"

#include <ctype.h>
#include <ncurses.h>

void ConsoleDirectionController::updateDirection() {
    int key = getch();

    if (key >= 0 && key <= 255) {
        key = tolower(key);
    }

    switch (key) {
        case 'd':
        case KEY_RIGHT:
            if (_current_direction != Direction::Left) {
                _current_direction = Direction::Right;
            }
            break;
        case 's':
        case KEY_DOWN:
            if (_current_direction != Direction::Up) {
                _current_direction = Direction::Down;
            }
            break;
        case 'a':
        case KEY_LEFT:
            if (_current_direction != Direction::Right) {
                _current_direction = Direction::Left;
            }
            break;
        case 'w':
        case KEY_UP:
            if (_current_direction != Direction::Down) {
                _current_direction = Direction::Up;
            }
            break;
        default:
            break;
    }
};