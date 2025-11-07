#include "Snake.h"
#include "Game.h"


Snake::Snake(const Coord2i& start) :
	pos{ 100, start },
	dir{ 1, 0 },
	color{ 0.5f, 0.9f, 0.5f, 1.f },
	length{ 4 },
	isDead{ false }
{
	for (size_t i = 1; i < length; i++) {
		pos[i] = pos[0] + (dir * -1 * i);
	}
}

void Snake::AddTail(  ) {
	pos[length] = g_Fruit.eaten;
	length++;
}

void Snake::Move() {
	for (size_t i = length - 1; i > 0; i--) {
		if (pos[i] != pos[i - 1])
			pos[i] = pos[i - 1];
	}
		if ( DeleteFruit(pos[length - 1]) )
		{
			AddTail();
		}
	}

	Coord2i newPos{ pos[0] + dir };
	newPos.x = (newPos.x + g_GridWidth) % g_GridWidth;
	newPos.y = (newPos.y + g_GridHeight) % g_GridHeight;
	pos[0] = newPos;
}

void	Snake::CheckDeath() {
	if (g_BoostOn)
		return;

	for (size_t i = 1; i < length; i++) {
		if (pos[i] == pos[0])
			isDead = true;
	}
	if (g_WallsEnabled) {
		if (pos[0].x % g_GridWidth == 0 || pos[0].x % g_GridWidth == g_GridWidth - 1)
			isDead = true;
		else if (pos[0].y % g_GridHeight == 0 || pos[0].y % g_GridHeight == g_GridHeight - 1)
			isDead = true;
	}
}
