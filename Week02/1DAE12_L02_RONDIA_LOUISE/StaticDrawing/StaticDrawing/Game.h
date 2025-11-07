#pragma once
#include <utils.h>
using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "Static Drawing - Rondia, Louise - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 1080 };
float g_WindowHeight{ 720 };
#pragma endregion gameInformation



#pragma region ownDeclarations

const int columns{ 2 };
const int rows{ 3 };
const Point2f tileSize{ g_WindowWidth / columns, g_WindowHeight / rows };
const float offset{ 20.f };

const Color4f c_black{ 0.f, 0.f, 0.f, 1.f };
const Color4f c_grey{ 0.1f, 0.1f, 0.1f, 1.f };
const Color4f c_red{ 1.f, 0.f, 0.f, 1.f };
const Color4f c_green{ 0.f, 1.f, 0.f, 1.f };
const Color4f c_blue{ 0.f, 0.f, 1.f, 1.f };
const Color4f c_yellow{ 1.f, 1.f, 0.f, 1.f };
const Color4f c_pink{ 1.f, 0.f, 1.f, 1.f };
const Color4f c_cyan{ 0.f, 1.f, 1.f, 1.f };
const Color4f c_white{ 1.f, 1.f, 1.f, 1.f };

const Color4f colors[10] = {
	c_black,
	c_grey,
	c_red,
	c_green,
	c_blue,
	c_yellow,
	c_pink,
	c_cyan,
	c_white
};

void DrawHouse();
void DrawFlag();
void DrawCheckerPattern();
void DrawColorBand();
void DrawPentagram();
void DrawColumnChart();

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
