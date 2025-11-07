// Rondia, Louise, 1DAE12

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

	// Drawing red lines

	SetColor(1.f, 0.f, 0.f, 1.f); // red
	float thickness{ 2.f };

	DrawLine(0, 0, g_WindowWidth, g_WindowHeight, thickness);
	DrawLine(0, g_WindowHeight, g_WindowWidth, 0, thickness);


	// Drawing white lines

	SetColor(1.f, 1.f, 1.f, 1.f); // white

	float heightThird{ g_WindowHeight / 3 };
	float widthThird{ g_WindowWidth / 3 };

	DrawLine(0, heightThird, g_WindowWidth, heightThird, thickness);
	DrawLine(0, heightThird * 2, g_WindowWidth, heightThird * 2, thickness);
	DrawLine(widthThird, 0, widthThird, g_WindowHeight, thickness);
	DrawLine(widthThird * 2, 0, widthThird * 2, g_WindowHeight, thickness);

	// Drawing central dot

	SetColor(0.f, 0.f, 1.f, 1.f); // blue

	float width{ 4.f };
	float height{ 4.f };
	float xPos{ g_WindowWidth / 2 - width / 2 };
	float yPos{ g_WindowHeight / 2 - height / 2 };

	FillRect(xPos, yPos, width, height);

	// Drawing border green rectangle

	SetColor(0.f, 1.f, 0.f, 1.f); // green

	DrawRect(0, 0, g_WindowWidth, g_WindowHeight, 4.f);

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