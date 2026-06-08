#pragma once
#include <SFML/Graphics.hpp>

#include "common.h"
#include "direction_controller.h"
#include "gui_flow_controller.h"

class GuiDirectionController : public DirectionController {
   private:
    const GuiFlowController& _flow_controller;
    const sf::RenderWindow& _window;

   public:
    GuiDirectionController(const GuiFlowController& fc, const sf::RenderWindow& w);

    void updateDirection() override;
};