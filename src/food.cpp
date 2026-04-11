#include "food.h"
#include <cstdlib>
#include <ctime>

Coords Food::coords() const
{
	return _coords;
}

void Food::placeFood(const Field& f)
{
    srand(time(0));

    int x, y;

    x = rand() % f.height();
    y = rand() % f.width();

    _coords = { x, y };
}

bool Food::isFood(Coords c) const
{
	return c==_coords;
}
