#include "snake.h"

#include <algorithm>

#include "common.h"
#include "food.h"

Snake::Snake(const Field& f) {
    _field = &f;
    Coords start_head_coords = {_field->height() / 2, _field->width() / 2};
    _snake_coords.push_back(start_head_coords);
};

int Snake::length() { return _snake_coords.size(); }

const Coords* Snake::snakeCoords() const { return _snake_coords.data(); }

Coords Snake::headCoords() const { return _snake_coords[0]; }

Coords Snake::tailCoords() const { return _snake_coords[_snake_coords.size() - 1]; }

bool Snake::isSnakePart(Coords c) const {
    auto it = std::find(_snake_coords.begin(), _snake_coords.end(), c);
    return it != _snake_coords.end();
}

void Snake::move(Direction d, bool eat) {
    Coords head_coords = headCoords();

    switch (d) {
        case Direction::Right:
            if (head_coords.x + 1 < _field->width())
                head_coords.x++;
            else
                head_coords.x = 0;
            break;
        case Direction::Down:
            if (head_coords.y + 1 < _field->height())
                head_coords.y++;
            else
                head_coords.y = 0;
            break;
        case Direction::Left:
            if (head_coords.x > 0)
                head_coords.x--;
            else
                head_coords.x = _field->width() - 1;
            break;
        case Direction::Up:
            if (head_coords.y > 0)
                head_coords.y--;
            else
                head_coords.y = _field->height() - 1;
            break;
    }

    _snake_coords.insert(_snake_coords.begin(), head_coords);

    if (!eat) {
        _snake_coords.pop_back();
    }
}

bool Snake::isHeadInBody() {
    return std::count(_snake_coords.begin(), _snake_coords.end(), headCoords()) >= 2;
}

bool Snake::isDead() { return isHeadInBody(); }