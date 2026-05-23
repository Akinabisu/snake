cmake_minimum_required(VERSION 3.10.0)
project(snake VERSION 0.1.0 LANGUAGES C CXX)

find_package(Curses REQUIRED)
find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)

add_executable(snake
    includes/common.h
    includes/field.h
    includes/snake.h
    includes/food.h
    includes/direction_controller.h
    includes/console_direction_controller.h
    includes/gui_direction_controller.h
    includes/game_flow_controller.h
    includes/console_flow_controller.h
    includes/gui_flow_controller.h
    includes/game_logic.h
    includes/game_logic_graphic.h


    src/field.cpp 
    src/snake.cpp
    src/food.cpp
    src/direction_controller.cpp
    src/console_direction_controller.cpp
    src/gui_direction_controller.cpp
    src/console_flow_controller.cpp
    src/gui_flow_controller.cpp
    src/game_logic.cpp
    src/game_logic_graphic.cpp
    
    src/main.cpp 
)

target_link_libraries(snake PRIVATE ${CURSES_LIBRARIES})
target_link_libraries(snake PRIVATE sfml-graphics sfml-window sfml-system)
target_include_directories(
    snake
    PUBLIC
    includes
)