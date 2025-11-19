#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	InitWolf();
}

void Draw()
{
	ClearBackground(g_White.r, g_White.g, g_White.b);


	DrawWolf();
}

void Update(float elapsedSec)
{
	UpdateWolfPos(elapsedSec);
	UpdateWolfFrame(elapsedSec);

	// Check keyboard state
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);
	if (pStates[SDL_SCANCODE_RIGHT] && g_Wolf.animState != AnimState::Jump) {
		g_Wolf.animState = AnimState::Walk;
		g_Wolf.dir.x = 1.f;
		UpdateWolfFrameStartIndex();
	}
	else if (pStates[SDL_SCANCODE_LEFT] && g_Wolf.animState != AnimState::Jump) {
		g_Wolf.animState = AnimState::Walk;
		g_Wolf.dir.x = -1.f;
		UpdateWolfFrameStartIndex();
	}
	else if (g_Wolf.animState != AnimState::Jump && ((!pStates[SDL_SCANCODE_RIGHT] && g_Wolf.dir.x == 1.f)
		|| (!pStates[SDL_SCANCODE_LEFT] && g_Wolf.dir.x == -1.f))) {
		g_Wolf.animState = AnimState::Idle;
		UpdateWolfFrameStartIndex();
	}

	if (pStates[SDL_SCANCODE_SPACE] && g_Wolf.moveState != MoveState::Jumping) {
		g_Wolf.moveState = MoveState::Jumping;
		g_Wolf.animState = AnimState::Jump;
		g_Wolf.vy = g_JumpPower;
		g_Wolf.pos.y -= 2.f;
		UpdateWolfFrameStartIndex();
	}
	else if (g_Wolf.moveState == MoveState::Jumping && g_Wolf.pos.y > g_Ground.top - g_Wolf.frame.height) {
		std::cout << "yoooooooooooooooooooooooooooooooooooooooo\n";
		g_Wolf.moveState = MoveState::Grounded;
		g_Wolf.animState = AnimState::Idle;
		g_Wolf.vy = 0.f;
		g_Wolf.pos.y = g_Ground.top - g_Wolf.frame.height;
		UpdateWolfFrameStartIndex();
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
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//const float mouseX{ float(e.x) };
	//const float mouseY{ float(e.y) };
	//std::cout << "  [" << mouseX << ", " << mouseY << "]\n";
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

void InitWolf() {
	if (!TextureFromFile("Resources/wolf.png", g_Wolf.texture.texture)) {
		std::cout << "Couldn't load wolf.png\n";
	}
	g_Wolf.frame.width = g_Wolf.texture.texture.width / g_Wolf.texture.nrCols;
	g_Wolf.frame.height = g_Wolf.texture.texture.height / g_Wolf.texture.nrRows;
	g_Wolf.frame.rect = GetFrameRectf(0);
	g_Wolf.pos = Point2f{ g_WindowWidth / 4, g_WindowHeight * .75f - g_Wolf.frame.height };
	g_Wolf.dir = Point2f{ 1.f, 0.f };
}

Rectf	GetFrameRectf(int index) {
	const int nrCols{ g_Wolf.texture.nrCols };
	const float width{ g_Wolf.frame.width }, height{ g_Wolf.frame.height };

	return Rectf(GetCol(index, nrCols) * width, GetRow(index, nrCols) * height, width, height);
}

int GetIndex(int rowIdx, int colIdx, int nrCols) {
	return rowIdx * nrCols + colIdx;
}

int GetRow(int index, int nrCols) {
	return index / nrCols;
}

int GetCol(int index, int nrCols) {
	return index % nrCols;
}

void DrawWolf() {
	DrawTexture(g_Wolf.texture.texture, g_Wolf.pos, g_Wolf.frame.rect);
}

void UpdateWolfPos(float elapsedSec) {
	g_Wolf.pos.x += elapsedSec * g_Wolf.vx;
	g_Wolf.pos.y += elapsedSec * g_Wolf.vy;

	switch (g_Wolf.moveState)
	{
	case MoveState::Falling:
	case MoveState::Jumping:
		g_Wolf.vy += elapsedSec * g_Gravity;
		break;
	default:
		break;
	}
	switch (g_Wolf.animState)
	{
	case AnimState::Idle:
		g_Wolf.vx = 0.f;
		break;
	case AnimState::Walk:
		g_Wolf.vx = g_WolfSpeed * g_Wolf.dir.x;
		break;
	default:
		break;
	}
}

void	UpdateWolfFrameStartIndex() {

	std::cout << (g_Wolf.animState == AnimState::Jump ? "jump" : "other") << std::endl;
	if (g_Wolf.animState == AnimState::Idle) {
		g_Wolf.frame.nrFrames = g_Wolf.frame.idleNrFrames;
		if (g_Wolf.dir.x == 1.f)
			g_Wolf.frame.startIndex = 0;
		else
			g_Wolf.frame.startIndex = g_Wolf.frame.idleNrFrames + g_Wolf.frame.walkNrFrames;
	}
	else if (g_Wolf.animState == AnimState::Walk) {
		g_Wolf.frame.nrFrames = g_Wolf.frame.walkNrFrames;
		if (g_Wolf.dir.x == 1.f)
			g_Wolf.frame.startIndex = g_Wolf.frame.idleNrFrames;
		else
			g_Wolf.frame.startIndex = 2 * g_Wolf.frame.idleNrFrames + g_Wolf.frame.walkNrFrames;
	}
	else if (g_Wolf.animState == AnimState::Jump) {
		g_Wolf.frame.nrFrames = g_Wolf.frame.jumpNrFrames;
		if (g_Wolf.dir.x == 1.f)
			g_Wolf.frame.startIndex = 2 * g_Wolf.frame.idleNrFrames + 2 * g_Wolf.frame.walkNrFrames;
		else
			g_Wolf.frame.startIndex = 2 * g_Wolf.frame.idleNrFrames + 2 * g_Wolf.frame.walkNrFrames + g_Wolf.frame.jumpNrFrames;
	}
}

void UpdateWolfFrame(float elapsedSec) {
	const float frameRate{ 1.f / 8.f };

	g_FrameTime += elapsedSec;
	if (g_FrameTime >= frameRate) {
		g_FrameTime = 0.f;
		g_Wolf.frame.index = (g_Wolf.frame.index + 1) % g_Wolf.frame.nrFrames;
		g_Wolf.frame.rect = GetFrameRectf(g_Wolf.frame.startIndex + g_Wolf.frame.index);
	}

}

#pragma endregion ownDefinitions