#include "pch.h"
#include "Coord2i.h"


Coord2i::Coord2i()
	:Coord2i{ 0, 0 }
{
}

Coord2i::Coord2i(int x, int y)
	:x{ x }, y{ y }
{
}

Coord2i Coord2i::operator-(const Coord2i& rhv)
{
	return Coord2i(x - rhv.x, y - rhv.y);
}

Coord2i Coord2i::operator+(const Coord2i& rhv)
{
	return Coord2i(x + rhv.x, y + rhv.y);
}

Coord2i Coord2i::operator*(const int& rhv)
{
	return Coord2i(x * rhv, y * rhv);
}

Coord2i Coord2i::operator*(const Coord2i& rhv)
{
	return Coord2i(x * rhv.x, y * rhv.y);
}

bool Coord2i::operator==(const Coord2i& rhv)
{
	return (x == rhv.x && y == rhv.y);
}

bool Coord2i::operator!=(const Coord2i& rhv)
{
	return (x != rhv.x || y != rhv.y);
}

bool	Coord2i::IsOut() const {
	return x == -1 || y == -1;
}

Coord2i	Out() {
	return Coord2i{ -1, -1 };
}
