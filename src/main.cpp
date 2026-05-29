#include "common.h"
#include "factory_helper.h"
#include "game_engine.h"

int main() {
    GameMode mode = GameMode::Console;
    auto factory = FactoryHelper::createFactory(mode);

    GameEngine engine;
    const int FIELD_SIZE = 20;
    const int FPS = 10;

    engine.run(*factory, FIELD_SIZE, FPS);

    return 0;
}