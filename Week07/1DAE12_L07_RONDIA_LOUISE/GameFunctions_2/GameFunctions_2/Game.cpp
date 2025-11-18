#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
}

void Draw()
{
	ClearBackground();

	const Point2f
		left{ 0.f, g_WindowHeight },
		top{ g_WindowWidth / 2, 0.f },
		right{ g_WindowWidth, g_WindowHeight };

	DrawSierpinskiTriangle(left, top, right, g_Red);
}

void Update(float elapsedSec)
{
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

void DrawSierpinskiTriangle(const Point2f& left, const Point2f& top, const Point2f& right, const Color4f& color) {
	SetColor(color);

	DrawTriangle(left, top, right);
	const float length{ right.x - left.x };
	if (length < 20.f)
		return;

	const Point2f midLeft{ left.x + (top.x - left.x) / 2,  left.y + (top.y - left.y) / 2 },
		midright{ right.x + (top.x - right.x) / 2,  right.y + (top.y - right.y) / 2 },
		midBottom{ left.x + length / 2,  left.y };

	DrawSierpinskiTriangle(left, midLeft, midBottom, g_Red);
	DrawSierpinskiTriangle(midLeft, top, midright, g_Green);
	DrawSierpinskiTriangle(midBottom, midright, right, g_Blue);
}

#pragma endregion ownDefinitions