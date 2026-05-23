#include "gui_direction_controller.h"

void GuiDirectionController::updateDirection() {
    if (!_window.hasFocus()) {
        return;
    }

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
         sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) &&
        _current_direction != Direction::Left) {
        _current_direction = Direction::Right;
        return;
    }

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
         sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) &&
        _current_direction != Direction::Up) {
        _current_direction = Direction::Down;
        return;
    }

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
         sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) &&
        _current_direction != Direction::Right) {
        _current_direction = Direction::Left;
        return;
    }

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
         sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) &&
        _current_direction != Direction::Down) {
        _current_direction = Direction::Up;
        return;
    }
}