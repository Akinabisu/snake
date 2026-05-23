#include "gui_flow_controller.h"

bool GuiFlowController::wantsToExit() {
    return _window.hasFocus() && sf::Keyboard::isKeyPressed(sf::Keyboard::E);
}

bool GuiFlowController::wantsToRestart() {
    return _window.hasFocus() && sf::Keyboard::isKeyPressed(sf::Keyboard::R);
}