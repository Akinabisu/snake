#pragma once
#include <SFML/Graphics.hpp>

#include "common.h"
#include "direction_controller.h"

class GuiDirectionController : public DirectionController {
   private:
    sf::RenderWindow& _window;

   public:
    GuiDirectionController(sf::RenderWindow& window) : _window(window) {};
    void updateDirection() override;
};