#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	InitWorldScenes();
	InitAnimationFrames();
	InitFox();
	InitFoxSteps();
}

void Draw()
{
	ClearBackground(g_White.r, g_White.g, g_White.b);
	DrawBackground();
	DrawSteps();
	DrawFox();
	DrawForeground();

	// utils : draw altitude vectors

	//for (float col{}; col < g_WindowWidth; ++col) {
	//	SetColor(g_Black);
	//	DrawRect(col, g_World.scenes[g_World.currentScene].altitude[col], 1.f, 1.f);
	//}
}

void Update(float elapsedSec)
{
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);

	UpdateFoxAnimState(pStates);
	UpdateFoxJumpState(pStates);
	UpdateFoxDirection(pStates);
	UpdateFoxPos(elapsedSec);
	UpdateFoxFrame(elapsedSec);
	UpdateWorldScene();


	// should be when a key is pressed or released, whenever there's any event
	// so for now it's just updated all the time, is that ok ?

	//if (IsAnyMovementKeyPressed(pStates)) 
	UpdateFoxFrameStartIndex();
	UpdateSteps(elapsedSec);

	g_SleepTime += elapsedSec;
	g_Time += elapsedSec;

	g_CloudPos.x += cosf(g_Time) / 3;
}

void End()
{
	DeleteTexture(g_Fox.texture.texture);
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

void	InitWorldScenes() {
	g_World.scenes[0].altitude.resize(g_WindowWidth + 1);
	g_World.scenes[1].altitude.resize(g_WindowWidth + 1);
	TextureFromFile("Resources/landscape0_bg.png", g_World.scenes[0].bgTexture);
	TextureFromFile("Resources/landscape0_fg.png", g_World.scenes[0].fgTexture);
	TextureFromFile("Resources/landscape1_bg.png", g_World.scenes[1].bgTexture);
	TextureFromFile("Resources/landscape1_fg.png", g_World.scenes[1].fgTexture);
	TextureFromFile("Resources/cloud.png", g_Cloud);
	g_CloudPos = Point2f{ g_WindowWidth * 2 / 3 + 50.f, g_WindowHeight / 3 };

	const int third{ int(g_WindowWidth / 3) },
		third2{ int(g_WindowWidth / 3 * 2) };
	const float gap{ (g_MinAltitude - g_MaxAltitude) };

	for (int col{}; col < g_WindowWidth; ++col) {
		if (col > third && col < third2) {
			g_World.scenes[0].altitude[col] = g_MinAltitude - (gap / third * (col - third));
		}
		else if (col >= third2) {
			g_World.scenes[0].altitude[col] = g_MaxAltitude + (gap / third * (col - third2));
		}
		else {
			g_World.scenes[0].altitude[col] = g_MinAltitude;
		}
	}

	for (int col{}; col < g_WindowWidth; ++col) {
		if (col < int(third)) {
			g_World.scenes[1].altitude[col] = g_MaxAltitude + (gap / (third)*col);
		}
		else {
			g_World.scenes[1].altitude[col] = g_MinAltitude;
		}
	}
}

void InitFox() {
	if (!TextureFromFile("Resources/Fox Sprite Sheet.png", g_Fox.texture.texture)) {
		std::cout << "Couldn't load fox.png\n";
	}
	g_Fox.texture.frameWidth = g_Fox.texture.texture.width / g_Fox.texture.nrCols;
	g_Fox.texture.frameHeight = g_Fox.texture.texture.height / g_Fox.texture.nrRows;
	g_Fox.frame.rect = GetFrameRectf(0);
	g_Fox.frame.nrFrames = g_AnimFrames["idleRight"].nrFrames;
	g_Fox.frame.startIndex = GetIndex(g_AnimFrames["idleRight"].row, g_AnimFrames["idleRight"].col, g_Fox.texture.nrCols);
	g_Fox.pos = Point2f{ g_WindowWidth / 4, GetAltitude(g_WindowWidth / 4 + g_FoxDrawWidth / 2) - g_FoxDrawHeight };
	g_Fox.dir = Point2f{ 1.f, 0.f };
}

void	InitFoxSteps() {
	for (int i{}; i < g_NrSteps; ++i) {
		g_Steps[i].isOn = false;
		g_Steps[i].shape.center.y = g_Ground.top + (i & 1 ? 15.f : 0.f);
		g_Steps[i].index = i;
	}
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

float GetAltitude(float index) {
	if (index < 0.f)
		index = 0.f;
	else if (index >= g_WindowWidth)
		index = g_WindowWidth;
	return g_World.scenes[g_World.currentScene].altitude[static_cast<unsigned int>(index)];
}

void	DrawBackground() {
	SetColor(g_Orange);
	FillEllipse(g_Sun);
	DrawTexture(g_World.scenes[g_World.currentScene].bgTexture, Rectf{ 0.f, 0.f, g_WindowWidth, g_WindowHeight });
}

void DrawForeground() {
	DrawTexture(g_World.scenes[g_World.currentScene].fgTexture, Rectf{ 0.f, 0.f, g_WindowWidth, g_WindowHeight });
	if (!g_World.currentScene)
		DrawTexture(g_Cloud, g_CloudPos);
}

void DrawFox() {
	const Rectf rect{ g_Fox.pos.x, g_Fox.pos.y, g_FoxDrawWidth, g_FoxDrawHeight };
	DrawTexture(g_Fox.texture.texture, rect, g_Fox.frame.rect);
}

void UpdateFoxPos(float elapsedSec) {
	const float altitude{ GetAltitude(g_Fox.pos.x + g_FoxDrawWidth / 2) };

	g_Fox.pos.x += elapsedSec * g_Fox.vx;
	if (g_Fox.isJumping)
		g_Fox.pos.y += elapsedSec * g_Fox.vy;
	else
		g_Fox.pos.y = altitude - g_FoxDrawHeight;
	g_StepOffset += fabsf(elapsedSec * g_Fox.vx);

	if (g_Fox.isJumping) {
		g_Fox.vy += elapsedSec * g_Gravity;
	}
	if (g_Fox.animState == AnimState::Idle) {
		g_Fox.vx = 0.f;
	}
}

bool	IsAnyMovementKeyPressed(const Uint8* pStates) {
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

void	UpdateFoxFrame(float elapsedSec) {
	const float frameRate{ 1.f / 8.f };

	g_FrameTime += elapsedSec;
	if (g_FrameTime >= frameRate) {
		g_FrameTime = 0.f;
		g_Fox.frame.index = (g_Fox.frame.index + 1) % g_Fox.frame.nrFrames;
		g_Fox.frame.rect = GetFrameRectf(g_Fox.frame.startIndex + g_Fox.frame.index);
	}
}

void	UpdateFoxJumpState(const Uint8* pStates) {
	const float altitude{ GetAltitude(g_Fox.pos.x + g_FoxDrawWidth / 2) };

	if (!g_Fox.isJumping && pStates[SDL_SCANCODE_SPACE]) {
		g_Fox.isJumping = true;
		g_Fox.vy = g_JumpPower;
		g_Fox.pos.y -= 2.f;
	}
	else if (g_Fox.isJumping && g_Fox.pos.y > altitude - g_FoxDrawHeight) {
		g_Fox.isJumping = false;
		g_Fox.vy = 0.f;
		g_Fox.pos.y = GetAltitude(g_Fox.pos.x + g_FoxDrawWidth / 2) - g_FoxDrawHeight;
	}
}

void	UpdateFoxAnimState(const Uint8* pStates) {
	const float altitude{ GetAltitude(g_Fox.pos.x + g_FoxDrawWidth / 2) };

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
	else if (g_Fox.isJumping && g_Fox.pos.y > altitude - g_FoxDrawHeight) {
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

void	DrawSteps() {
	for (int i{}; i < g_NrSteps; ++i) {
		if (g_Steps[i].isOn) {
			SetColor(g_Steps[i].color);
			FillEllipse(g_Steps[i].shape);
		}
	}
}

void	UpdateSteps(float elapsedSec) {
	const float width{ g_Fox.frame.rect.width };
	const float altitude{ GetAltitude(g_Fox.pos.x + g_FoxDrawWidth / 2) };

	if (g_StepOffset > 15.f && !g_Fox.isJumping) {
		g_StepOffset = (g_StepIndex % 4 ? 0.f : -30.f);
		g_StepIndex = (g_StepIndex + 1) % g_NrSteps;

		g_Steps[g_StepIndex].shape.center.x = g_Fox.pos.x + (g_Fox.dir.x == -1 ? width * 2 : width);
		g_Steps[g_StepIndex].shape.center.y = altitude + (g_StepIndex & 1 ? (rand() % 7 - 3) + 7.f : (rand() % 7 - 3)) - 5.f;
		g_Steps[g_StepIndex].isOn = true;
		g_Steps[g_StepIndex].coolDown = 0.f;
		g_Steps[g_StepIndex].color = g_DarkGrey;

		const int last4{ (g_StepIndex + 1) % g_NrSteps }, last2{ (g_StepIndex + 3) % g_NrSteps };
		for (int index{}; index < g_NrSteps; ++index) {
			if (index == last4 || index == (last4 + 1) % g_NrSteps)
				g_Steps[index].color = g_LightGrey;
			else if (index == last2 || index == (last2 + 1) % g_NrSteps)
				g_Steps[index].color = g_MedGrey;
		}
	}

	for (int i{}; i < g_NrSteps; ++i) {
		g_Steps[i].coolDown += elapsedSec;

		if (g_Steps[i].coolDown > 5.f)
			g_Steps[i].isOn = false;
		else if (g_Steps[i].coolDown > 4.f)
			g_Steps[i].color = g_LightGrey;
		else if (g_Steps[i].coolDown > 3.f && g_Steps[i].color.a != g_LightGrey.a)
			g_Steps[i].color = g_MedGrey;
	}
}

void	UpdateWorldScene() {
	if (g_Fox.pos.x + g_FoxDrawWidth / 2 <= 0.f) {
		g_World.currentScene -= 1;
		if (g_World.currentScene < 0)
			g_World.currentScene = g_World.nrScenes - 1;
		g_Fox.pos.x = g_WindowWidth - g_FoxDrawWidth / 2;
		InitFoxSteps();
	}
	else if (g_Fox.pos.x + g_FoxDrawWidth / 2 >= g_WindowWidth) {
		g_World.currentScene += 1;
		g_World.currentScene %= g_World.nrScenes;
		g_Fox.pos.x = g_FoxDrawWidth / 2;
		InitFoxSteps();
	}

}

#pragma endregion ownDefinitions