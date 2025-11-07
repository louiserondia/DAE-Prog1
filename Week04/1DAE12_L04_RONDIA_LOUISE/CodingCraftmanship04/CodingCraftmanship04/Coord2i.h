#pragma once

struct Coord2i {
	int	x;
	int	y;

	Coord2i();
	explicit Coord2i(int x, int y);

	Coord2i operator-(const Coord2i& rhv);
	Coord2i operator+(const Coord2i& rhv);
	Coord2i operator*(const int& rhv);
	Coord2i operator*(const Coord2i& rhv);
	bool	operator==(const Coord2i& rhv) const;
	bool	operator!=(const Coord2i& rhv);

	bool	IsOut() const;
};

Coord2i	Out();

