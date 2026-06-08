#pragma once

struct Coords {
    int x = 0;
    int y = 0;

    friend bool operator==(const Coords& c1, const Coords& c2) {
        return c1.x == c2.x && c1.y == c2.y;
    }
};

enum class Direction {
    Right,
    Down,
    Left,
    Up,
};

enum class FieldObject {
    Snake,
    Food,
    Empty,
};
