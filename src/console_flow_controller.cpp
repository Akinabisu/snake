
#include "console_flow_controller.h"

#include <ctype.h>
#include <curses.h>

bool ConsoleFlowController::wantsToExit() {
    int key = getch();
    if (key != ERR && tolower(key) == 'e') {
        return true;
    }
    if (key != ERR) ungetch(key);
    return false;
}

bool ConsoleFlowController::wantsToRestart() {
    int key = getch();
    if (key != ERR && tolower(key) == 'r') {
        return true;
    }
    if (key != ERR) ungetch(key);
    return false;
}
