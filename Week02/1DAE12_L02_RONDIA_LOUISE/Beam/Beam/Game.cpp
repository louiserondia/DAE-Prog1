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

	SetColor(0.f, 0.f, 0.f);
	FillRect(0.f, 0.f, g_WindowWidth, g_WindowHeight);

	DrawPicture();

	// Put your own draw statements here

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

void DrawPicture() {
	const float border{ 10.f }, squareSize{ 200.f };

	SetColor(0.f, 0.5f, 0.f); // green
	FillRect(border, g_WindowHeight - border, squareSize, -squareSize);
	FillRect(g_WindowWidth - border, border, -squareSize, squareSize);

	SetColor(1.f, 1.f, 1.f); // white

	DrawRect(border, g_WindowHeight - border, squareSize, -squareSize);
	DrawRect(g_WindowWidth - border, border, -squareSize, squareSize);

	DrawLine(
		border,
		g_WindowHeight - squareSize - border,
		g_WindowWidth - squareSize - border,
		border
	);
	DrawLine(
		border + squareSize,
		g_WindowHeight - squareSize - border,
		g_WindowWidth - border,
		border
	);
	DrawLine(
		border ,
		g_WindowHeight - border,
		g_WindowWidth - squareSize - border,
		squareSize + border
	);
	DrawLine(
		border + squareSize,
		g_WindowHeight - border,
		g_WindowWidth - border,
		border + squareSize
	);

}


#pragma endregion ownDefinitions