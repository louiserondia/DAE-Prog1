#pragma once
#include <utils.h>
using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "Sliding Rectangles - Rondia, Louise - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 800 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

Color4f	g_Green{ 0.f, 1.f, 0.f, 0.5f };
Color4f	g_Blue{ 0.f, 0.f, 1.f, 0.5f };
Color4f	g_Red{ 1.f, 0.f, 0.f, 0.5f };
Color4f	g_Yellow{ 1.f, 1.f, 0.f, 0.5f };
Color4f	g_Black{ 0.f, 0.f, 0.f, 0.5f };

int		g_Direction{ 1 };
float	g_Move{0.f};
float	g_Size{ 100.f };
const	float g_Offset{ 20.f };
const	Point2f g_Mid{ g_WindowWidth / 2, g_WindowHeight / 2 };

Rectf	greenRect{ g_Mid.x - g_Size - g_Offset, g_Mid.y - g_Size - g_Offset, g_Size, g_Size };
Rectf	blueRect{ g_Mid.x + g_Offset, g_Mid.y - g_Size - g_Offset, g_Size, g_Size };
Rectf	redRect{ g_Mid.x - g_Size - g_Offset, g_Mid.y + g_Offset, g_Size, g_Size };
Rectf	yellowRect{ g_Mid.x + g_Offset, g_Mid.y + g_Offset, g_Size, g_Size };

// Declare your own functions here
void DrawRectangles();
void UpdateRectPos(float elapsedSec);

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
