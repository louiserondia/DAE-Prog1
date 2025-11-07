// 1DAE12 Louise Rondia

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

	SetColor(1.f, 0.9f, 0.98f, 1.f);
	FillRect(0.f, 0.f, g_WindowWidth, g_WindowHeight);

	DrawHouse();
	DrawFlag();
	DrawCheckerPattern();
	DrawColorBand();
	DrawPentagram();
	DrawColumnChart();
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
void DrawHouse() {
	const float width{ tileSize.x * 4 / 5 };
	const float height{ tileSize.y * 2 / 5 };
	const Point2f start(offset, offset);
	const Point2f triangleA{ start.x , start.y + height };
	const Point2f triangleB{ start.x + width / 2 , start.y };
	const Point2f triangleC{ start.x + width, start.y + height };
	const Point2f rect{ start.x, start.y + height };

	SetColor(c_red);
	FillTriangle(triangleA, triangleB, triangleC);
	FillRect(rect.x, rect.y, width, height);

	SetColor(c_white);
	DrawTriangle(triangleA, triangleB, triangleC);
	DrawRect(rect.x, rect.y, width, height);
}

void DrawFlag() {
	const float width{ tileSize.x * 4 / 5 };
	const float height{ tileSize.y * 4 / 5 };
	const Point2f start(offset, tileSize.y + offset);

	SetColor(c_black);
	FillRect(start.x, start.y, width / 3, height);

	SetColor(c_yellow);
	FillRect(start.x + width / 3, start.y, width / 3, height);

	SetColor(c_red);
	FillRect(start.x + width * 2 / 3, start.y, width / 3, height);

	SetColor(c_white);
	DrawRect(start.x, start.y, width, height);
}

void DrawCheckerPattern() {
	const float width{ tileSize.y * 4 / 5 };
	const Point2f start(offset, tileSize.y * 2 + offset);
	const Point2f rect{ start.x, start.y };

	SetColor(c_white);
	FillRect(rect.x, rect.y, width, width);

	SetColor(c_black);
	FillRect(rect.x, rect.y, width / 3, width / 3);
	FillRect(rect.x + width * 2 / 3, rect.y, width / 3, width / 3);
	FillRect(rect.x + width / 3, rect.y + width / 3, width / 3, width / 3);
	FillRect(rect.x, rect.y + width * 2 / 3, width / 3, width / 3);
	FillRect(rect.x + width * 2 / 3, rect.y + width * 2 / 3, width / 3, width / 3);

	SetColor(c_white);
	DrawRect(rect.x, rect.y, width, width);
}

void DrawColorBand() {
	const float width{ tileSize.x * 4 / 5 };
	const float height{ width / 9 * 4 }; // rectangles must be 4x higher than their width
	const float lineWidth{ 6.f };
	const Point2f start(tileSize.x + offset, offset);

	SetColor(c_yellow);
	FillRect(start.x - 3.f, start.y - 3.f, width + 6.f, height + 6.f);

	SetColor(c_grey);
	FillRect(start.x, start.y, width / 9, height);

	SetColor(c_red);
	FillRect(start.x + width / 9, start.y, width / 9, height);

	SetColor(c_green);
	FillRect(start.x + width * 2 / 9, start.y, width / 9, height);

	SetColor(c_blue);
	FillRect(start.x + width * 3 / 9, start.y, width / 9, height);

	SetColor(c_pink);
	FillRect(start.x + width * 4 / 9, start.y, width / 9, height);

	SetColor(c_yellow);
	FillRect(start.x + width * 5 / 9, start.y, width / 9, height);

	SetColor(c_green);
	FillRect(start.x + width * 6 / 9, start.y, width / 9, height);

	SetColor(c_cyan);
	FillRect(start.x + width * 7 / 9, start.y, width / 9, height);

	SetColor(c_white);
	FillRect(start.x + width * 8 / 9, start.y, width / 9, height);

	SetColor(0.f, 0.f, 0.f, 0.5f);
	FillRect(start.x, start.y + height / 2, width, height / 2);
}

void DrawPentagram() {
	const float radius{ tileSize.y * 2 / 5 };
	const float lineWidth{ 3.f };
	const float slice{ 360.f / 5.f / 180 * g_Pi };
	const Point2f start(tileSize.x * 1.5f, tileSize.y * 1.5f);
	
	SetColor(1.f, 0.f, 0.56f, 1.f);
	Point2f vertices[5] = {
		Point2f(start.x + cosf(0) * radius, start.y + sinf(0) * radius),
		Point2f(start.x + cosf(slice * 2) * radius, start.y + sinf(slice * 2) * radius),
		Point2f(start.x + cosf(slice * 4) * radius, start.y + sinf(slice * 4) * radius),
		Point2f(start.x + cosf(slice) * radius, start.y + sinf(slice) * radius),
		Point2f(start.x + cosf(slice * 3) * radius, start.y + sinf(slice * 3) * radius) };

	for (int i = 0; i < 5; i++) {
		utils::DrawLine(vertices[i], vertices[(i + 1) % 5], lineWidth);
	}
}

void DrawColumnChart() {
	const float height{ tileSize.y * 1.5f };
	const Point2f start(tileSize.x + offset, g_WindowHeight - offset);
	const float percentages[4] = { -0.2f, -0.35f, -0.35f, -0.1f };
	const float miniOffset{ 0.1f };

	SetColor(c_red);
	for (int i = 0; i < 4; i++) {
		SetColor(0.6f - miniOffset * i, 0.7f, 1.f, 1.f);
		FillRect(start.x + height * i / 5, start.y, height / 5, height * percentages[i]);
	}
}

// background color of the exercise was too ugly for me to change it 

#pragma endregion ownDefinitions