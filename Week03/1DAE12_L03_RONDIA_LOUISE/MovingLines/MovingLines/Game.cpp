// Louise Rondia 1DAE12

#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions

#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground(0.66f, 0.5f, 0.9f);

	DrawVerticalLines();
	DrawDiagonalLines();

}

void Update(float elapsedSec)
{
	g_TimePassed += elapsedSec * 100;
	if (g_TimePassed > g_WindowWidth)
		g_TimePassed = 0.f;

	top.start.x = g_TimePassed;
	bottom.start.x = g_WindowWidth - g_TimePassed;
	left.start.y = g_TimePassed;
	right.start.y = g_WindowHeight - g_TimePassed;

	top.end.x = g_TimePassed;
	bottom.end.x = g_WindowWidth - g_TimePassed;
	left.end.y = g_TimePassed;
	right.end.y = g_WindowHeight - g_TimePassed;
}

void End()
{
	// free game resources here
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


void DrawVerticalLines() {
	SetColor(1.f, 1.f, 1.f);
	DrawLine(top.start.x, top.start.y, top.end.x, top.end.y);
	DrawLine(bottom.start.x, bottom.start.y, bottom.end.x, bottom.end.y);
	DrawLine(left.start.x, left.start.y, left.end.x, left.end.y);
	DrawLine(right.start.x, right.start.y, right.end.x, right.end.y);
}

void DrawDiagonalLines() {
	SetColor(1.f, 0.8f, 0.25f);
	DrawLine(top.end.x, top.end.y, left.start.x, left.start.y);
	DrawLine(left.start.x, left.start.y, bottom.end.x, bottom.end.y);
	DrawLine(bottom.end.x, bottom.end.y, right.start.x, right.start.y);
	DrawLine(right.start.x, right.start.y, top.end.x, top.end.y);
}

#pragma endregion ownDefinitions