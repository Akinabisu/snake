#pragma once
#include <SFML/Graphics.hpp>

#include "game_flow_controller.h"

class GuiFlowController : public GameFlowController {
   private:
    sf::RenderWindow& _window;

   public:
    GuiFlowController(sf::RenderWindow& window) : _window(window) {};

    bool wantsToExit() override;

    bool wantsToRestart() override;
};