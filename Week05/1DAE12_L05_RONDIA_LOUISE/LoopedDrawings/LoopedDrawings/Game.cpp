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
	ClearBackground(0.f, 0.f, 0.f);

	DrawStairs();
	DrawConcentricSquares();
	DrawConcentricSpiral();
	DrawSpinningLines();
}

void Update(float elapsedSec)
{
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
// Define your own functions here

void DrawStairs() {
	Point2f	p1{ g_Offset, g_WindowHeight / 2 - g_Offset };
	Point2f	p2{ g_Offset * 3, g_WindowHeight / 2 - g_Offset };

	for (int i = 0; i < 10; i++) {
		if (i % 4 > 1)
			SetColor(g_Blue);
		else
			SetColor(g_Red);

		DrawLine(p1, p2, 3.f);

		p1 = p2;
		if (i & 1)
			p2.x += 2 * g_Offset;
		else
			p2.y -= 2 * g_Offset;
	}
}

void DrawConcentricSquares() {
	SetColor(g_Green);
	Point2f topLeft{ g_Offset, g_WindowHeight / 2 + g_Offset };
	float length{ g_WindowWidth / 2 - 2 * g_Offset };
	const float	width{ 3.f };

	for (int i = 0; i < 5; i++) {
		DrawLine(topLeft.x, topLeft.y, topLeft.x + length, topLeft.y, width);
		DrawLine(topLeft.x + length, topLeft.y, topLeft.x + length, topLeft.y + length, width);
		DrawLine(topLeft.x + length, topLeft.y + length, topLeft.x, topLeft.y + length, width);
		DrawLine(topLeft.x, topLeft.y + length, topLeft.x, topLeft.y, width);
		length -= 2 * g_Offset;
		topLeft.x += g_Offset;
		topLeft.y += g_Offset;
	}
}

void DrawConcentricSpiral() {
	SetColor(g_Blue);
	float length{ g_WindowWidth / 2 - 2 * g_Offset };
	Point2f p2{ g_WindowWidth / 2 + g_Offset, g_WindowHeight - g_Offset };
	Point2f p1{ };
	const float	width{ 3.f };

	for (int i = 0; i < 20; i++) {
		p1 = p2;
		switch (i % 4)
		{
		case 0:
			p2.x += length;
			break;
		case 1:
			p2.y -= length;
			length -= g_Offset;
			break;
		case 2:
			p2.x -= length;
			break;
		case 3:
			p2.y += length;
			length -= g_Offset;
			break;
		default:
			break;
		}
		DrawLine(p1, p2, width);
	}
}

void DrawSpinningLines() {
	Point2f start{ Point2f(g_WindowWidth / 2 + g_Offset, g_Offset) };
	const float length{ g_WindowWidth / 2 - g_Offset * 2 };
	const float dist{ length / 5 };
	const float width{ 3.f };
	Point2f next{ start.x + length, start.y };

	SetColor(g_Green);
	for (int i = 0; i < 5; i++) {
		DrawLine(start, next, width);
		start.x += dist;
		next.y += dist;
	}

	SetColor(g_Red);
	for (int i = 0; i < 5; i++) {
		DrawLine(start, next, width);
		start.y += dist;
		next.x -= dist;
	}

	SetColor(g_Yellow);
	for (int i = 0; i < 5; i++) {
		DrawLine(start, next, width);
		start.x -= dist;
		next.y -= dist;
	}

	SetColor(g_Blue);
	for (int i = 0; i < 5; i++) {
		DrawLine(start, next, width);
		start.y -= dist;
		next.x += dist;
	}
}

#pragma endregion ownDefinitions