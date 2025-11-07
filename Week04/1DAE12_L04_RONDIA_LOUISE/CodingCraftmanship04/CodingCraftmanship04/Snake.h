#include "pch.h"
#include <utils.h>
#include "Coord2i.h"

class Snake {
public:
	std::vector<Coord2i>	pos;
	Coord2i					dir;
	Color4f					color;
	size_t					length;
	bool					isDead;

	Snake( const Coord2i & start );
	void	Move();
	void	AddTail();
	void	CheckDeath();


};
