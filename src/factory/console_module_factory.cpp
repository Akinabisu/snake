#include "console_module_factory.h"

#include "console_direction_controller.h"
#include "console_flow_controller.h"
#include "console_renderer.h"

GameModules ConsoleModuleFactory::createModules(int field_size, int fps) {
    auto renderer = std::make_unique<ConsoleRenderer>(field_size, fps);
    auto flow = std::make_unique<ConsoleFlowController>();
    auto dir = std::make_unique<ConsoleDirectionController>(*flow);

    return {std::move(renderer), std::move(flow), std::move(dir)};
}