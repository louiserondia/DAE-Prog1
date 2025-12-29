// Rondia, Louise, 1DAE12

#include "pch.h"
#include "Game.h"
#include <iostream>
#include <string>


//Basic game functions
#pragma region gameFunctions	

void ShuffleKnuth(int* array, int size) {
	for (int i{ size - 1 }; i > 0; --i) {
		const int j{ rand() % i };

		std::swap(array[i], array[j]);
	}
}

bool IsInArray(int* array, int size, int needle) {
	for (int i{}; i < size; ++i) {
		if (array[i] == needle) return true;
	}
	return false;
}

Color4f RandColor() {
	return Color4f{
		float(rand() % 255) / 255.f,
		float(rand() % 255) / 255.f,
		float(rand() % 255) / 255.f,
		1.f };
}

void Start()
{
	const Texture digits{};
	const std::string fontPath{ "Resources/GristledFont-Regular.ttf" };
	for (int index{}; index < 10; ++index) {
		TextureFromString(std::to_string(index), fontPath, 32, g_Black, g_DigitTexture[index]);
	}
	const float gap{ 50.f };
	Rectf pos{ gap, 100.f, gap / 2, gap / 2 };

	int num{};
	for (int index{}; index < g_NumShapeOptions; ++index) {
		do {
			num = rand() % 7 + 3;
		} while (IsInArray(g_ShapeOptions, g_NumShapeOptions, num));
		g_ShapeOptions[index] = num;
	}
	for (int index{}; index < g_NumColorOptions; ++index) {
		g_ColorOptions[index] = RandColor();
		g_ColorOptionRect[index] = pos;
		pos.top += gap;
	}
	//ShuffleKnuth(g_ShapeOptions, g_NumShapeOptions);
}

void DrawDigit(int index, float left, float top) {
	DrawDigit(index, Point2f{ left, top });
}

void DrawDigit(int digit, const Point2f& center) {
	const Point2f topLeft{
		center.x - g_DigitTexture[digit].width / 2,
		center.y - g_DigitTexture[digit].height / 2
	};
	DrawTexture(g_DigitTexture[digit], topLeft);
}

void DrawDigits() {
	const float gap{ 50.f };
	Point2f pos{ gap, gap };

	for (int index{}; index < g_NumShapeOptions; ++index) {
		const int digit{ g_ShapeOptions[index] };
		const float radius{ g_DigitTexture[digit].height * 0.5f };
		
		if (digit == g_CurShapeOption) {
			SetColor(g_Yellow);
			FillEllipse(pos, radius, radius);
		}

		DrawDigit(digit, pos);
		SetColor(g_Black);
		DrawEllipse(pos, radius, radius, 4.f);
		pos.x += gap;
	}
}

void DrawColorOptions() {
	for (int index{}; index < g_NumColorOptions; ++index) {
		SetColor(g_ColorOptions[index]);
		FillRect(g_ColorOptionRect[index]);
		SetColor(g_Black);
		DrawRect(g_ColorOptionRect[index], 5.f);
	}
	Rectf cur{ g_ColorOptionRect[g_CurColorOptionIndex] };

	cur.top += cur.width / 2;
	cur.left -= cur.width / 2;
	cur.height /= 5;
	cur.width /= 5;
	SetColor(g_Black);
	FillRect(cur);
}

int GetTotalIdenticalPoly(int sides) {
	int count{};
	for (const Shape& shape : g_Shapes) {
		if (shape.sides == sides)
			count++;
	}
	return count;
}

void DrawShape(const Shape& shape) {
	const float angle{ 2 * g_Pi / shape.sides };
	const float radius{ 25.f };

	for (int index{}; index < shape.sides; ++index) {
		float angle1{ shape.startAngle + index * angle };
		float angle2{ shape.startAngle + (index + 1) * angle };

		Point2f p1{
			shape.pos.x + cosf(angle1) * radius,
			shape.pos.y + sinf(angle1) * radius
		};

		Point2f p2{
			shape.pos.x + cosf(angle2) * radius,
			shape.pos.y + sinf(angle2) * radius
		};

		SetColor(shape.color);
		DrawLine(p1, p2, 5.f);
	}
	SetColor(g_Black);

	const int count{ GetTotalIdenticalPoly(shape.sides) };
	DrawDigit(count, shape.pos);
}

void DrawShapes() {
	for (const Shape& shape : g_Shapes) {
		std::cout << shape.pos.x << std::endl;
		DrawShape(shape);
	}
}

void Draw()
{
	ClearBackground();
	DrawDigits();
	DrawColorOptions();
	DrawShapes();
}

void Update(float elapsedSec)
{

	g_Time += elapsedSec;

	for (Shape& shape : g_Shapes) {
		shape.startAngle += elapsedSec;
	}
}

void End()
{
	for (int index{}; index < 10; ++index) {
		DeleteTexture(g_DigitTexture[index]);
	}
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{
}

void OnKeyUpEvent(SDL_Keycode key)
{
	if (key >= SDLK_3 && key <= SDLK_9 && IsInArray(g_ShapeOptions, g_NumShapeOptions, key - SDLK_0)) {
		g_CurShapeOption = key - SDLK_0;
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
}

bool IsInRect(const Point2f& mouse, const Rectf& rect) {
	return mouse.x >= rect.left && mouse.y >= rect.top
		&& mouse.x <= rect.left + rect.width && mouse.y <= rect.top + rect.height;
}

int GetTargetFromClick(const Point2f& mouse) {
	for (int index{}; index < g_NumColorOptions; ++index) {
		if (IsInRect(mouse, g_ColorOptionRect[index]))
			return index;
	}
	return -1; // no rect was clicked
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	const Point2f mouse{ float(e.x), float(e.y) };
	const float bound{ 130.f };
	const bool isRightClick{ e.button == SDL_BUTTON_RIGHT };
	const bool isLeftClick{ e.button == SDL_BUTTON_LEFT };
	const int target{ GetTargetFromClick(mouse) };

	if (target != -1) {
		if (isRightClick) {
			g_ColorOptions[target] = RandColor();
		}
		else if (isLeftClick) {
			g_CurColorOptionIndex = target;
		}
	}
	else if (isLeftClick && g_CurShapeOption
		&& mouse.x > bound && mouse.y > bound 
		&& mouse.x < g_WindowWidth- bound && mouse.y < g_WindowHeight - bound) {
		const Shape shape{
			g_CurShapeOption,
			g_ColorOptions[g_CurColorOptionIndex],
			mouse,
			g_Time
		};
		g_Shapes.push_back(shape);
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

#pragma endregion ownDefinitions