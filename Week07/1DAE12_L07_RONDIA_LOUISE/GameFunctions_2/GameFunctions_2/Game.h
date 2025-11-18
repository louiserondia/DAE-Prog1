#pragma once
#include <utils.h>
using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "Game Functions 2 (recursion) - Rondia, Louise - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 600 };
#pragma endregion gameInformation

#pragma region ownDeclarations
// Declare your own global variables here

const Color4f	g_Red{ 1.f, 0.f, 0.f, 1.f };
const Color4f	g_Green{ 0.f, 1.f, 0.f,  1.f };
const Color4f	g_Blue{ 0.f, 0.f,  1.f,1.f };

// Declare your own functions here

void DrawSierpinskiTriangle(const Point2f& left, const Point2f& top, const Point2f& right, const Color4f& color);

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
