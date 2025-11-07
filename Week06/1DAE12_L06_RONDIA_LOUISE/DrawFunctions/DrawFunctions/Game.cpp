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
	DrawAllSquares();
	DrawAllTriangles();
	DrawAllPentagrams();
	DrawAllGradients();
	DrawAllDotGrids();
}

void Update(float elapsedSec)
{
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

void DrawSquares(Point2f topLeft, float size, int nSquares) {
	float offset{ size / (nSquares * 2) };

	SetColor(0.f, 0.f, 0.f);
	for (int i{}; i < nSquares; ++i) {
		DrawRect(
			topLeft.x + i * offset,
			topLeft.y + i * offset,
			size - i * offset * 2,
			size - i * offset * 2);
	}
}

void DrawAllSquares() {
	const float size{ 100.f };
	const int	nSquares{ 9 };

	DrawSquares(Point2f{ 20.f, 20.f }, size, 9);
	DrawSquares(Point2f{ 20.f * 2 + size, 20.f + size * .25f }, size * .75f, 5);
	DrawSquares(Point2f{ 20.f * 3 + size * 1.75f, 20.f + size / 2 }, size / 2, 3);
}

void DrawEquilateralTriangles(float bottomLeftX, float bottomLeftY, float size, bool isFilled, Color4f color) {
	DrawEquilateralTriangles(Point2f{ bottomLeftX, bottomLeftY }, size, isFilled, color);
}


void DrawEquilateralTriangles(Point2f bottomLeft, float size, bool isFilled, Color4f color) {
	Point2f top{ bottomLeft.x + (cosf(g_Pi / 3) * size), bottomLeft.y - (sinf(g_Pi / 3) * size) };
	Point2f right{ bottomLeft.x + (cosf(0) * size), bottomLeft.y - (sinf(0) * size) };

	SetColor(color);
	if (isFilled)
		FillTriangle(bottomLeft, top, right);
	else
		DrawTriangle(bottomLeft, top, right);

}

void DrawAllTriangles() {
	float size = 75.f;
	Point2f trianglePos{ g_WindowWidth / 2 + 50.f, 100.f };

	DrawEquilateralTriangles(trianglePos, size, true, Color4f{ 1.f, 0.f, 0.f, 1.f });
	DrawEquilateralTriangles(trianglePos.x + 10.f, trianglePos.y - 5.f, size - 20.f, true, Color4f{ 0.f, 1.f, 0.f, 1.f });
	DrawEquilateralTriangles(trianglePos.x + 20.f, trianglePos.y - 10.f, size - 40.f, true, Color4f{ 0.f, 0.f, 1.f,  1.f });

	trianglePos.x += 100.f;
	size /= 2;

	DrawEquilateralTriangles(trianglePos, size, true, Color4f{ 0.f, 1.f, 1.f, 1.f });
	DrawEquilateralTriangles(trianglePos.x + size, trianglePos.y, size, true, Color4f{ 1.f, 1.f, 0.f, 1.f });
	DrawEquilateralTriangles(trianglePos.x + cosf(g_Pi / 3) * size, trianglePos.y - sinf(g_Pi / 3) * size, size, true, Color4f{ 1.f, 0.f, 1.f, 1.f });

	DrawEquilateralTriangles(trianglePos, size, false, Color4f{ 0.f, 0.f, 0.f, 1.f });
	DrawEquilateralTriangles(trianglePos.x + size, trianglePos.y, size, false, Color4f{ 0.f, 0.f, 0.f, 1.f });
	DrawEquilateralTriangles(trianglePos.x + cosf(g_Pi / 3) * size, trianglePos.y - sinf(g_Pi / 3) * size, size, false, Color4f{ 0.f, 0.f, 0.f, 1.f });
}

void DrawPentagram(Point2f start, float size, Color4f color) {
	SetColor(color);

	const float stepAngle{ g_Pi * 2 / 5 };
	const float startAngle{ stepAngle };

	for (int index{}; index < 5; ++index) {
		const int nextIndex{ (index + 2) % 5 };
		Point2f p1{ start.x + cosf(startAngle + stepAngle * index) * size, start.y + sinf(startAngle + stepAngle * index) * size };
		Point2f p2{ start.x + cosf(startAngle + stepAngle * nextIndex) * size, start.y + sinf(startAngle + stepAngle * nextIndex) * size };
		DrawLine(p1, p2);
	}
}

void DrawAllPentagrams() {
	Point2f center{ g_WindowWidth / 2 + 100.f, 180.f };
	float size = 50.f;

	DrawPentagram(center, size, Color4f{ 1.f, 0.f, 0.f, 1.f });
	center.x += 100.f;
	size = 30.f;
	DrawPentagram(center, size, Color4f{ 0.f, 0.f, 1.f, 1.f });
}

void DrawLineGradient(Rectf rect, Color4f startColor, Color4f endColor) {
	const float
		stepR{ (endColor.r - startColor.r) / rect.width },
		stepG{ (endColor.g - startColor.g) / rect.width },
		stepB{ (endColor.b - startColor.b) / rect.width },
		stepA{ (endColor.a - startColor.a) / rect.width };

	for (float x{}; x < rect.width; ++x) {
		SetColor(startColor.r + stepR * x, startColor.g + stepG * x, startColor.b + stepB * x, startColor.a + stepA * x);

		DrawLine(rect.left + x, rect.top, rect.left + x, rect.top - rect.height);

	}
}

void DrawAllGradients() {
	const float length{ g_WindowWidth - 100.f };
	Rectf rect{ 20.f, 200.f, length / 4, 30.f };

	DrawLineGradient(rect, Color4f{ 0.f, 0.f, 0.f, 1.f }, Color4f{ 1.f, 1.f, 1.f, 1.f });
	rect.top += 40.f;
	rect.width = length / 2;
	DrawLineGradient(rect, Color4f{ 1.f, 0.f, 0.f, 1.f }, Color4f{ 1.f, 0.f, 1.f, 1.f });
	rect.top += 50.f;
	rect.height = 40.f;
	rect.width = length / 4 * 3;
	DrawLineGradient(rect, Color4f{ 0.533f, 0.58f, 0.392f, 1.f }, Color4f{ 0.9f, 0.5f, 0.5f, 1.f });
	rect.top += 60.f;
	rect.width = length;
	rect.height = 50.f;
	DrawLineGradient(rect, Color4f{ 0.f, 0.f, 1.f, 1.f }, Color4f{ 0.9f, 0.5f, 0.5f, 1.f });
}

void DrawDotGrid(float left, float top, float dotRadius, int rows, int columns, float gap, Color4f color) {
	DrawDotGrid(Point2f{ left, top }, dotRadius, rows, columns, gap, color);
}

void DrawDotGrid(Point2f topLeft, float dotRadius, int rows, int columns, float gap, Color4f color) {
	const float offset{ dotRadius * 2 + gap };

	topLeft.x += dotRadius / 2;
	topLeft.y += dotRadius / 2;

	SetColor(color);
	for (int index{}; index < rows * columns; ++index) {
		FillEllipse(topLeft.x + offset * (index / rows), topLeft.y + offset * (index % rows), dotRadius, dotRadius);
	}
}

void DrawAllDotGrids() {
	DrawDotGrid(20.f, g_WindowHeight * .75f, 20.f, 3, 5, 3.f, Color4f{ 1.f, 0.f, 0.f, 1.f });
	DrawDotGrid(g_WindowWidth / 2, g_WindowHeight * .75f, 20.f, 2, 7, 2.f, Color4f{ 0.f, 1.f, 0.f, 1.f });
	DrawDotGrid(g_WindowWidth / 2 + 5.f, g_WindowHeight * .75f + 5.f, 11.f, 2, 7, 20.f, Color4f{ 0.f, 0.f, 1.f, 1.f });
}

#pragma endregion ownDefinitions