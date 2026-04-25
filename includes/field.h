#pragma once
#include <iostream>
#include <string>

#include "common.h"

class Field {
   private:
    int _height = 0;
    int _width = 0;
    char** _field;

   public:
    Field(int h, int w);
    ~Field();

    int height() const;
    int width() const;

    void addObject(Coords coords, char character_to_represent_object);
    void addObject(const Coords* coords, int size, char character_to_represent_object);
    void clear();

    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& output, const Field& f);
};