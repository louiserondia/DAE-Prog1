#pragma once
#include <utils.h>
using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "Image And Text - Rondia, Louise - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 600 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

const Color4f g_White{ 1.f, 1.f, 1.f, 1.f };
const Color4f g_Red{ 1.f, 0.f, 0.f, 1.f };
const Color4f g_Green{ 0.f, 1.f, 0.f, 1.f };
const Color4f g_Blue{ 0.f, 0.f, 1.f, 1.f };

Texture g_ImgCrewmate{};
Texture g_ImgSus{};
Texture g_TextAmongUs{};
Texture g_TextRedIsSus{};

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
