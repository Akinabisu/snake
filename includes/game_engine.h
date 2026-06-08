#pragma once
#include "game_module_factory.h"

class GameEngine {
   public:
    static void run(GameModuleFactory& factory, int field_size = 20, int fps = 10);
};