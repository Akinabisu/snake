#pragma once

#include <memory>

#include "common.h"
#include "console_module_factory.h"
#include "gui_module_factory.h"

class FactoryHelper {
   public:
    static std::unique_ptr<GameModuleFactory> createFactory(GameMode mode) {
        if (mode == GameMode::Graphic) {
            return std::make_unique<GuiModuleFactory>();
        }
        return std::make_unique<ConsoleModuleFactory>();
    }
};