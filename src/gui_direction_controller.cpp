#include "gui_direction_controller.h"

void GuiDirectionController::updateDirection() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (_current_direction != Direction::Down) {
            _current_direction = Direction::Up;
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
               sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if (_current_direction != Direction::Up) {
            _current_direction = Direction::Down;
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
               sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if (_current_direction != Direction::Right) {
            _current_direction = Direction::Left;
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
               sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (_current_direction != Direction::Left) {
            _current_direction = Direction::Right;
        }
    }
};
