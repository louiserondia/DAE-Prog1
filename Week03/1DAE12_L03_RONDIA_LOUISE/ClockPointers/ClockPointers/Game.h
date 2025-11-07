#pragma once
#include <utils.h>
using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "CLock Pointer - Rondia, Louise - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 800 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
Point2f start{ g_WindowWidth / 2, g_WindowHeight / 2 };

struct Pointer {
	const Point2f start{ g_WindowWidth / 2, g_WindowHeight / 2 };
	Point2f midLeft;
	Point2f midRight;
	Point2f end;
	float length;
	float angle;
};

Pointer smallPointer{};
Pointer bigPointer{};

// Declare your own functions here

void DrawPointer(Pointer pointer);


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
