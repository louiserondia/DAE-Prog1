#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											


//		             ____
//		            / . .\
//		            \  ---<
//		             \  /
//		   __________/ /
//  	-_/___________/
// 
//		----------------
//	Press W to enable or disable walls
//	If you die, press any non directional key to restart
//		----------------

void Start()
{
	g_Start = RandomMidPos();
	g_Snake = Snake();
	g_Fruit.notEaten = Out();
	g_Fruit.eaten = Out();
	g_IsGameOver = false;
}

void Draw()
{
	ClearBackground(g_Grey.r, g_Grey.g, g_Grey.b); // Greenish grey 

	if (g_WallsEnabled)
		DrawWalls();

	DrawFruit();
	DrawSnake();

	if (g_IsGameOver)
		DrawGameOver();
}

void Update(float elapsedSec)
{
	if (!g_IsGameOver && g_PosTime > 0.1f) {
		g_Snake.Move();
		g_PosTime = 0.f;
	}

	if (g_Fruit.notEaten.IsOut() && floor(g_FruitTime) > 1.f)
		AddFruit();

	if (!g_Fruit.notEaten.IsOut() && g_Snake.pos[0] == g_Fruit.notEaten)
		EatFruit();

	if (g_Snake.isDead)
		GameOver();

	g_Snake.CheckDeath();

	g_PosTime += elapsedSec;
	g_FruitTime += elapsedSec;
}

