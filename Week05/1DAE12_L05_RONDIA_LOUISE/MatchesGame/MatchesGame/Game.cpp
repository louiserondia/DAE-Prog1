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
	ClearBackground(0.f, 0.f, 0.f);
	DrawMatches();
}

void Update(float elapsedSec)
{
	if (g_MatchesRem <= 0 && !g_IsOver) {
		PrintResults();
		g_IsOver = true;
	}

	if (!g_IsMyTurn && !g_IsOver) {
		Sleep(1);
		TakeMatches(rand() % 3 + 1, g_EnnemyMatches, g_EnnemyMoves);
		if (g_MatchesRem <= 0)
			g_AmWinner = true;
	}
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
	if (g_IsMyTurn && !g_IsOver) {
		int num{};

		switch (key)
		{
		case SDLK_1:
			num = 1;
			break;
		case SDLK_2:
			num = 2;
			break;
		case SDLK_3:
			num = 3;
			break;
		default:
			break;
		}
		TakeMatches(num, g_MyMatches, g_MyMoves);
	}

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

void DrawMatch(Point2f pos) {
	SetColor(1.f, 1.f, 0.f);
	DrawLine(pos, Point2f{ pos.x, pos.y + 10.f }, 3.f);
	SetColor(1.f, 0.f, 0.f);
	DrawLine(pos.x, pos.y + 10.f, pos.x, pos.y + g_MatchLength, 3.f);
}

void DrawMatches() {
	const float gap{ 15.f };
	Point2f matchesRemPos{ gap * 2, gap * 2 };
	Point2f myMatchesPos{ gap * 2, g_WindowHeight - gap * 2 - g_MatchLength };
	Point2f ennemyMatchesPos{ g_WindowWidth / 2 + gap * 2, g_WindowHeight - gap * 2 - g_MatchLength };

	for (int i{}; i < g_MatchesRem; ++i) {
		DrawMatch(matchesRemPos);
		matchesRemPos.x += gap;
	}
	for (int i{}; i < g_MyMatches; ++i) {
		DrawMatch(myMatchesPos);
		myMatchesPos.x += gap;
	}
	for (int i{}; i < g_EnnemyMatches; ++i) {
		DrawMatch(ennemyMatchesPos);
		ennemyMatchesPos.x += gap;
	}
}

void TakeMatches(int num, int& matches, std::string& moves) {
	matches += num;
	g_MatchesRem -= num;
	moves += std::to_string(num) + " ";
	g_IsMyTurn = !g_IsMyTurn;
}

void PrintResults() {
	std::cout << "PC Moves: " << g_EnnemyMoves << std::endl;
	std::cout << "Your Moves: " << g_MyMoves << std::endl;
	std::cout << (g_AmWinner ? "You win !" : "Computer wins !") << std::endl;
}

#pragma endregion ownDefinitions