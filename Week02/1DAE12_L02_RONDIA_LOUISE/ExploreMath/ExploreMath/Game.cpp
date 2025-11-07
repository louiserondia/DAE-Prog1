#include "pch.h"
#include "Game.h"
#include <iostream>

float rotationX{ 0.f }; // cos(rotationX) fait tourner sur lui-même sur un axe
float rotationY{ 0.f }; // ajouter a tous les cos et sin de base pour tourner comme un poirier

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground();
	Point2f center(g_WindowWidth / 2, g_WindowHeight / 2);
	float radius{ 200.f };

	Point2f
		vertexA{ center.x + cosf(0.f + rotationY) * radius * 0.8f * cosf(rotationX), center.y + sinf(0.f + rotationY) * radius * 0.8f },
		vertexB{ center.x + cosf(g_Pi * 2 / 3 + rotationY) * radius * 0.8f * cosf(rotationX), center.y + sinf(g_Pi * 2 / 3 + rotationY) * radius * 0.8f },
		vertexC{ center.x + cosf(g_Pi * 4 / 3 + rotationY) * radius * 0.8f * cosf(rotationX), center.y + sinf(g_Pi * 4 / 3 + rotationY) * radius * 0.8f };

	DrawEllipse(center.x, center.y, radius, radius, 3.f);
	DrawTriangle(vertexA, vertexB, vertexC, 3.f);
	rotationX += 0.02f;
	rotationY += 0.01f;
}

void Update(float elapsedSec)
{
	// process input, do physics 

	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
}

void End()
{
	// free game resources here
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	// SAMPLE CODE: print mouse position
	//const float mouseX{ float(e.x) };
	//const float mouseY{ float(e.y) };
	//std::cout << "  [" << mouseX << ", " << mouseY << "]\n";
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	// SAMPLE CODE: print mouse position
	//const float mouseX{ float(e.x) };
	//const float mouseY{ float(e.y) };
	//std::cout << "  [" << mouseX << ", " << mouseY << "]\n";
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	// SAMPLE CODE: print mouse position
	//const float mouseX{ float(e.x) };
	//const float mouseY{ float(e.y) };
	//std::cout << "  [" << mouseX << ", " << mouseY << "]\n";

	// SAMPLE CODE: check which mouse button was pressed
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//	//std::cout << "Left mouse button released\n";
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

#pragma endregion ownDefinitions