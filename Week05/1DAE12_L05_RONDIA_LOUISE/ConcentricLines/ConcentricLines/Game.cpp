// Louise Rondia, 1GD12E

#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	g_MousePos = Point2f{ g_WindowWidth / 2, g_WindowHeight / 2 };
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);
	DrawConcentricLines();

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
	SwitchColor();
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	g_MousePos = Point2f{ float(e.x), float(e.y) };
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

void DrawConcentricLines() {
	Color4f color{};

	switch (g_Color)
	{
	case Color::red:
		color.r = 1.f;
		break;
	case Color::green:
		color.g = 1.f;
		break;
	case Color::blue:
		color.b = 1.f;
		break;
	default:
		break;
	}

	SetColor(color);

	for (float iterator{ 0.f }; iterator <= g_WindowWidth; iterator += g_LineOffset) {
		DrawLine(iterator, 0.f, g_MousePos.x, g_MousePos.y);
		DrawLine(iterator, g_WindowHeight, g_MousePos.x, g_MousePos.y);
	}
	for (float iterator{ 0.f }; iterator <= g_WindowHeight; iterator += g_LineOffset) {
		DrawLine(0.f, iterator, g_MousePos.x, g_MousePos.y);
		DrawLine(g_WindowWidth, iterator, g_MousePos.x, g_MousePos.y);
	}
}

void SwitchColor() {
	g_Color = static_cast<Color>((int(g_Color) + 1) % 3);
}

#pragma endregion ownDefinitions