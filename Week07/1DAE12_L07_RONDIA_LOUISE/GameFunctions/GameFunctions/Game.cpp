#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	g_Circle = Circlef{ RandomPoint2f(), 100.f };
	g_Rect = Rectf{ RandomPoint2f().x, RandomPoint2f().y, 100.f , 150.f };
	g_UserCircle.center = RandomPoint2f();
}

void Draw()
{
	ClearBackground();

	DrawCircles();
	DrawRects();
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
	const float speed{ 7.f };

	if (key == SDLK_LEFT)
		g_UserCircle.center.x -= speed;
	if (key == SDLK_UP)
		g_UserCircle.center.y -= speed;
	if (key == SDLK_DOWN)
		g_UserCircle.center.y += speed;
	if (key == SDLK_RIGHT)
		g_UserCircle.center.x += speed;
}

void OnKeyUpEvent(SDL_Keycode key)
{
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	g_MousePos.x = static_cast<float>(e.x);
	g_MousePos.y = static_cast<float>(e.y);
	g_UserRect.left = static_cast<float>(e.x);
	g_UserRect.top = static_cast<float>(e.y);
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

Point2f RandomPoint2f() {
	return Point2f{
		static_cast<float>(rand() % static_cast<int>(g_WindowWidth)),
		static_cast<float>(rand() % static_cast<int>(g_WindowHeight))
	};
}

void DrawCircles() {
	SetColor(g_White);
	FillEllipse(g_Circle.center, g_Circle.radius, g_Circle.radius);

	SetColor(g_Green);
	if (IsOverlapping(g_UserCircle, g_Circle))
		SetColor(g_TransRed);
	FillEllipse(g_UserCircle.center, g_UserCircle.radius, g_UserCircle.radius);
}

void DrawRects() {
	SetColor(g_White);
	FillRect(g_Rect);

	SetColor(g_Green);
	if (IsOverlapping(g_UserRect, g_Rect))
		SetColor(g_TransRed);

	FillRect(g_UserRect);
}


#pragma endregion ownDefinitions