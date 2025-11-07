#include "pch.h"
#include "Game.h"
#include <iostream>

#pragma region gameFunctions											
void Start()
{
	Init();
}

void Draw()
{
	ClearBackground(.5f, .5f, .5f);
	DrawExplosion();
}

void Update(float elapsedSec)
{
	UpdateExplosion();
}

void End()
{
}
#pragma endregion gameFunctions

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
	if (e.button == SDL_BUTTON_LEFT)
		ProcessMouseClick(Point2f{ float(e.x), float(e.y) });
}
#pragma endregion inputHandling

#pragma region ownDefinitions

void Init() {
	g_BombColor = g_Black;
	g_Distance = 0.f;
	g_IsExploding = false;
}

void UpdateExplosion() {
	if (g_IsExploding)
		++g_Distance;
	if (g_Distance > (g_WindowWidth + g_Size) / 2) {
		Init();
	}
}

void DrawExplosion() {
	SetColor(g_Red);
	FillRect(g_Start.x - g_Distance, g_Start.y - g_Distance, g_Size, g_Size);
	FillRect(g_Start.x + g_Distance, g_Start.y - g_Distance, g_Size, g_Size);
	FillRect(g_Start.x - g_Distance, g_Start.y + g_Distance, g_Size, g_Size);
	FillRect(g_Start.x + g_Distance, g_Start.y + g_Distance, g_Size, g_Size);

	SetColor(g_BombColor);
	FillRect(g_Start, g_Size, g_Size);
}

void ProcessMouseClick(Point2f mouse) {
	if (mouse.x >= g_Start.x && mouse.y >= g_Start.y
		&& mouse.x <= g_Start.x + g_Size && mouse.y <= g_Start.y + g_Size) {
		g_IsExploding = true;
		g_BombColor = g_TransBlack;
	}

}

#pragma endregion ownDefinitions