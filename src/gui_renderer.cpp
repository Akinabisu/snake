#include "gui_renderer.h"

#include <SFML/Graphics.hpp>

const int GAME_OVER_PATTERN[10][20] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
    {0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0},
    {0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0},
    {0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

GuiRenderer::GuiRenderer(int window_size, int fps)
    : Renderer(window_size, fps),
      _window(sf::VideoMode(window_size * _SCALE, window_size * _SCALE), "Snake") {
    _window.setFramerateLimit(fps);
}

void GuiRenderer::RenderObject(int x, int y, sf::Color color) {
    sf::RectangleShape shape(sf::Vector2f(_SCALE - 2, _SCALE - 2));
    shape.setPosition(x * _SCALE, y * _SCALE);
    shape.setFillColor(color);

    _window.draw(shape);
}

void GuiRenderer::RenderObject(const Coords& coords, sf::Color color) {
    RenderObject(coords.x, coords.y, color);
}

void GuiRenderer::renderField(const Field& field) {
    _window.clear();

    for (int i = 0; i < field.height(); ++i) {
        for (int j = 0; j < field.width(); ++j) {
            Coords coords{j, i};
            FieldObject object_type = field[i][j];

            if (object_type == FieldObject::Snake) {
                RenderObject(coords, sf::Color::Blue);
            }
            if (object_type == FieldObject::Food) {
                RenderObject(coords, sf::Color::Green);
            }
        }
    }

    _window.display();
}

void GuiRenderer::renderGameOver() {
    _window.clear();

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (GAME_OVER_PATTERN[i][j] == 1) {
                RenderObject(j, i, sf::Color::Red);
            }
        }
    }

    _window.display();
}

sf::RenderWindow& GuiRenderer::getWindow() { return _window; }
