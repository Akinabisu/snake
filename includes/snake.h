#pragma once

#include "common.h"
#include "field.h"
#include <vector>

class Snake
{
private:
    const Field* _field;
    std::vector<Coords> _snake_coords;

public:
    Snake(const Field& f);
    int length();
    const Coords* snakeCoords() const;
    Coords headCoords() const;
    Coords tailCoords() const;

    bool isSnakePart(Coords c) const;
    void move(Direction d, bool eat = false);
};