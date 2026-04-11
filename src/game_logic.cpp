#include "game_logic.h"
#include "field.h"
#include "snake.h"
#include "keyboard_controller.h"
#include "food.h"
#include <thread>
#include <iostream>
#include <cstdlib>

void GameLogic::game() {
	int h, w;
	std::cout << "Enter field height and width: ";
	std::cin >> h >> w;

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
			system("cls");
			std::cout << msg << '\n';
			break;
		}
		

		field.addObject(food.coords(), '0');
		field.addObject(snake.snakeCoords(), snake.length(), 'x');

		//TODO fix flickering
		std::cout << field;
		field.clear();

		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		system("cls");
	}

	if (listener.joinable())
		listener.join();
};
