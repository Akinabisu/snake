#pragma once

#include <memory>

#include "game_module_factory.h"

class FactoryHelper {
   public:
    static std::unique_ptr<GameModuleFactory> createFactory();
};