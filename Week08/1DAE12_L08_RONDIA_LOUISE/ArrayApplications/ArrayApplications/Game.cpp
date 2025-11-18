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

	DrawClickPolygon();
}

void Update(float elapsedSec)
{
	// Check keyboard state
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
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{
}

void OnKeyUpEvent(SDL_Keycode key)
{
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//const float mouseX{ float(e.x) };
	//const float mouseY{ float(e.y) };
	//std::cout << "  [" << mouseX << ", " << mouseY << "]\n";
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	AddClickedPoint(e);
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

bool IsPoint2fZero(const Point2f& p) {
	return (p.x == 0.f && p.y == 0.f);
}

void DrawClickPolygon() {
	const float radius{ 5.f };

	for (int index{}; index < g_MaxMousePos; ++index) {
		if (IsPoint2fZero(g_MousePosArray[index]))
			continue;

		const int next{ index + 1 == g_MaxMousePos ? 0 : index + 1 };

		SetColor(1.f, 0.f, 0.f, 0.8f);
		FillEllipse(g_MousePosArray[index], radius, radius);

		SetColor(1.f, 1.f, 1.f);
		if (!IsPoint2fZero(g_MousePosArray[next]))
			DrawLine(g_MousePosArray[index], g_MousePosArray[next], 2.f);
	}
}

void AddClickedPoint(const SDL_MouseButtonEvent& e) {
	g_MousePosArray[g_MousePosIndex] = Point2f{ float(e.x), float(e.y) };
	g_MousePosIndex = (g_MousePosIndex + 1) % g_MaxMousePos;
}

#pragma endregion ownDefinitions