#pragma once
#include <SFML/Graphics.hpp>

#include "common.h"
#include "direction_controller.h"
#include "gui_flow_controller.h"

class GuiDirectionController : public DirectionController {
   private:
    GuiFlowController _flow_controller;
    sf::RenderWindow& _window;

   public:
    GuiDirectionController(GuiFlowController& flow_controller, sf::RenderWindow& window);
    void updateDirection() override;
};