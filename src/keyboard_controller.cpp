#include "..\includes\keyboard_controller.h"
#include <conio.h>
#include <thread>
#include <chrono>

Direction KeyboardController::currentDirection() {
	return _current_direction;
};

void KeyboardController::keyListener() {
    while(true) {
        if (_kbhit()) {
            char key = _getch();
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
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
};