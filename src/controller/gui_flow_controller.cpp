#include "gui_flow_controller.h"

GuiFlowController::GuiFlowController(sf::RenderWindow& w) : _window(w) {};

sf::Keyboard::Key GuiFlowController::getLastKeyPressed() const { return _last_key_pressed; };

void GuiFlowController::updateEvents() {
    _wants_to_restart = false;

    sf::Event event;

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _wants_to_exit = true;
        }

        if (event.type == sf::Event::KeyPressed) {
            _last_key_pressed = sf::Keyboard::Unknown;

            if (event.key.code == sf::Keyboard::E) {
                _wants_to_exit = true;
            }
            if (event.key.code == sf::Keyboard::R) {
                _wants_to_restart = true;
            }

            sf::Keyboard::Key k = event.key.code;
            if (k == sf::Keyboard::W || k == sf::Keyboard::A || k == sf::Keyboard::S ||
                k == sf::Keyboard::D || k == sf::Keyboard::Up || k == sf::Keyboard::Down ||
                k == sf::Keyboard::Left || k == sf::Keyboard::Right) {
                _last_key_pressed = k;
            }
        }
    }
}

void GuiFlowController::exit() { _window.close(); }