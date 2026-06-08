#include "factory_helper.h"

#include "console_module_factory.h"
#include "graphics_check.h"
#include "gui_module_factory.h"

std::unique_ptr<GameModuleFactory> FactoryHelper::createFactory() {
    if (GraphicsCheck::hasGraphics()) {
        return std::make_unique<GuiModuleFactory>();
    } else {
        return std::make_unique<ConsoleModuleFactory>();
    }
}