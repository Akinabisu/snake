
#include "console_flow_controller.h"

#include <ctype.h>
#include <curses.h>

int ConsoleFlowController::getLastKeyPressed() const { return _last_key_pressed; }

void ConsoleFlowController::updateEvents() {
    _wants_to_restart = false;
    _last_key_pressed = -1;

    int key;

    while ((key = getch()) != ERR) {
        if (key >= 0 && key <= 255) {
            key = tolower(key);
        }

        if (key == 'e') {
            _wants_to_exit = true;
        }

        if (key == 'r') {
            _wants_to_restart = true;
        }

        if (key == 'w' || key == 'a' || key == 's' || key == 'd' || key == KEY_UP ||
            key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT) {
            _last_key_pressed = key;
        }
    }
}

void ConsoleFlowController::exit() { endwin(); }