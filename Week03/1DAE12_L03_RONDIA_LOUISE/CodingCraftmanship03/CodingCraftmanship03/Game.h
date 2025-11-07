#pragma once
#include <utils.h>
#include "Coord2i.h"
using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "Coding Craftmanship 3 - Snake - Rondia, Louise - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 720 };
float g_WindowHeight{ 720 };
#pragma endregion gameInformation

#pragma region ownDeclarations
// Declare your own global variables here

struct Dirs {
	const Coord2i	left{ -1, 0 };
	const Coord2i	up{ 0, -1 };
	const Coord2i	right{ 1, 0 };
	const Coord2i	down{ 0, 1 };
};

class Snake {
public:
	std::vector<Coord2i> pos;
	Coord2i dir;
	Color4f color;
	size_t	length;
	bool	isDead;

	Snake();
	void	Move();
	void	AddTail();
	void	CheckDeath();
};

struct Fruit
{
	Coord2i	notEaten{};
	Coord2i	eaten{};
};

const Color4f	g_Grey(0.77f, 0.86f, 0.84f, 1.f);
const Color4f	g_Green(0.55f, 0.64f, 0.28f, 1.f);
const Color4f	g_Pink(0.86f, 0.63f, 0.7f, 1.f);
const Color4f	g_Orange(0.9f, 0.41f, 0.27f, 1.f);


const float		g_TileSizef{ 40.f };
const int		g_TileSizei{ 40 };
const int		g_GridWidth{ static_cast<int>(g_WindowWidth / g_TileSizef) };
const int		g_GridHeight{ static_cast<int>(g_WindowHeight / g_TileSizef) };
Coord2i			g_Start{};

float			g_PosTime{ 0.f };
float			g_FruitTime{ 0.f };
bool			g_WallsEnabled{ true };

const Dirs		g_Dirs;

Snake			g_Snake{};
Fruit			g_Fruit{};

bool			g_IsGameOver{};

// Declare your own functions here

bool	IsDirectionKey(SDL_Keycode key);
Coord2i RandomPos();
Coord2i RandomMidPos();

void	DrawSnake();
void	DrawTongue();
void	DrawFruit();
void	AddFruit();
void	EatFruit();
void	DeleteFruit();
void	DrawWalls();
void	EnableWalls();
void	DisableWalls();
void	GameOver();
void	DrawGameOver();


#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
