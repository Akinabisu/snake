#pragma once
#include <SFML/Graphics.hpp>

#include "common.h"
#include "renderer.h"

class GuiRenderer : public Renderer {
   private:
    const int _SCALE = 40;
    sf::RenderWindow _window;

   public:
    GuiRenderer(int window_size, int fps);

    sf::RenderWindow& getWindow();

    void renderObject(int x, int y, sf::Color color);
    void renderObject(const Coords& coords, sf::Color color);
    void renderField(const Field& field) override;
    void renderGameOver() override;
};