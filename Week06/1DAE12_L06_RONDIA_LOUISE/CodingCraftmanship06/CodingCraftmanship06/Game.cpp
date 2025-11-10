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
	ClearBackground(0.8f, 0.8f, 0.8f);

	DrawBackGround();
	DrawPortals();
	DrawBall();
}

void Update(float elapsedSec)
{
	UpdateBallPosition(elapsedSec);
	if (!isBallColliding()) {
		g_IsBallFalling = true;
	}
	else {
		ApplyBallBounce();
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
	switch (key)
	{
	case SDLK_q:
	case SDLK_LEFT:
		g_BallVelocity.x = -g_MovesVelocity.x;
		g_MvtKeyPressed = true;
		break;
	case SDLK_d:
	case SDLK_RIGHT:
		g_MvtKeyPressed = true;
		g_BallVelocity.x = g_MovesVelocity.x;
		break;
	case SDLK_SPACE:
		g_MvtKeyPressed = true;
		if (g_BallCenter.y + g_BallRadius.y + g_BallJumpOffset > g_Ground.top)
			g_BallVelocity.y = g_MovesVelocity.y;
		break;
	default:
		break;
	}
}

void OnKeyUpEvent(SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_q:
	case SDLK_LEFT:
	case SDLK_d:
	case SDLK_RIGHT:
		g_MvtKeyPressed = false;
		break;
	default:
		break;
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
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		UpdatePortalPosition(g_BluePortal, float(e.x), float(e.y));
		break;
	case SDL_BUTTON_RIGHT:
		UpdatePortalPosition(g_OrangePortal, float(e.x), float(e.y));
		break;
	default:
		break;
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

float GetLineWidthInEllipse(float y) {
	const float height = g_PortalHeight - 8.f;
	const float width = g_PortalWidth - 8.f;
	return (width * (sqrt(1 - ((y * y) / (height * height)))));
}

float GetLineHeightInEllipse(float x) {
	const float height = g_PortalHeight - 8.f;
	const float width = g_PortalWidth - 8.f;
	return (height * (sqrt(1 - ((x * x) / (width * width)))));
}


void DrawPortal(const Portal& src, const Portal& dst) {
	SetColor(src.color);
	FillEllipse(src.center, src.width, src.height);

	SetColor(g_Grey);
	FillEllipse(src.center, src.width - 8.f, src.height - 8.f);

	if (!dst.isOn)
		return;
	DrawPortalView(src, dst);
}


void DrawPortals() {
	if (g_BluePortal.isOn)
		DrawPortal(g_BluePortal, g_OrangePortal);
	if (g_OrangePortal.isOn)
		DrawPortal(g_OrangePortal, g_BluePortal);	
}

void UpdatePortalPosition(Portal& portal, float newCenterX, float newCenterY) {
	Point2f newCenter{ newCenterX, newCenterY };
	UpdatePortalPosition(portal, newCenter);
}

void UpdatePortalPosition(Portal& portal, Point2f& newCenter) {
	if (newCenter.y > g_Ground.top)
		return;
	else if (newCenter.y > g_Ground.top - 30.f)
		newCenter.y = g_Ground.top - 30.f;

	portal.isOn = true;
	portal.center = newCenter;
}


void DrawBall() {
	SetColor(g_BallColor);
	FillEllipse(g_BallCenter, g_BallRadius.x, g_BallRadius.y);
}

bool IsBallInPortal(const Portal& portal) {
	const float offset{ 5.f };
	bool isIn{ false };

	// check overlap
	if (g_BallCenter.x <= portal.center.x + offset
		&& g_BallCenter.x >= portal.center.x - offset
		&& g_BallCenter.y <= portal.center.y + portal.height
		&& g_BallCenter.y >= portal.center.y - portal.height)
	{

		//check direction
		const float gap{ g_BallCenter.x - portal.center.x };
		if (gap < 0 && g_BallVelocity.x > 0.f) // on the left, going right 
			isIn = true;
		else if (gap > 0 && g_BallVelocity.x < 0.f) // on the right, going left
			isIn = true;
	}
	return isIn;
}

void UpdateBallPosition(float elapsedSec) {

	g_BallCenter.x += g_BallVelocity.x * elapsedSec;
	g_BallCenter.y += g_BallVelocity.y * elapsedSec;

	if (!g_MvtKeyPressed)
		g_BallVelocity.x *= HOR_FRICTION;

	if (g_BallCenter.x - g_BallRadius.x <= 0.f || g_BallCenter.x + g_BallRadius.x >= g_WindowWidth)
		g_BallVelocity.x *= -1.f;

	BallFalling(elapsedSec);

	BallTeleportation(g_BluePortal, g_OrangePortal);
	BallTeleportation(g_OrangePortal, g_BluePortal);
}

void BallFalling(float elapsedSec) {
	if (!g_IsBallFalling)
		return;
	g_BallVelocity.y += g_Gravity * elapsedSec;
}

bool BallTeleportation(const Portal& src, const Portal& dst) {

	if (!src.isOn || !dst.isOn || !IsBallInPortal(src))
		return false;

	g_BallCenter = dst.center;
	return true;
}

bool isBallColliding() {
	bool isColliding{ false };
	const float epsilon{ 1.f };

	if (g_BallCenter.y + g_BallRadius.y + epsilon > g_Ground.top)
		isColliding = true;
	return isColliding;
}

void ApplyBallBounce() {
	g_BallCenter.y = g_Ground.top - g_BallRadius.y;
	g_IsBallFalling = false;
	g_BallVelocity.y *= g_BallBounceCoef;

	if (g_IsBallFalling && g_BallVelocity.y < MIN_BOUNCE_SPEED && g_BallVelocity.y > -MIN_BOUNCE_SPEED) {
		g_BallVelocity.y = 0.f;
		g_IsBallFalling = false;
	}
}

void DrawBackGround() {
	const float nRow{ 5.f };
	const float nCol{ 10.f };
	const float offsetX{ 100.f }, offsetY{ 30.f };
	const float gap{ g_WindowWidth / nCol },
		pGap{ (g_WindowWidth - offsetX * 2) / nCol };

	SetColor(g_DarkGrey);
	for (int i{ -1 }; i < nCol + 2; i++) {
		DrawLine(offsetX + i * pGap, g_Ground.top - offsetY, offsetX + i * pGap, 0.f);	// vertical top lines
		DrawLine(i * gap, g_Ground.top + offsetY, offsetX + i * pGap, g_Ground.top - offsetY); // diagonals
		DrawLine(i * gap, g_Ground.top + offsetY, i * gap, g_WindowHeight); // vertical bottom lines
	}
	for (int i{}; i < nRow; i++) {
		const float up = (g_Ground.top - offsetY) - i * g_WindowHeight / 5;
		const float down = (g_Ground.top + offsetY) + i * g_WindowHeight / 5;
		DrawLine(0.f, up, g_WindowWidth, up);
		DrawLine(0.f, down, g_WindowWidth, down);
	}
}

void DrawPortalView(const Portal& viewer, const Portal& target) {
	const float nRow{ 5.f };
	const float nCol{ 10.f };
	const float offsetX{ 100.f }, offsetY{ 30.f };
	const float gap{ g_WindowWidth / nCol },
		pGap{ (g_WindowWidth - offsetX * 2) / nCol };

	Point2f start{ viewer.center.x - target.center.x, viewer.center.y - target.center.y };

	SetColor(g_DarkGrey);
	for (int i{ -1 }; i < nCol + 2; i++) {

		DrawLineInEllipse(start.x + offsetX + i * pGap, start.y + g_Ground.top - offsetY, start.x + offsetX + i * pGap, start.y + 0.f, viewer);	// vertical top lines
		DrawLineInEllipse(start.x + i * gap, start.y + g_Ground.top + offsetY, start.x + offsetX + i * pGap, start.y + g_Ground.top - offsetY, viewer); // diagonals
		DrawLineInEllipse(start.x + i * gap, start.y + g_Ground.top + offsetY, start.x + i * gap, start.y + g_WindowHeight, viewer); // vertical bottom lines
	}
	for (int i{}; i < nRow; i++) {
		const float up = (g_Ground.top - offsetY) - i * g_WindowHeight / 5;
		const float down = (g_Ground.top + offsetY) + i * g_WindowHeight / 5;
		DrawLineInEllipse(start.x + 0.f, start.y + up, start.x + g_WindowWidth, start.y + up, viewer);
		DrawLineInEllipse(start.x + 0.f, start.y + down, start.x + g_WindowWidth, start.y + down, viewer);
	}
}
bool IsInEllipse(const Point2f& pos, const Portal& portal) {
	return IsInEllipse(pos.x, pos.y, portal);
}

bool IsInEllipse(float x, float y, const Portal& portal) {
	const float width{ g_PortalWidth - 8.f }, height{ g_PortalHeight - 8.f };
	const float dx{ (x - portal.center.x) / width }, dy{ (y - portal.center.y) / height };
	bool isIn{ false };

	if ((dx * dx) + (dy * dy) <= 1.f)
		isIn = true;

	return isIn;
}

void DrawLineInEllipse(float x1, float y1, float x2, float y2, const Portal& portal) {

	const float dx{ x2 - x1 }, dy{ y2 - y1 };
	const float steps{ std::max(fabsf(dx), fabsf(dy)) };
	if (!steps)
		return;

	float x{ x1 }, y{ y1 };

	for (float i{}; i < steps; ++i) {
		if (IsInEllipse(x, y, portal))
			DrawPixel(x, y);

		x += dx / steps;
		y += dy / steps;
	}

}

// utils

void DrawPixel(const Point2f& pos, float size) {
	DrawPixel(pos.x, pos.y, size);
}

void DrawPixel(float x, float y, float size)
{
	glPointSize(size);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}

#pragma endregion ownDefinitions