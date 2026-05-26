#include "field.h"

#include <unistd.h>

#include <iostream>

Field::Field(int h, int w) {
    _height = h;
    _width = w;
    _field = new FieldObject*[_height];

    for (int i = 0; i < _height; ++i) {
        _field[i] = new FieldObject[_width];
        for (int j = 0; j < _width; ++j) {
            _field[i][j] = FieldObject::Empty;
        }
    }
}

Field::~Field() {
    for (int i = 0; i < _height; ++i) {
        delete[] _field[i];
    }

    delete[] _field;
}

int Field::height() const { return _height; }

int Field::width() const { return _width; }

// maybe create isCellFree and change food checking

void Field::addObject(Coords c, FieldObject fo) { _field[c.y][c.x] = fo; }

void Field::addObject(const Coords* c, int s, FieldObject fo) {
    for (int i = 0; i < s; ++i) {
        _field[c[i].y][c[i].x] = fo;
    }
}

void Field::clear() {
    for (int i = 0; i < _height; ++i) {
        for (int j = 0; j < _width; ++j) {
            _field[i][j] = FieldObject::Empty;
        }
    }
}

std::string Field::toString() const {
    std::string result = "";

    result += ' ';

    for (int i = 0; i < _width; ++i) {
        result += '_';
    }
    result += '\n';

    for (int i = 0; i < _height; ++i) {
        result += '|';

        for (int j = 0; j < _width; ++j) {
            switch (_field[i][j]) {
                case FieldObject::Snake:
                    result += 'X';
                    break;
                case FieldObject::Food:
                    result += '0';
                    break;
                case FieldObject::Empty:
                    result += ' ';
                    break;
                default:
                    result += ' ';
                    break;
            }
        }

        result += "|\n";
    }

    result += ' ';
    for (int i = 0; i < _width; ++i) {
        result += '_';
    }
    result += '\n';

    return result;
}

const FieldObject* Field::operator[](int row) const { return _field[row]; }

std::ostream& operator<<(std::ostream& output, const Field& f) {
    output << f.toString();

    return output;
}