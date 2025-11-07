#pragma once
#include <utils.h>
using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "Draw Functions - Rondia, Louise - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 600 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

// Declare your own functions here

void DrawAllSquares();
void DrawAllTriangles();
void DrawAllPentagrams();
void DrawAllGradients();
void DrawAllDotGrids();

void DrawSquares(Point2f topLeft, float size, int nSquares);
void DrawEquilateralTriangles(Point2f bottomLeft, float size, bool isFilled, Color4f color);
void DrawEquilateralTriangles(float bottomLeftX, float bottomLeftY, float size, bool isFilled, Color4f color);
void DrawPentagram(Point2f center, float size, Color4f color);
void DrawLineGradient(Rectf rect, Color4f startColor, Color4f endColor);
void DrawDotGrid(Point2f topLeft, float dotRadius, int rows, int columns, float gap, Color4f color);
void DrawDotGrid(float left, float top, float dotRadius, int rows, int columns, float gap, Color4f color);


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
