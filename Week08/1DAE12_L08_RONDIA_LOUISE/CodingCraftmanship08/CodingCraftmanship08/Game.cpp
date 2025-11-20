#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	InitAnimationFrames();
	InitFox();
}

void Draw()
{
	ClearBackground(g_White.r, g_White.g, g_White.b);
	DrawFox();
}

void Update(float elapsedSec)
{
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);

	UpdateFoxAnimState(pStates);
	UpdateFoxJumpState(pStates);
	UpdateFoxDirection(pStates);
	UpdateFoxPos(elapsedSec);
	UpdateFoxFrame(elapsedSec);

	// should be when a key is pressed or released, whenever there's any event
	// so for now it's just updated all the time, is that ok ?

	//if (IsAnyMovementKeyPressed(pStates)) 
	UpdateFoxFrameStartIndex();

	g_SleepTime += elapsedSec;
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

void InitFox() {
	if (!TextureFromFile("Resources/Fox Sprite Sheet.png", g_Fox.texture.texture)) {
		std::cout << "Couldn't load fox.png\n";
	}
	g_Fox.texture.frameWidth = g_Fox.texture.texture.width / g_Fox.texture.nrCols;
	g_Fox.texture.frameHeight = g_Fox.texture.texture.height / g_Fox.texture.nrRows;
	g_Fox.frame.rect = GetFrameRectf(0);
	g_Fox.frame.nrFrames = g_AnimFrames["idleRight"].nrFrames;
	g_Fox.frame.startIndex = GetIndex(g_AnimFrames["idleRight"].row, g_AnimFrames["idleRight"].col, g_Fox.texture.nrCols);
	g_Fox.pos = Point2f{ g_WindowWidth / 4, g_WindowHeight * .75f - g_Fox.texture.frameHeight };
	g_Fox.dir = Point2f{ 1.f, 0.f };
}

void InitAnimationFrames() {
	g_AnimFrames["idleRight"] = AnimationFrame{ 0, 0, 5 };
	g_AnimFrames["idleLeft"] = AnimationFrame{ 0, 5, 5 };
	g_AnimFrames["walkRight"] = AnimationFrame{ 2, 0, 8 };
	g_AnimFrames["walkLeft"] = AnimationFrame{ 2, 8, 8 };
	g_AnimFrames["jumpRight"] = AnimationFrame{ 3, 0, 11 };
	g_AnimFrames["jumpLeft"] = AnimationFrame{ 3, 11, 11 };
	g_AnimFrames["sleep"] = AnimationFrame{ 5, 0, 6 };
}

Rectf	GetFrameRectf(int index) {
	const int nrCols{ g_Fox.texture.nrCols };
	const float width{ g_Fox.texture.frameWidth }, height{ g_Fox.texture.frameHeight };

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

void DrawFox() {
	const Rectf rect{ g_Fox.pos.x, g_Fox.pos.y, 100.f, 100.f };
	DrawTexture(g_Fox.texture.texture, rect, g_Fox.frame.rect);
}

void UpdateFoxPos(float elapsedSec) {
	g_Fox.pos.x += elapsedSec * g_Fox.vx;
	g_Fox.pos.y += elapsedSec * g_Fox.vy;

	if (g_Fox.isJumping) {
		g_Fox.vy += elapsedSec * g_Gravity;
	}
	if (g_Fox.animState == AnimState::Idle) {
		g_Fox.vx = 0.f;
	}
}

bool IsAnyMovementKeyPressed(const Uint8* pStates) {
	return (pStates[SDL_SCANCODE_RIGHT] || pStates[SDL_SCANCODE_LEFT] || pStates[SDL_SCANCODE_SPACE]);
}

void	UpdateFoxFrameStartIndex() {
	std::string key{};

	switch (g_Fox.animState)
	{
	case AnimState::Sleep:
		key = "sleep";
		break;
	case AnimState::Jump:
		key = g_Fox.dir.x == 1.f ? "jumpRight" : "jumpLeft";
		break;
	case AnimState::Walk:
		key = g_Fox.dir.x == 1.f ? "walkRight" : "walkLeft";
		break;
	case AnimState::Idle:
	default:
		key = g_Fox.dir.x == 1.f ? "idleRight" : "idleLeft";
		break;
	}

	g_Fox.frame.nrFrames = g_AnimFrames[key].nrFrames;
	g_Fox.frame.startIndex = GetIndex(g_AnimFrames[key].row, g_AnimFrames[key].col, g_Fox.texture.nrCols);
}

void UpdateFoxFrame(float elapsedSec) {
	const float frameRate{ 1.f / 8.f };

	g_FrameTime += elapsedSec;
	if (g_FrameTime >= frameRate) {
		g_FrameTime = 0.f;
		g_Fox.frame.index = (g_Fox.frame.index + 1) % g_Fox.frame.nrFrames;
		g_Fox.frame.rect = GetFrameRectf(g_Fox.frame.startIndex + g_Fox.frame.index);
	}
}

void	UpdateFoxJumpState(const Uint8* pStates) {

	if (!g_Fox.isJumping && pStates[SDL_SCANCODE_SPACE]) {
		g_Fox.isJumping = true;
		g_Fox.vy = g_JumpPower;
		g_Fox.pos.y -= 2.f;
	}
	else if (g_Fox.isJumping && g_Fox.pos.y > g_Ground.top - g_Fox.texture.frameHeight) {
		g_Fox.isJumping = false;
		g_Fox.vy = 0.f;
		g_Fox.pos.y = g_Ground.top - g_Fox.texture.frameHeight;
	}
}

void	UpdateFoxAnimState(const Uint8* pStates) {
	if ((pStates[SDL_SCANCODE_RIGHT] || pStates[SDL_SCANCODE_LEFT]) && g_Fox.animState != AnimState::Jump) {
		g_Fox.animState = AnimState::Walk;
	}
	else if (g_Fox.animState == AnimState::Walk && (!pStates[SDL_SCANCODE_RIGHT] && !pStates[SDL_SCANCODE_LEFT])) {
		g_Fox.animState = AnimState::Idle;
		g_SleepTime = 0.f;
	}
	if (!g_Fox.isJumping && pStates[SDL_SCANCODE_SPACE]) {
		g_Fox.animState = AnimState::Jump;
	}
	else if (g_Fox.isJumping && g_Fox.pos.y > g_Ground.top - g_Fox.texture.frameHeight) {
		g_Fox.animState = AnimState::Idle;
		g_SleepTime = 0.f;
	}

	if (g_Fox.animState == AnimState::Idle && g_SleepTime > 5.f) {
		g_Fox.animState = AnimState::Sleep;
	}
}
void	UpdateFoxDirection(const Uint8* pStates) {
	if (pStates[SDL_SCANCODE_RIGHT]) {
		g_Fox.vx = g_FoxSpeed * g_Fox.dir.x;
		g_Fox.dir.x = 1.f;
	}
	else if (pStates[SDL_SCANCODE_LEFT]) {
		g_Fox.vx = g_FoxSpeed * g_Fox.dir.x;
		g_Fox.dir.x = -1.f;
	}

}

#pragma endregion ownDefinitions