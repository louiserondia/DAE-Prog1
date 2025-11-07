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
	ClearBackground(0.f, 0.f, 0.2f);
	DrawFirstDiceStats();
	DrawSumOfDiceStats();
}

void Update(float elapsedSec)
{
	RollDice();
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
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

void RollDice() {
	const int firstResult{ rand() % 6 };
	const int secondResult{ rand() % 6 };

	g_FirstDice[firstResult]++;
	g_SumOfDice[firstResult + secondResult]++;
}

void DrawSumOfDiceStats() {
	Point2f	start{ 2 * g_Offset, 2 * g_Offset };

	SetColor(.8f, 0.5f, 1.f);
	for (int i = 0; i < 11; i++) {
		FillRect(start.x, start.y, g_SumOfDice[i], g_RowHeight);
		start.y += g_Offset + g_RowHeight;
	}
}

void DrawFirstDiceStats() {
	Point2f	start{ 2 * g_Offset, 14 * g_Offset + 11 * g_RowHeight };

	SetColor(1.f, 0.4f, 0.4f);
	for (int i = 0; i < 6; i++) {
		FillRect(start.x, start.y, g_FirstDice[i], g_RowHeight);
		start.y += g_Offset + g_RowHeight;
	}
}

#pragma endregion ownDefinitions