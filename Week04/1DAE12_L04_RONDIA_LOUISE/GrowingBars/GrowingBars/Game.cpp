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
	ClearBackground(0.8f, 0.8f, 0.8f);

	DrawBars();
}

void Update(float elapsedSec)
{
	++g_PassedFrames;
	g_PassedTime += elapsedSec;
	g_InnerTopRect.width = int(g_RectWidth * g_PassedTime / 10) % int(g_RectWidth); // smooth
	g_InnerMidRect.width = int(g_RectWidth * g_PassedTime) % int(g_RectWidth); // smooth fast

	if (g_PassedFrames % 50 == 0) {
		g_InnerBottomRect.width =
			int(g_RectWidth / 8 * (g_PassedFrames / 50)) % int(g_RectWidth);
	}
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
	if (key == SDLK_r) {
		g_PassedFrames = -1;
		g_PassedTime = 0.f;
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	Point2f mouse = Point2f{ float(e.x), float(e.y) };

	if (mouse.x >= g_InnerBottomRect.left && mouse.x <= g_InnerBottomRect.left + g_RectWidth
		&& mouse.y >= g_InnerBottomRect.top && mouse.y <= g_InnerBottomRect.top + g_RectHeight) {
		g_BottomRectColor = RandomColor();
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions

Color4f	RandomColor() {
	return  Color4f{ 
		static_cast<float>(rand()) / RAND_MAX,
		static_cast<float>(rand()) / RAND_MAX,
		static_cast<float>(rand()) / RAND_MAX,
		1.f };
}


void DrawBars() {
	SetColor(g_Yellow);
	FillRect(g_InnerTopRect);
	SetColor(g_Red);
	FillRect(g_InnerMidRect);

	SetColor(g_BottomRectColor);
	FillRect(g_InnerBottomRect);

	SetColor(g_White);

	DrawRect(g_OuterTopRect, 3.f);
	DrawRect(g_OuterMidRect, 3.f);
	DrawRect(g_OuterBottomRect, 3.f);
}

#pragma endregion ownDefinitions