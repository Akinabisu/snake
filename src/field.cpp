#include "field.h"
#include <iostream>

Field::Field(int h, int w)
{
	_height = h;
	_width = w;
	_field = new char* [_height];

	for (int i = 0; i < _height; ++i)
	{
		_field[i] = new char[_width];
		for (int j = 0; j <_width; ++j) {
			_field[i][j] = ' ';
		}
	}
}

Field::~Field() {
	for (int i = 0; i < _height; ++i) {
		delete _field[i];
	}

	delete _field;
}

int Field::height() const
{
	return _height;
}

int Field::width() const
{
	return _height;
}

//maybe create isCellFree and change food checking

void Field::addObject(Coords c, char ch)
{
	_field[c.y][c.x] = ch;
}

void Field::addObject(const Coords* c, int s, char ch)
{
	for (int i = 0; i < s; ++i) {
		_field[c[i].y][c[i].x] = ch;
	}
}

void Field::clear()
{
	for (int i = 0; i < _height; ++i)
	{
		for (int j = 0; j < _width; ++j) {
			_field[i][j] = ' ';
		}
	}
}

// width/height through getter?
// TODO square field cells
std::ostream& operator<<(std::ostream& output, const Field& f)
{
	output << ' ';
	for (int i = 0; i < f._width; ++i) {
		output << '_';
	}
	output << '\n';

	for (int i = 0; i < f._height; ++i) { 
		output << '|';

		for (int j = 0; j < f._width; ++j) {
			output << f._field[i][j];
		}

		output << "|\n";
	}

	output << ' ';
	for (int i = 0; i < f._width; ++i) {
		output << '_';
	}
	output << '\n';

	return output;
}

std::string Field::toString(){
	std::string result="";
	result+=' ';

	for (int i = 0; i < _width; ++i) {
		result += '_';
	}
	result+='\n';

	for (int i = 0; i < _height; ++i) { 
		result+= '|';

		for (int j = 0; j < _width; ++j) {
			result+=_field[i][j];
		}

		result+= "|\n";
	}

	result+= ' ';
	for (int i = 0; i < _width; ++i) {
		result+= '_';
	}
	result+= '\n';

	return result;
}