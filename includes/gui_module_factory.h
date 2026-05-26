#pragma once

#include "game_module_factory.h"

class GuiModuleFactory : public GameModuleFactory {
   public:
    GameModules createModules(int field_size, int fps) override;
};