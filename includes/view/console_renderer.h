#pragma once
#include "renderer.h"

class ConsoleRenderer : public Renderer {
   public:
    ConsoleRenderer(int window_size = 20, int fps = 10);

    void renderField(const Field& field) override;
    void renderGameOver() override;
};