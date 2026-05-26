#pragma once
#include "common.h"
#include "field.h"

class Food {
   private:
    Coords _coords = {0, 0};

   public:
    Coords coords() const;
    void placeFood(const Field& f);
    bool isFood(Coords coords) const;
};