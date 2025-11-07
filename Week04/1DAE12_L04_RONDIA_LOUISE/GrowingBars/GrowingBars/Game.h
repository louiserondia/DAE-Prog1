#pragma once
#include <utils.h>
using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "Growing Bars - Rondia, Louise - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 600 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

float	g_PassedTime{ 0 };
int		g_PassedFrames{ -1 };

const Color4f g_Yellow{ 1.f, 0.7f, 0.2f, 1.f };
const Color4f g_Blue{ 0.2f, 0.6f, 1.f, 1.f };
const Color4f g_Red{ 0.1f, 0.f, 0.f, 1.f };
const Color4f g_White{ 1.f, 1.f, 1.f, 1.f };

const float g_RectWidth{ g_WindowWidth / 2 };
const float g_RectHeight{ g_WindowHeight / 6 };
const float	g_Left{ g_WindowWidth / 4 };
const float	g_Top{ g_WindowHeight / 6 };

const Rectf g_OuterTopRect{ g_Left, g_Top, g_RectWidth, g_RectHeight };
const Rectf g_OuterMidRect{ g_Left, g_Top + 150.f , g_RectWidth, g_RectHeight };
const Rectf g_OuterBottomRect{ g_Left, g_Top + 300.f, g_RectWidth, g_RectHeight };

Rectf g_InnerTopRect{ g_Left,  g_Top, g_RectWidth, g_RectHeight };
Rectf g_InnerMidRect{ g_Left,  g_Top + 150.f, g_RectWidth, g_RectHeight };
Rectf g_InnerBottomRect{ g_Left,  g_Top + 300.f, g_RectWidth, g_RectHeight };

Color4f	g_BottomRectColor{ g_Blue };

// own functions

void DrawBars();
Color4f	RandomColor();

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
