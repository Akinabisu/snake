#include "game_logic.h"
#include "field.h"
#include "snake.h"
#include "keyboard_controller.h"
#include "food.h"
#include <thread>
#include <iostream>
#include <cstdlib>
#include <ncurses.h>

void GameLogic::game() {
	
	int h, w;
	std::cout << "Enter field height and width: ";
	std::cin >> h >> w;
	
	initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);

	Field field = Field(h, w);
	Snake snake = Snake(field);
	Food food;
	KeyboardController keyboard_controller;
	food.placeFood(field);

	std::thread listener([&keyboard_controller]() {
		keyboard_controller.keyListener(); });

	//TODO add exit condition
	while (true) {

		bool eat = food.coords()==snake.headCoords();

		try
		{
			snake.move(keyboard_controller.currentDirection(), eat);
			if (eat){
				food.placeFood(field);
			}
		}
		catch(const char* msg)
		{
			system("clear");
			std::cout << msg << '\n';
			break;
		}
		

		field.addObject(food.coords(), '0');
		field.addObject(snake.snakeCoords(), snake.length(), 'x');

		//TODO fix flickering
		clear();
		mvprintw(0, 0, "%s", field.toString().c_str());
		refresh();
		field.clear();

		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		system("clear");
	}

	if (listener.joinable())
		listener.join();
};
