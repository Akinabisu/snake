#pragma once
#include <iostream>
#include <string>

#include "common.h"

class Field {
   private:
    int _height = 0;
    int _width = 0;
    FieldObject** _field;

   public:
    Field(int h, int w);
    ~Field();

    int height() const;
    int width() const;

    void addObject(Coords coords, FieldObject object_type);
    void addObject(const Coords* coords, int size, FieldObject object_type);
    void clear();

    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& output, const Field& f);
    const FieldObject* operator[](int row) const;
};