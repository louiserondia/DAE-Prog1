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

	float outerRadius{ 200.f };
	float innerRadius{ 100.f };

	const Point2f outerStart{ g_WindowWidth / 2 + outerRadius, g_WindowHeight / 2};
	const Point2f outerTop{ g_WindowWidth / 2, g_WindowHeight / 2 - outerRadius };
	const Point2f outerLeft{ g_WindowWidth / 2 - outerRadius, g_WindowHeight / 2};
	const Point2f outerBottom{ g_WindowWidth / 2, g_WindowHeight / 2 + outerRadius };

	const Point2f innerStart{ g_WindowWidth / 2 + innerRadius, g_WindowHeight / 2 - innerRadius };
	const Point2f innerTop{ g_WindowWidth / 2 - innerRadius, g_WindowHeight / 2 - innerRadius };
	const Point2f innerLeft{ g_WindowWidth / 2 - innerRadius, g_WindowHeight / 2 + innerRadius };
	const Point2f innerBottom{ g_WindowWidth / 2 + innerRadius, g_WindowHeight / 2 + innerRadius };

	DrawLine(outerStart, innerStart);
	DrawLine(innerStart, outerTop);
	DrawLine(outerTop, innerTop);
	DrawLine(innerTop, outerLeft);
	DrawLine(outerLeft, innerLeft);
	DrawLine(innerLeft, outerBottom);
	DrawLine(outerBottom, innerBottom);
	DrawLine(innerBottom, outerStart);

	// calculate the positions of crossing stars with cos and sin of each angle where the 2 stars cross

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