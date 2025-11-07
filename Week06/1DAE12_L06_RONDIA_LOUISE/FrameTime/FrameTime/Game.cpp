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
	PrintFrameTimeInfos();

	DrawBall(g_BallCenter, g_BallRadius, Color4f{ 1.f, 0.f, 0.f, 1.f });
	DrawFreeFall(g_SquareTopLeft, g_SquareWidth, Color4f{ 1.f, 1.f, 0.f, 1.f });

	++g_FrameCount;
}

void Update(float elapsedSec)
{
	g_TotalElapsedTime += elapsedSec;
	UpdateBall(elapsedSec);
	UpdateFreeFall(elapsedSec);
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
	if (key == SDLK_s)
		g_IsSquareFalling = true;
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

void PrintFrameTimeInfos() {
	if (g_FrameCount % 100 == 0) {
		std::cout
			<< "Number of frames : " << g_FrameCount
			<< "	Accumulated time : " << g_TotalElapsedTime
			<< "	Frame rate : " << float(g_FrameCount) / g_TotalElapsedTime
			<< std::endl;
	}
}

void UpdateBall(float elapsedSec) {
	g_BallCenter.x += g_BallSpeed.x * elapsedSec;
	g_BallCenter.y += g_BallSpeed.y * elapsedSec;

	if (g_BallCenter.x - g_BallRadius <= 0.f || g_BallCenter.x + g_BallRadius >= g_WindowWidth)
		g_BallSpeed.x *= -1;
	else if (g_BallCenter.y - g_BallRadius <= 0.f || g_BallCenter.y + g_BallRadius >= g_WindowHeight)
		g_BallSpeed.y *= -1;
}

void DrawBall(float centerX, float centerY, float radius, Color4f color) {
	DrawBall(Point2f{ centerX, centerY }, radius, color);
}

void DrawBall(Point2f center, float radius, Color4f color) {
	SetColor(color);
	FillEllipse(center, radius, radius);
}

void 	UpdateFreeFall(float elapsedSec) {
	if (!g_IsSquareFalling)
		return;

	g_SquareVelocity += g_Acceleration * elapsedSec;
	g_SquareTopLeft.y += g_SquareVelocity * elapsedSec;

	if (!g_IsSquareBouncing && g_SquareTopLeft.y + g_SquareWidth >= g_WindowHeight) {
		g_SquareVelocity *= g_SquareBounceCoefficient;
		g_IsSquareBouncing = true;
	}
	else if (g_IsSquareBouncing && g_SquareVelocity >= 0) {
		g_IsSquareBouncing = false;
	}
}


void 	DrawFreeFall(float left, float top, float width, Color4f color) {
	DrawFreeFall(Point2f{ left, top }, width, color);
}
void 	DrawFreeFall(Point2f topLeft, float width, Color4f color) {
	SetColor(color);
	FillRect(topLeft, width, width);
}

#pragma endregion ownDefinitions