cmake_minimum_required(VERSION 3.10.0)
project(snake VERSION 0.1.0 LANGUAGES C CXX)

add_executable(snake
    includes/field.h
    includes/snake.h
    includes/food.h
    includes/keyboard_controller.h
    includes/game_logic.h

    src/field.cpp 
    src/snake.cpp
    src/food.cpp
    src/keyboard_controller.cpp
    src/game_logic.cpp
    
    src/main.cpp 
)

include(CTest)
enable_testing()

