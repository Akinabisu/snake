#include "keyboard_controller.h"
#include <ncurses.h>
#include <thread>
#include <chrono>
#include <ctype.h>

Direction KeyboardController::currentDirection() {
	return _current_direction;
};

void KeyboardController::keyListener(){    
    while(true) {
            char key = tolower(getch());
            switch (key) {
                case 'd':
                    if (_current_direction != Direction::Left) {
                        _current_direction = Direction::Right;
                    }
                    break;
                case 's':
                    if (_current_direction != Direction::Up) {
                        _current_direction = Direction::Down;
                    }
                    break;
                case 'a':
                    if (_current_direction != Direction::Right) {
                        _current_direction = Direction::Left;
                    }
                    break;
                case 'w':
                    if (_current_direction != Direction::Down) {
                        _current_direction = Direction::Up;
                    }
                    break;
            }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
};