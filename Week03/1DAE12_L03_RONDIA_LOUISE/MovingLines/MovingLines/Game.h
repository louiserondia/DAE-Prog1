#pragma once
#include <utils.h>
using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "Moving Lines - Rondia, Louise - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

float g_TimePassed{ 0.f };

struct Line {
	Point2f start{};
	Point2f end{};
};

Line top{ Point2f(0, 0), Point2f(0, g_WindowHeight) };
Line left{ Point2f(0, 0), Point2f(g_WindowWidth, 0) };
Line bottom{ Point2f(g_WindowWidth, g_WindowHeight), Point2f(g_WindowWidth, 0) };
Line right{ Point2f(g_WindowWidth, g_WindowHeight), Point2f(0, g_WindowHeight) };

// Declare your own functions here

void DrawVerticalLines();
void DrawDiagonalLines();

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
