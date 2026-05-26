#pragma once
#include <SFML/Graphics.hpp>

#include "game_flow_controller.h"

class GuiFlowController : public GameFlowController {
   private:
    sf::RenderWindow& _window;
    sf::Keyboard::Key _last_key_pressed = sf::Keyboard::Unknown;

   public:
    GuiFlowController(sf::RenderWindow& window);
    sf::Keyboard::Key getLastKeyPressed() const;

    void updateEvents() override;
    void exit() override;
};