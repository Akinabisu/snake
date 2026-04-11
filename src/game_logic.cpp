#include "..\includes\game_logic.h"
#include "..\includes\field.h"
#include "..\includes\snake.h"
#include "..\includes\keyboard_controller.h"
#include "..\includes\food.h"
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
		snake.move(keyboard_controller.currentDirection());

		field.addObject(snake.snakeCoords(), snake.length(), 'x');

		//field.addObject(food.coords(), 1, '0');

		//TODO fix flickering
		std::cout << field;
		field.clear();

		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		system("cls");
	}

	if (listener.joinable())
		listener.join();
};
