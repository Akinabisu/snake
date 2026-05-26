#include "console_module_factory.h"
#include "game_engine.h"
#include "gui_module_factory.h"

enum class GameMode { Graphic, Console };

int main() {
    GameMode mode = GameMode::Console;

    GameEngine engine;
    const int FIELD_SIZE = 20;
    const int FPS = 10;

    if (mode == GameMode::Graphic) {
        GuiModuleFactory gui_factory;
        engine.run(gui_factory, FIELD_SIZE, FPS);
    } else if (mode == GameMode::Console) {
        ConsoleModuleFactory console_factory;
        engine.run(console_factory, FIELD_SIZE, FPS);
    }

    return 0;
}