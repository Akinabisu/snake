#include "game_logic.h"

#include <ncurses.h>

#include <cstdlib>
#include <iostream>
#include <thread>

#include "console_direction_controller.h"
#include "direction_controller.h"
#include "field.h"
#include "food.h"
#include "snake.h"

const int FIELD_WIDTH = 20, FIELD_HEIGHT = 20;

void GameLogic::game() {
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);
    keypad(stdscr, TRUE);

    Field field = Field(FIELD_HEIGHT, FIELD_WIDTH);
    Snake snake = Snake(field);
    Food food;
    ConsoleDirectionController controller;
    food.placeFood(field);

    while (true) {
        if (snake.isDead()) {
            clear();
            mvprintw(10, 20, "Game Over :(");
            refresh();
            napms(2000);
            break;
        }

        controller.updateDirection();
        bool eat = food.coords() == snake.headCoords();

        snake.move(controller.currentDirection(), eat);

        if (eat) {
            food.placeFood(field);
        }
        field.addObject(snake.snakeCoords(), snake.length(), FieldObject::Snake);
        field.addObject(food.coords(), FieldObject::Food);

        clear();
        mvprintw(0, 0, "%s", field.toString().c_str());
        refresh();
        field.clear();

        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
};
