#pragma once
#include <utils.h>
using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "Looped Drawings - Rondia, Louise - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

float g_Offset{ 20.f };
Color4f	g_Blue{ 0.5f, 0.7f, 1.f, 1.f };
Color4f	g_Red{ 1.f, 0.5f, 0.5f, 1.f };
Color4f	g_Green{ 0.5f, 0.8f, 0.5f, 1.f };
Color4f	g_Yellow{ 0.8f, 0.8f, 0.2f, 1.f };

// Declare your own functions here
void DrawStairs();
void DrawConcentricSquares();
void DrawConcentricSpiral();
void DrawSpinningLines();


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
