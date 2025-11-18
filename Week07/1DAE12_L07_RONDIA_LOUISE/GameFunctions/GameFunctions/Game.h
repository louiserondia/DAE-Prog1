#pragma once
#include <utils.h>
using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "Game Functions - Rondia, Louise - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 600 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

const Color4f g_White{ 1.f, 1.f, 1.f, 1.f };
const Color4f g_Green{ 0.f, 1.f, 0.f, 1.f };
const Color4f g_TransRed{ 1.f, 0.f, 0.f, 0.5f };

Point2f g_MousePos{};

Circlef g_Circle{ Point2f{}, 100.f };
Circlef g_UserCircle{ Point2f{}, 50.f };
Rectf g_Rect{ 0.f, 0.f, 100.f, 150.f };
Rectf g_UserRect{ 0.f, 0.f, 80.f, 30.f };

// Declare your own functions here

void DrawCircles();
void DrawRects();
Point2f RandomPoint2f();

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
