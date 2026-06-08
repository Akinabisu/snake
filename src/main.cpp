#include "common.h"
#include "factory_helper.h"
#include "game_engine.h"
#include "graphics_check.h"

int main() {
    auto factory = FactoryHelper::createFactory();

    GameEngine engine;
    const int FIELD_SIZE = 20;
    const int FPS = 10;

    engine.run(*factory, FIELD_SIZE, FPS);

    return 0;
}