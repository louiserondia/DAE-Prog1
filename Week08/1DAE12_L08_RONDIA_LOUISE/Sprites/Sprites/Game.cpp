#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	TextureFromFile("Resources/walkingcycle girl.png", g_Girl);
	TextureFromFile("Resources/crab spritesheet.png", g_Crab);

	g_GirlPos.y = g_WindowHeight - g_Girl.height;
	g_GirlTile.width = g_Girl.width / g_GirlNrFrames;
	g_GirlTile.height = g_Girl.height;

	g_CrabTile.width = g_Crab.width / g_CrabNrCol;
	g_CrabTile.height = g_Crab.height / g_CrabNrRow;
}

void Draw()
{
	ClearBackground();
	DrawGirl();
	DrawCrab();
}

void Update(float elapsedSec)
{
	UpdateGirlPos(elapsedSec);
	UpdateGirlTile();
	UpdateCrabTile();

	g_GirlTime += elapsedSec;
	g_CrabTime += elapsedSec;
}

void End()
{
	DeleteTexture(g_Girl);
	DeleteTexture(g_Crab);
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{
}

void OnKeyUpEvent(SDL_Keycode key)
{
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
// Define your own functions here

void UpdateGirlTile() {
	const float frameRate{ 1.f / g_GirlNrFrames * .75f };
	g_GirlTile.left = g_GirlTile.width * g_GirlTileIndex;

	if (g_GirlTime > frameRate) {
		g_GirlTileIndex = (g_GirlTileIndex + 1) % g_GirlNrFrames;
		g_GirlTime = 0.f;
	}
}

void UpdateCrabTile() {
	const float frameRate{ 1.f / g_CrabNrFrames };
	const int row{ g_CrabTileIndex / g_CrabNrCol }, col{ g_CrabTileIndex % g_CrabNrCol };

	g_CrabTile.left = g_CrabTile.width * col;
	g_CrabTile.top = g_CrabTile.height * row;

	if (g_CrabTime > frameRate) {
		g_CrabTileIndex = (g_CrabTileIndex + 1) % g_CrabNrFrames;
		g_CrabTime = 0.f;
	}
}

void UpdateGirlPos(float elapsedSec) {
	g_GirlPos.x += elapsedSec * 50.f;
	if (g_GirlPos.x > g_WindowWidth)
		g_GirlPos.x = 0.f - g_Girl.width;
}

void DrawGirl() {
	DrawTexture(g_Girl, g_GirlPos, g_GirlTile);
}

void DrawCrab() {
	DrawTexture(g_Crab, g_CrabPos, g_CrabTile);
}

#pragma endregion ownDefinitions