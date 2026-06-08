#pragma once
#include "field.h"

class Renderer {
   protected:
    int _window_size;
    int _fps;

   public:
    Renderer(int window_size, int fps);
    virtual ~Renderer() = default;

    virtual void renderField(const Field& field) = 0;
    virtual void renderGameOver() = 0;
};