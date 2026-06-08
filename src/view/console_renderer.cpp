#include "console_renderer.h"

#include <ncurses.h>

#include <chrono>
#include <thread>

#include "renderer.h"

ConsoleRenderer::ConsoleRenderer(int window_size, int fps) : Renderer(window_size, fps) {
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);
    keypad(stdscr, TRUE);
}

void ConsoleRenderer::renderField(const Field& field) {
    move(0, 0);
    mvprintw(0, 0, "%s", field.toString().c_str());
    refresh();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000 / _fps));
}

void ConsoleRenderer::renderGameOver() {
    erase();
    mvprintw(0, 0, "Game Over :(");
    refresh();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000 / _fps));
}
