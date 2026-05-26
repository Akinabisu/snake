#include "game_logic_graphic.h"

#include <SFML/Graphics.hpp>

#include "field.h"
#include "food.h"
#include "gui_direction_controller.h"
#include "gui_flow_controller.h"
#include "gui_renderer.h"
#include "snake.h"

const int FPS = 10;
const int FIELD_SIZE = 20;

void GameLogicGraphic::game() {
    Field field = Field(FIELD_SIZE, FIELD_SIZE);
    Snake snake = Snake(field);
    Food food;

    GuiRenderer renderer = GuiRenderer(FIELD_SIZE, FPS);
    GuiFlowController flow_controller(renderer.getWindow());
    GuiDirectionController direction_controller(flow_controller, renderer.getWindow());

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

            field.clear();
            field.addObject(food.coords(), FieldObject::Food);
            field.addObject(snake.snakeCoords(), snake.length(), FieldObject::Snake);

            renderer.renderField(field);
            field.clear();
        }
    }
}