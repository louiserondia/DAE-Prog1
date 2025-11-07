#pragma once
#include <utils.h>
using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "Explosion - Rondia, Louise - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 600 };
float g_WindowHeight{ 600 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

const float			g_Size{ 100.f };
const Point2f		g_Start{ (g_WindowWidth - g_Size) / 2, (g_WindowHeight - g_Size) / 2 };
const Color4f		g_Red{ 1.f, 0.f, 0.f, 1.f };
const Color4f		g_Black{ 0.f, 0.f, 0.f, 1.f };
const Color4f		g_TransBlack{ 0.f, 0.f, 0.f, .5f };

Color4f				g_BombColor{};
float				g_Distance{};
bool				g_IsExploding{};

// Declare your own functions here

void Init();
void DrawExplosion();
void ProcessMouseClick(Point2f mouse);
void UpdateExplosion();

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
