#include "gui_module_factory.h"

#include "gui_direction_controller.h"
#include "gui_flow_controller.h"
#include "gui_renderer.h"

GameModules GuiModuleFactory::createModules(int field_size, int fps) {
    {
        auto renderer = std::make_unique<GuiRenderer>(field_size, fps);
        auto flow = std::make_unique<GuiFlowController>(renderer->getWindow());
        auto dir = std::make_unique<GuiDirectionController>(*flow, renderer->getWindow());

        return {std::move(renderer), std::move(flow), std::move(dir)};
    }
}