void End()
{
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{
}

bool	IsDirectionKey(SDL_Keycode key) {
	return key == SDLK_LEFT || key == SDLK_RIGHT || key == SDLK_UP || key == SDLK_DOWN;
}

void OnKeyUpEvent(SDL_Keycode key)
{
	// Restart game by pressing any non-directional key
	if (g_IsGameOver && !IsDirectionKey(key)) {
		Start();
	}

	if (key == SDLK_LEFT && g_Snake.dir != g_Dirs.right)
		g_Snake.dir = g_Dirs.left;
	else if (key == SDLK_UP && g_Snake.dir != g_Dirs.down)
		g_Snake.dir = g_Dirs.up;
	else if (key == SDLK_RIGHT && g_Snake.dir != g_Dirs.left)
		g_Snake.dir = g_Dirs.right;
	else if (key == SDLK_DOWN && g_Snake.dir != g_Dirs.up)
		g_Snake.dir = g_Dirs.down;

	if (key == SDLK_w && !g_WallsEnabled)
		EnableWalls();
	else if (key == SDLK_w && g_WallsEnabled)
		DisableWalls();
	g_PosTime = 0.11f;
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
}
#pragma endregion inputHandling

#pragma region ownDefinitions

Coord2i RandomPos() {
	return Coord2i{
		rand() % (g_GridWidth - 2) + 1,
		rand() % (g_GridHeight - 2) + 1
	};
}

Coord2i RandomMidPos() {
	return Coord2i{
		rand() % (g_GridWidth - 10) + 5,
		rand() % (g_GridHeight - 10) + 5
	};
}

Snake::Snake() :
	pos{ 100, g_Start },
	dir{ 1, 0 },
	color{ 0.5f, 0.9f, 0.5f, 1.f },
	length{ 4 },
	isDead{ false }
{
	for (size_t i = 1; i < length; i++) {
		pos[i] = pos[0] + (dir * -1 * i);
	}
}

void Snake::AddTail() {
	pos[length] = g_Fruit.eaten;
	length++;
}

void Snake::Move() {
	for (size_t i = length - 1; i > 0; i--) {
		if (pos[i] != pos[i - 1])
			pos[i] = pos[i - 1];
	}

	if (!g_Fruit.eaten.IsOut() && pos[length - 1] == g_Fruit.eaten) {
		AddTail();
		DeleteFruit();
	}

	Coord2i newPos{ pos[0] + dir };
	newPos.x = (newPos.x + g_GridWidth) % g_GridWidth;
	newPos.y = (newPos.y + g_GridHeight) % g_GridHeight;
	pos[0] = newPos;
}

void	Snake::CheckDeath() {
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

void DrawSnake() {

	float offset{ };

	for (size_t i = 0; i < g_Snake.length; i++) {
		offset = 0.f;
		if (!g_Fruit.eaten.IsOut() && g_Snake.pos[i] == g_Fruit.eaten) {
			offset = 5.f;
		}

		SetColor(g_Green);
		FillRect(
			g_Snake.pos[i].x * g_TileSizef - offset,
			g_Snake.pos[i].y * g_TileSizef - offset,
			g_TileSizef + 2 * offset,
			g_TileSizef + 2 * offset
		);

		SetColor(0.796f, 0.941f, 0.8f);
		DrawRect(
			g_Snake.pos[i].x * g_TileSizef - offset,
			g_Snake.pos[i].y * g_TileSizef - offset,
			g_TileSizef + 2 * offset,
			g_TileSizef + 2 * offset,
			2.f
		);

	}

	SetColor(g_Grey);
	FillEllipse(g_Snake.pos[0].x * g_TileSizef + g_TileSizef / 2, g_Snake.pos[0].y * g_TileSizef + g_TileSizef / 2, 5.f, 5.f);
	DrawTongue();
}

void DrawTongue() {
	Point2f c1{}, c2{};

	c1.x = g_Snake.pos[0].x + .5f + (g_Snake.dir.x == 0 ? 0.0f : g_Snake.dir.x * 0.5f);
	c2.x = g_Snake.pos[0].x + 0.5f + (g_Snake.dir.x == 0 ? 0.0f : g_Snake.dir.x * 1.0f);
	c1.y = g_Snake.pos[0].y + 0.5f + (g_Snake.dir.y == 0 ? 0.0f : g_Snake.dir.y * 0.5f);
	c2.y = g_Snake.pos[0].y + 0.5f + (g_Snake.dir.y == 0 ? 0.0f : g_Snake.dir.y * 1.0f);

	c1.x *= g_TileSizef;
	c1.y *= g_TileSizef;
	c2.x *= g_TileSizef;
	c2.y *= g_TileSizef;

	SetColor(g_Orange);
	DrawLine(c1, c2, 5.f);
}

void DrawFruit() {
	SetColor(g_Orange);

	if (!g_Fruit.notEaten.IsOut())
		FillRect(g_Fruit.notEaten.x * g_TileSizef, g_Fruit.notEaten.y * g_TileSizef, g_TileSizef, g_TileSizef);
	if (!g_Fruit.notEaten.IsOut())
		FillRect(g_Fruit.eaten.x * g_TileSizef, g_Fruit.eaten.y * g_TileSizef, g_TileSizef, g_TileSizef);
}

void	AddFruit() {
	g_Fruit.notEaten = RandomPos();
}

void	EatFruit() {
	g_Fruit.eaten = g_Fruit.notEaten;
	g_Fruit.notEaten = Out();
}

void	DeleteFruit() {
	g_Fruit.eaten = Out();
}

void	DrawWalls() {
	for (int i = 0; i < g_GridWidth; i++) {
		SetColor(g_Pink);
		FillRect(i * g_TileSizef, 0, g_TileSizef, g_TileSizef);
		FillRect(i * g_TileSizef, g_WindowHeight - g_TileSizef, g_TileSizef, g_TileSizef);

		SetColor(0.941f, 0.796f, 0.925f);
		DrawRect(i * g_TileSizef, 0, g_TileSizef, g_TileSizef, 2.f);
		DrawRect(i * g_TileSizef, g_WindowHeight - g_TileSizef, g_TileSizef, g_TileSizef, 2.f);
	}
	for (int i = 0; i < g_GridHeight; i++) {
		SetColor(g_Pink);
		FillRect(0, i * g_TileSizef, g_TileSizef, g_TileSizef);
		FillRect(g_WindowWidth - g_TileSizef, i * g_TileSizef, g_TileSizef, g_TileSizef);

		SetColor(0.941f, 0.796f, 0.925f);
		DrawRect(0, i * g_TileSizef, g_TileSizef, g_TileSizef, 2.f);
		DrawRect(g_WindowWidth - g_TileSizef, i * g_TileSizef, g_TileSizef, g_TileSizef, 2.f);
	}
}


void	EnableWalls() {
	g_WallsEnabled = true;
}

void	DisableWalls() {
	g_WallsEnabled = false;
}

void GameOver() {
	g_IsGameOver = true;
}

void	DrawGameOver() {
	SetColor(.8f, .8f, .8f, 0.65f);
	FillRect(0.f, 0.f, g_WindowWidth, g_WindowHeight);

	SetColor(g_Pink);
	FillEllipse(g_WindowWidth / 2 - 100.f, g_WindowHeight / 2.5f, 20.f, 20.f);
	FillEllipse(g_WindowWidth / 2 + 100.f, g_WindowHeight / 2.5f, 20.f, 20.f);
	FillArc(g_WindowWidth / 2, g_WindowHeight / 1.8f, 90.f, 100.f, 0, g_Pi);
}


#pragma endregion ownDefinitions