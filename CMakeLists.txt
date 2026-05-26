cmake_minimum_required(VERSION 3.10.0)
project(snake VERSION 0.1.0 LANGUAGES C CXX)

find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)
find_package(Curses REQUIRED COMPONENTS ncurses)

add_executable(snake
    includes/model/common.h
    includes/model/field.h
    includes/model/snake.h
    includes/model/food.h

    includes/controller/direction_controller.h
    includes/controller/console_direction_controller.h
    includes/controller/gui_direction_controller.h
    includes/controller/game_flow_controller.h
    includes/controller/console_flow_controller.h
    includes/controller/gui_flow_controller.h

    includes/view/renderer.h
    includes/view/console_renderer.h
    includes/view/gui_renderer.h

    includes/factory/game_module_factory.h
    includes/factory/console_module_factory.h
    includes/factory/gui_module_factory.h

    includes/game_engine.h
    

    src/model/field.cpp 
    src/model/snake.cpp
    src/model/food.cpp

    src/controller/direction_controller.cpp
    src/controller/console_direction_controller.cpp
    src/controller/gui_direction_controller.cpp

    src/controller/game_flow_controller.cpp
    src/controller/console_flow_controller.cpp
    src/controller/gui_flow_controller.cpp

    src/view/console_renderer.cpp
    src/view/gui_renderer.cpp

    src/factory/console_module_factory.cpp
    src/factory/gui_module_factory.cpp

    src/game_engine.cpp
    
    src/main.cpp 
)
    
target_include_directories(
    snake
    PUBLIC
    includes
    
)

target_link_libraries(snake PRIVATE 
    sfml-graphics 
    sfml-window 
    sfml-system 
    ncurses
)