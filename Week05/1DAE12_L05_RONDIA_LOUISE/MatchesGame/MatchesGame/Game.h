#pragma once
#include <utils.h>
using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "Matches Game - Rondia, Louise - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 600 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation


#pragma region ownDeclarations
// Declare your own global variables here

int	g_MatchesRem{ 21 };
int	g_MyMatches{ 0 };
int	g_EnnemyMatches{ 0 };

std::string	g_MyMoves{ "" };
std::string	g_EnnemyMoves{ "" };

const float g_MatchLength{ 50.f };

bool g_IsMyTurn{ true };
bool g_AmWinner{ false };
bool g_IsOver{ false };


// Declare your own functions here

void DrawMatch(Point2f pos);
void DrawMatches();
void TakeMatches(int num, int& matches, std::string& moves);

void PrintResults();

#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
