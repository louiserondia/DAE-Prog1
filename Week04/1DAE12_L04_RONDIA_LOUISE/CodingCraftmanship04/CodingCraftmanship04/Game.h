#pragma once
#include <utils.h>
#include "Coord2i.h"
#include <iostream>
#include <random>
#include <cmath>
#include "Snake.h"

using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "Coding Craftmanship 4 - Space Snake - Rondia, Louise - 1DAE12" };

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
struct Fruit
{
	Coord2i	notEaten{};
	Coord2i	eaten{};
};

const Color4f	g_Grey(0.77f, 0.86f, 0.84f, 1.f);
const Color4f	g_Green(0.55f, 0.64f, 0.28f, 1.f);
const Color4f	g_Pink(0.86f, 0.63f, 0.7f, 1.f);
const Color4f	g_Orange(0.9f, 0.41f, 0.27f, 1.f);

const Color4f	g_MidnightBlue{ 0.11f, 0.086f, 0.471f, 1.f };
const Color4f	g_SlateBlue{ 0.522f, 0.463f, 1.f, 1.f };
const Color4f	g_SlateBlueTrans{ 0.522f, 0.463f, 1.f, 0.5f };
const Color4f	g_MayaBlue{ 0.482f, 0.788f, 1.f, 1.f };
const Color4f	g_Mint{ 0.639f, 1.f, 0.839f, 1.f };

const float		g_TileSizef{ 40.f };
const int		g_TileSizei{ 40 };
const int		g_GridWidth{ static_cast<int>(g_WindowWidth / g_TileSizef) };
const int		g_GridHeight{ static_cast<int>(g_WindowHeight / g_TileSizef) };
const Dirs		g_Dirs;
Coord2i			g_Start{};
int				g_Score{};
float			g_Time{ 0.f };
float			g_PosTime{ 0.f };

Snake			g_Snake{};
Fruit			g_Fruit{};
int				g_StarIndex{};

Rectf			g_GalaxyStars[500];

bool			g_WallsEnabled{ true };

bool			g_IsGameOver{};
Texture			g_DeathTexture{};
Texture			g_StarTexture[4];

bool			g_BoostVisible{};
bool			g_BoostOn{};
float			g_BoostCooldown{};
float			g_BoostEffectTime{};
Coord2i			g_Boost{};

// Declare your own functions here

//	Utils
bool	IsDirectionKey(SDL_Keycode key);
Coord2i RandomPosInGrid();
Coord2i RandomMidPos();
Point2f	RandomPoint2f();

//	Start
void	StartMessage();
void	LoadTextures();

//	Snake
void	DrawSnake();
void	UpdateSnake(float elapsedSec);
void	DrawTongue();

//	Fruit
void	DrawFruit();
void	AddFruit();
void	EatFruit();
bool	DeleteFruit(const Coord2i& position);

//	Boost
void	DrawBoost();
void	AddBoost();
void	RemoveBoost();
void	ActivateBoost();
void	DeactivateBoost();

//	Galaxy
void	InitGalaxy();
void	DrawGalaxy();
void	UpdateGalaxy(float elapsedSec);

//	Walls
void	DrawWalls();
void	EnableWalls();
void	DisableWalls();

//	Game Over
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
