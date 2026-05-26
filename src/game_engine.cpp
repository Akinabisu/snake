#include "game_engine.h"

#include "field.h"
#include "food.h"
#include "game_module_factory.h"
#include "snake.h"

const int FPS = 10;
const int FIELD_SIZE = 20;

void GameEngine::run(GameModuleFactory& factory, int field_size, int fps) {
    Field field = Field(FIELD_SIZE, FIELD_SIZE);
    Snake snake = Snake(field);
    Food food;

    GameModules modules = factory.createModules(field_size, fps);

    Renderer& renderer = *modules.renderer;
    GameFlowController& flow_controller = *modules.flow_controller;
    DirectionController& direction_controller = *modules.direction_controller;

    food.placeFood(field);
    bool isGameOver = false;

    while (true) {
        flow_controller.updateEvents();

        if (flow_controller.wantsToExit()) {
            flow_controller.exit();
            break;
        };

        if (flow_controller.wantsToRestart()) {
            snake = Snake(field);
            food.placeFood(field);
            direction_controller.SetDirection(Direction::Right);
            isGameOver = false;
        }

        if (snake.isDead()) {
            isGameOver = true;
        }

        if (isGameOver) {
            renderer.renderGameOver();
        } else {
            direction_controller.updateDirection();

            bool eat = food.coords() == snake.headCoords();

            snake.move(direction_controller.currentDirection(), eat);

            if (eat) {
                food.placeFood(field);
            }

            field.addObject(snake.snakeCoords(), snake.length(), FieldObject::Snake);
            field.addObject(food.coords(), FieldObject::Food);

            renderer.renderField(field);

            field.clear();
        }
    }
};
