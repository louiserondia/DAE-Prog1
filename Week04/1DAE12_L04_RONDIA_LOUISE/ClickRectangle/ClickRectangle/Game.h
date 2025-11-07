#pragma once
#include <utils.h>
using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "Click Rectangle - Rondia, Louise - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 600 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

struct Point
{
	Point2f	point{};
	float	speed{};
	Point2f	dir{};
};

struct Line
{
	Point	a{};
	Point	b{};
	bool	on{};
};

Line	g_Line{};

enum class State
{
	grey,
	green
};

struct MyRect
{
	Rectf	rect{};
	Color4f	color{};
	State	state{};
	bool	isOut{};
	bool	isMoving{ true };
};

MyRect g_Rect{};

const Color4f	g_Grey{ .5f, .5f, .5f, 1.f };
const Color4f	g_Green{ 0.f, 1.f, 0.f, 1.f };

// Declare your own functions here

bool	isMouseInRect(Point2f mouse);
bool	isPointOut(Point2f p);
Rectf	RandomRect();
Point2f	RandomPoint2f();
float	RandomSpeed();


void	InitRect();
void	DrawRectangle();
void	ProcessMouseClick(Point2f mouse);
void	UpdateRect();

void	InitLine();
void	DrawMyLine();
void	UpdateLine();
void	UpdatePoint(Point &p);

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
