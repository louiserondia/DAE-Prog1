#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground();
	DrawMouse();

}

void Update(float elapsedSec)
{

}

void End()
{
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{
	std::cout << "Key down here with code " << key << std::endl;
}

void OnKeyUpEvent(SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_LEFT:
		std::cout << "Left arrow key released\n";
		break;
	case SDLK_RIGHT:
		std::cout << "Right arrow key released\n";
		break;
	default:
		std::cout << "Key released here with code " << key << std::endl;
		break;
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	g_Mouse = Point2f{ static_cast<float>(e.x), static_cast<float>(e.y) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	std::cout << "  [" << g_Mouse.x << ", " << g_Mouse.y << "]\n";
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	std::cout << "  [" << g_Mouse.x << ", " << g_Mouse.y << "]\n";
	
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		std::cout << "Left mouse button released\n";
		break;
	case SDL_BUTTON_RIGHT:
		std::cout << "Right mouse button released\n";
		break;
	case SDL_BUTTON_MIDDLE:
		std::cout << "Middle mouse button released\n";
		break;
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void DrawMouse() {
	SetColor(1.f, 0.f, 0.f);
	FillRect(g_Mouse.x - 5.f, g_Mouse.y - 5.f, 10.f, 10.f);
}

#pragma endregion ownDefinitions