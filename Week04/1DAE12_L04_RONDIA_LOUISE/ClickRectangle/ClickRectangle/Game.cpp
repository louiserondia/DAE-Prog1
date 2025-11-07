#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	InitRect();
	InitLine();
}

void Draw()
{
	ClearBackground();
	DrawRectangle();
	DrawMyLine();
}

void Update(float elapsedSec)
{
	if (g_Rect.isMoving)
		UpdateRect();
	if (g_Line.on)
		UpdateLine();
}

void End()
{
}
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{
}

void OnKeyUpEvent(SDL_Keycode key)
{
	if (key == SDLK_r)
		g_Rect.isMoving = !g_Rect.isMoving;
	if (key == SDLK_l)
		g_Line.on = !g_Line.on;
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	ProcessMouseClick(Point2f{ float(e.x), float(e.y) });
}
#pragma endregion inputHandling

#pragma region ownDefinitions

void	InitRect() {
	g_Rect.rect = RandomRect();
	g_Rect.color = g_Grey;
	g_Rect.state = State::grey;
	g_Rect.isOut = false;
}

Rectf	RandomRect() {
	const Point2f pos{
		std::max(50.f, rand() / float(RAND_MAX) * (g_WindowWidth - 160.f)),
		std::max(50.f, rand() / float(RAND_MAX) * (g_WindowHeight - 140.f))
	};
	const float maxWidth{ g_WindowWidth - pos.x };
	const float maxHeight{ g_WindowHeight - pos.y };
	const float	width{ std::max(60.f, rand() / float(RAND_MAX) * maxWidth) };
	const float height{ std::max(40.f, rand() / float(RAND_MAX) * maxHeight) };

	return Rectf{ pos.x, pos.y, width, height };
}

void	DrawRectangle() {
	SetColor(g_Rect.color);
	FillRect(g_Rect.rect);
	if (g_Rect.isOut)
		FillRect(-(g_WindowWidth - g_Rect.rect.left), g_Rect.rect.top, g_Rect.rect.width, g_Rect.rect.height);
}

bool	isMouseInRect(Point2f mouse) {
	const float	outLeft{ -(g_WindowWidth - g_Rect.rect.left) };

	if (mouse.y >= g_Rect.rect.top && mouse.y <= g_Rect.rect.top + g_Rect.rect.height) {
		if ((mouse.x >= g_Rect.rect.left && mouse.x <= g_Rect.rect.left + g_Rect.rect.width)
			|| (mouse.x >= outLeft && mouse.x <= outLeft + g_Rect.rect.width))
			return true;
	}
	return false;
}

void	ProcessMouseClick(Point2f mouse) {
	if (isMouseInRect(mouse)) {
		switch (g_Rect.state) {
		case State::grey:
			g_Rect.state = State::green;
			g_Rect.color = g_Green;
			break;
		case State::green:
			InitRect();
			break;
		}
	}
}

void	UpdateRect() {
	++g_Rect.rect.left;
	if (g_Rect.rect.left > g_WindowWidth) {
		g_Rect.isOut = false;
		g_Rect.rect.left = 0.f;
	}
	else if (g_Rect.rect.left > g_WindowWidth - g_Rect.rect.width)
		g_Rect.isOut = true;
}


void	InitLine() {
	g_Line.a.point = RandomPoint2f();
	g_Line.a.speed = RandomSpeed();
	g_Line.a.dir = Point2f{ 1, 1 };
	g_Line.b.point = RandomPoint2f();
	g_Line.b.speed = RandomSpeed();
	g_Line.b.dir = Point2f{ 1, 1 };
	g_Line.on = false;
}

Point2f	RandomPoint2f() {
	const Point2f pos{
		rand() / float(RAND_MAX) * g_WindowWidth,
		rand() / float(RAND_MAX) * g_WindowHeight
	};
	return pos;
}

float	RandomSpeed() {
	return std::max(2.f, rand() / float(RAND_MAX) * 6.f);
}

bool	isPointOut(Point2f p) {
	return (p.x <= 0.f || p.x >= g_WindowWidth || p.y <= 0.f || p.y >= g_WindowWidth);
}

void	DrawMyLine() {
	SetColor(0.f, 0.f, 1.f);
	if (g_Line.on)
		DrawLine(g_Line.a.point, g_Line.b.point, 5.f);
}

void	UpdateLine() {
	UpdatePoint(g_Line.a);
	UpdatePoint(g_Line.b);
}

void	UpdatePoint(Point &p) {
	p.point.x += p.speed * p.dir.x;
	p.point.y += p.speed * p.dir.y;
	
	if (p.point.x <= 0)
		p.dir.x = 1;
	else if (p.point.x >= g_WindowWidth)
		p.dir.x = -1;
	else if(p.point.y <= 0)
		p.dir.y = 1;
	else if (p.point.y >= g_WindowHeight)
		p.dir.y = -1;
	
	if (isPointOut(p.point))
		p.speed = RandomSpeed();
}

#pragma endregion ownDefinitions