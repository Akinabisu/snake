#pragma once
#include <SFML/Graphics.hpp>

#include "common.h"
#include "renderer.h"

class GuiRenderer : public Renderer {
   private:
    sf::RenderWindow _window;
    static const int _SCALE = 40;

   public:
    GuiRenderer(int window_size = 20, int fps = 10);

    void renderField(const Field& field) override;
    void renderGameOver() override;

    sf::RenderWindow& getWindow();
    void RenderObject(const Coords& coords, sf::Color color);
    void RenderObject(int x, int y, sf::Color color);
};