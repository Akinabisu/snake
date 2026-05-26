#include "gui_direction_controller.h"

GuiDirectionController::GuiDirectionController(GuiFlowController& flow_controller,
                                               sf::RenderWindow& window)
    : _flow_controller(flow_controller), _window(window){};

void GuiDirectionController::updateDirection() {
    sf::Keyboard::Key key = _flow_controller.getLastKeyPressed();

    if (key == sf::Keyboard::Unknown) return;

    switch (key) {
        case sf::Keyboard::D:
        case sf::Keyboard::Right:
            if (_current_direction != Direction::Left) _current_direction = Direction::Right;
            break;
        case sf::Keyboard::S:
        case sf::Keyboard::Down:
            if (_current_direction != Direction::Up) _current_direction = Direction::Down;
            break;
        case sf::Keyboard::A:
        case sf::Keyboard::Left:
            if (_current_direction != Direction::Right) _current_direction = Direction::Left;
            break;
        case sf::Keyboard::W:
        case sf::Keyboard::Up:
            if (_current_direction != Direction::Down) _current_direction = Direction::Up;
            break;
        default:
            break;
    }
}