#pragma once
#include <SFML/Graphics.hpp>

#include "common.h"
#include "renderer.h"

class GuiRenderer : public Renderer {
   private:
    sf::RenderWindow _window;
    const int _SCALE = 40;

   public:
    GuiRenderer(int window_size = 20, int fps = 10);

    sf::RenderWindow& getWindow();

    void renderObject(int x, int y, sf::Color color);
    void renderObject(const Coords& coords, sf::Color color);
    void renderField(const Field& field) override;
    void renderGameOver() override;
};