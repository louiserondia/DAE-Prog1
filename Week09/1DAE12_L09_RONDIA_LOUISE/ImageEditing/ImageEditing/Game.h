#pragma once
#include <utils.h>
using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "Image Editing - Rondia, Louise - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 600 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

enum class Mod
{
	neutral,
	grey,
	sepia,
	brighter,
	darker
};

Texture		g_Image{};
std::string	g_Path{};
Point2f		g_Pos{};
Color4f* g_Pixels;
Color4f* g_ModPixels;

const float	g_Speed{ 75.f };
Mod			g_Mod{};

// Declare your own functions here

void DrawPixels(const Color4f* pixels, Point2f start);
void PixelManipulationFromKey(SDL_Keycode key);
void GetNeutralPixels(Color4f* modPixels, const Color4f* pixels, int arraySize);
void GetGreyScalePixels(Color4f* modPixels, const Color4f* pixels, int arraySize);
void GetSepiaPixels(Color4f* modPixels, const Color4f* pixels, int arraySize);
void GetBrighterPixels(Color4f* modPixels, const Color4f* pixels, int arraySize);
void GetDarkerPixels(Color4f* modPixels, const Color4f* pixels, int arraySize);

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
