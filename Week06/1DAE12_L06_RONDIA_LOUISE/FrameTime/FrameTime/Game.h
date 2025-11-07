#pragma once
#include <utils.h>
using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "Frame Time - Rondia, Louise - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 600 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

float	g_Acceleration{ 9.8f };

int		g_FrameCount{};
float	g_TotalElapsedTime{};
float	g_IntervalTime{};

Point2f	g_BallCenter{g_WindowWidth / 2, g_WindowHeight / 2};
Point2f	g_BallSpeed{ 100.f, 80.f };
const float	g_BallRadius{ 50.f };

Point2f	g_SquareTopLeft{ g_WindowWidth / 4, g_WindowHeight / 4 };
bool	g_IsSquareFalling{ false };
bool	g_IsSquareBouncing{ false };
float	g_SquareVelocity{ 0.f };
float	g_SquareWidth{ 50.f };
const float	g_SquareBounceCoefficient{ -0.5f };


// Declare your own functions here

void PrintFrameTimeInfos();

void UpdateBall(float elapsedSec);
void DrawBall(Point2f center, float radius, Color4f color);
void DrawBall(float centerX, float centerY, float radius, Color4f color);

void 	UpdateFreeFall(float elapsedSec);
void 	DrawFreeFall(Point2f topLeft, float width, Color4f color);
void 	DrawFreeFall(float left, float top, float width, Color4f color);


#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
