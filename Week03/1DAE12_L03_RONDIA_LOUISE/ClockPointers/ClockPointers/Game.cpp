#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	smallPointer.length = g_WindowWidth / 4;
	smallPointer.angle = 0.f;
	bigPointer.length = g_WindowWidth / 3;
	bigPointer.angle = 0.f;
}

void Draw()
{
	ClearBackground();

	const float tic{ 1.f / 240 };

	smallPointer.angle += tic / 12;
	bigPointer.angle += tic;
	
	DrawPointer(smallPointer);
	DrawPointer(bigPointer);
}

void Update(float elapsedSec)
{
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

void DrawPointer(Pointer pointer) {
	pointer.midLeft = Point2f(
		pointer.start.x + pointer.length / 3 * cos(pointer.angle - .2f),
		pointer.start.y + pointer.length / 3 * sin(pointer.angle - .2f)
	);
	pointer.midRight = Point2f(
		pointer.start.x + pointer.length / 3 * cos(pointer.angle + .2f),
		pointer.start.y + pointer.length / 3 * sin(pointer.angle + .2f)
	);
	pointer.end = Point2f(
		pointer.start.x + pointer.length * cos(pointer.angle),
		pointer.start.y + pointer.length * sin(pointer.angle)
	);

	DrawLine(pointer.start, pointer.midLeft);
	DrawLine(pointer.start, pointer.midRight);
	DrawLine(pointer.midLeft, pointer.end);
	DrawLine(pointer.midRight, pointer.end);
}

#pragma endregion ownDefinitions