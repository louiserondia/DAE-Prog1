#pragma once
#include <utils.h>
using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };

// Change the window dimensions here
float g_WindowWidth{ 1000 };
float g_WindowHeight{ 700 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

struct Shape {
	int sides{};
	Color4f color{};
	Point2f pos{};
	float	startAngle{};
};

Texture g_DigitTexture[10]{};
const Color4f g_Black{ 0.f, 0.f, 0.f, 1.f };
const Color4f g_Yellow{ 1.f, 1.f, 0.f, .8f };

const int g_NumShapeOptions{ 5 };
int g_ShapeOptions[g_NumShapeOptions]{};
int g_CurShapeOption{};
int g_CurColorOptionIndex{};

const int g_NumColorOptions{ 8 };
Color4f g_ColorOptions[g_NumColorOptions]{};
Rectf g_ColorOptionRect[g_NumColorOptions]{};

std::vector<Shape> g_Shapes{};
float g_Time{};

// Declare your own functions here

void ShuffleKnuth(int* array, int size);
void DrawDigit(int index, const Point2f& center);
void DrawDigit(int index, float left, float top);
void DrawDigits();
void DrawColorOptions();
void DrawShape(const Shape& shape);
void DrawShapes();

bool IsInRect(const Point2f& mouse, const Rectf& rect);
int GetTargetFromClick(const Point2f& mouse);


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
