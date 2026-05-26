#pragma once

#include <memory>

#include "direction_controller.h"
#include "game_flow_controller.h"
#include "renderer.h"

struct GameModules {
    std::unique_ptr<Renderer> renderer;
    std::unique_ptr<GameFlowController> flow_controller;
    std::unique_ptr<DirectionController> direction_controller;
};

class GameModuleFactory {
   public:
    virtual GameModules createModules(int field_size, int fps) = 0;
    virtual ~GameModuleFactory() = default;
};