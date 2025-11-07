#pragma once
#include <utils.h>
using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "Arc Work - Rondia, Louise - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 400 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
const Color4f backgroundColor{ 0.98f, 0.87f, 0.79f, 1.f };
const Color4f powderBlue{ 0.68f, 0.77f, 0.92f, 1.f };
const Color4f delftBlue{ 0.23f, 0.25f, 0.35f, 1.f };

struct Arcf {
	Point2f center;
	float radX;
	float radY;
	float fromAngle;
	float tillAngle;
};

struct ColorCombo {
	Arcf arc;
	Color4f color;
};
// Declare your own functions here

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
