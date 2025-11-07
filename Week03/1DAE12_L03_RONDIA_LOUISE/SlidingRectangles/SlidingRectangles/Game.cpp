#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
}

void Draw()
{
	ClearBackground();
	DrawRectangles();
}

void Update(float elapsedSec)
{
	UpdateRectPos(elapsedSec);
}

void End()
{
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

void DrawRectangles() {

	SetColor(g_Red);
	FillRect(redRect);

	SetColor(g_Yellow);
	FillRect(yellowRect);

	SetColor(g_Blue);
	FillRect(blueRect);

	SetColor(g_Green);
	FillRect(greenRect);

	SetColor(g_Black);
	DrawRect(redRect);
	DrawRect(yellowRect);
	DrawRect(blueRect);
	DrawRect(greenRect);

}

void UpdateRectPos(float elapsedSec) {

	if (greenRect.top < 0.f || greenRect.top  > g_WindowHeight - g_Size)
		g_Direction *= -1;

	g_Move = elapsedSec * 100 * g_Direction;

	redRect.left -= g_Move;
	redRect.top += g_Move;
	yellowRect.left += g_Move;
	yellowRect.top += g_Move;
	blueRect.left += g_Move;
	blueRect.top -= g_Move;
	greenRect.left -= g_Move;
	greenRect.top -= g_Move;

}

#pragma endregion ownDefinitions