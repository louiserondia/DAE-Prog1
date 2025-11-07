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
	ClearBackground();

	DrawPortals();
	DrawBall();
	DrawGround();
}

void Update(float elapsedSec)
{
	UpdateBallPosition(elapsedSec);
	if (!isBallColliding()) {
		g_IsBallFalling = true;
	}
	else {
		g_BallCenter.y = g_Ground.top - g_BallRadius.y;
		g_IsBallFalling = false;
		g_BallVelocity.y *= g_BallBounceCoef;
	
		std::cout << g_BallVelocity.y << std::endl;
		/*	if (g_BallVelocity.y < 0.3f)
			g_BallVelocity.y = 0.f;
		else if (g_BallVelocity.y > -0.3f)
			g_BallVelocity.y = 0.f;*/
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
		break;
	case SDLK_d:
	case SDLK_RIGHT:
		g_BallVelocity.x = g_MovesVelocity.x;
		break;
	case SDLK_SPACE:
		if (!g_IsBallFalling)
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
		g_BallVelocity.x = 0.f;
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

void DrawPortal(float width, float height, Point2f center, Color4f color) {
	SetColor(color);

	FillEllipse(center, width, height);
}

void DrawPortal(Portal portal) {
	DrawPortal(portal.width, portal.height, portal.center, portal.color);
}

void DrawPortals() {
	if (g_BluePortal.isOn)
		DrawPortal(g_BluePortal);
	if (g_OrangePortal.isOn)
		DrawPortal(g_OrangePortal);
}


void UpdatePortalPosition(Portal& portal, float newCenterX, float newCenterY) {
	UpdatePortalPosition(portal, Point2f{ newCenterX, newCenterY });
}

void UpdatePortalPosition(Portal& portal, Point2f newCenter) {
	portal.isOn = true;
	portal.center = newCenter;
}


void DrawBall() {
	SetColor(g_BallColor);
	FillEllipse(g_BallCenter, g_BallRadius.x, g_BallRadius.y);
}

bool IsBallInPortal(Portal portal) {
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
		if (gap < 0 && g_BallVelocity.x > 0.f) // on the left and going right 
			isIn = true;
		else if (gap > 0 && g_BallVelocity.x < 0.f) // on the right and going left
			isIn = true;
	}
	return isIn;
}

void UpdateBallPosition(float elapsedSec) {

	g_BallCenter.x += g_BallVelocity.x * elapsedSec;
	g_BallCenter.y += g_BallVelocity.y * elapsedSec;

	BallFalling(elapsedSec);

	BallTeleportation(g_BluePortal, g_OrangePortal);
	BallTeleportation(g_OrangePortal, g_BluePortal);
}

void BallFalling(float elapsedSec) {
	if (!g_IsBallFalling)
		return;
	g_BallVelocity.y += g_Gravity * elapsedSec;
}

bool BallTeleportation(Portal src, Portal dst) {

	if (!src.isOn || !dst.isOn || !IsBallInPortal(src))
		return false;

	g_BallCenter = dst.center;
	return true;
}

void DrawGround() {
	SetColor(g_GroundColor);

	FillRect(g_Ground);
}

bool isBallColliding() {
	bool isColliding{ false };

	if (g_BallCenter.y + g_BallRadius.y > g_Ground.top)
		isColliding = true;
	return isColliding;
}



#pragma endregion ownDefinitions