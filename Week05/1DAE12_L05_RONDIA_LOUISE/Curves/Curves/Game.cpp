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
	ClearBackground(0.f, 0.f, 0.3f);
	DrawDecagon();
	DrawCrosier();
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

void DrawDecagon() {
	const Point2f	start{ g_WindowWidth / 4, g_WindowHeight / 2 };
	const float		width{ g_WindowWidth / 6 };
	const float		height{ g_WindowWidth / 5 };
	const float		arc{ g_Pi / 5 };

	Point2f			p1{};
	Point2f			p2{};

	SetColor(1.f, 0.f, 0.f);
	for (int i = 0; i < 10; i++) {
		p1 = Point2f{ start.x + cos(arc * i) * width, start.y + sin(arc * i) * height };
		p2 = Point2f{ start.x + cos(arc * (i + 1)) * width, start.y + sin(arc * (i + 1)) * height };
		DrawLine(p1, p2, 1.f);
	}
}

float RadiusFormula(float a, float angle) {
	return a / sqrtf(angle);
}

Point2f	PointFormula(Point2f start, float radius, float angle) {
	return Point2f{ start.x + radius * cos(angle), start.y + radius * -sin(angle) };
}

void DrawCrosier() {
	const Point2f	start{ g_WindowWidth / 4 * 3, g_WindowHeight / 2 };
	const float		step{ .01f };
	
	const float a{ g_WindowWidth / 4 }; // radius de départ
	const float b{ 8 }; // nbr de tours de cercle

	float angle{ g_Pi / 2 };
	float maxAngle{ b * 2 * g_Pi - g_Pi / 2 };
	float radius{ RadiusFormula(a, angle) };

	Point2f	p1{};
	Point2f	p2{};

	SetColor(0.5f, 0.f, 1.f);

	while (angle <= maxAngle) {
		Point2f	p1{ PointFormula(start, radius, angle) };
		angle += step;
		radius = RadiusFormula(a, angle);
		Point2f	p2{ PointFormula(start, radius, angle) };
		DrawLine(p1, p2);
	}


}

#pragma endregion ownDefinitions