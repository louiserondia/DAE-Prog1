#pragma once
#include <utils.h>
#include <map>
using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "Coding Craftmanship 08 - Rondia, Louise - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 1080 };
float g_WindowHeight{ 720 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

const Color4f g_White{ 1.f, 1.f, 1.f, 1.f };
const Color4f g_LightGrey{ 0.f, 0.f, 0.f, 0.1f };
const Color4f g_MedGrey{ 0.f, 0.f, 0.f, 0.2f };
const Color4f g_DarkGrey{ 0.f, 0.f, 0.f, 0.5f };
const Color4f g_Black{ 0.f, 0.f, 0.f, 1.f };

enum class AnimState {
	Idle,
	Walk,
	Jump,
	Sleep,
};

struct FoxTexture {
	Texture		texture{};
	const int	nrCols{ 22 };
	const int	nrRows{ 7 };
	float		frameWidth{};
	float		frameHeight{};
};

struct AnimationFrame {
	int row{};
	int col{};
	int nrFrames{};
};

struct Frame {
	Rectf		rect{};
	int			index{};
	int			startIndex{};
	int			nrFrames{};
};

struct Fox {
	Point2f		pos{};
	Point2f		dir{};
	Frame		frame{};
	FoxTexture	texture{};
	AnimState	animState{};
	bool		isJumping{};
	float		vx{};
	float		vy{};
};

struct Step {
	Ellipsef	shape{ 0.f, 0.f, 5.f, 3.f };
	Color4f		color{ g_DarkGrey };
	bool		isOn{};
	float		coolDown{};
	int			index{};
};

float		g_FrameTime{};
float		g_SleepTime{};
const float g_Gravity{ 800.f };
const float g_JumpPower{ -400.f };
const float g_FoxSpeed{ 200.f };
const float g_FoxDrawWidth{ 100.f };
const float g_FoxDrawHeight{ 100.f };

const int	g_NrSteps{ 8 };
Step		g_Steps[g_NrSteps]{};
float		g_StepOffset{};
int			g_StepIndex{};

Fox			g_Fox{};
Rectf		g_Ground{ 0.f, g_WindowHeight * .75f, g_WindowWidth, g_WindowHeight };
Texture		g_HeightMap{};

std::map<std::string, AnimationFrame> g_AnimFrames{};

// Declare your own functions here

void	DrawLandscape();
void	DrawSteps();
void	UpdateSteps(float elapsedSec);

void	InitFox();
void	DrawFox();
void	UpdateFoxPos(float elapsedSec);
void	UpdateFoxFrame(float elapsedSec);
void	UpdateFoxFrameStartIndex();
void	UpdateFoxAnimState(const Uint8* pStates);
void	UpdateFoxDirection(const Uint8* pStates);
void	UpdateFoxJumpState(const Uint8* pStates);

Rectf	GetFrameRectf(int index);

int GetIndex(int rowIdx, int colIdx, int nrCols);
int GetRow(int index, int nrCols);
int GetCol(int index, int nrCols);

void InitAnimationFrames();
bool IsAnyMovementKeyPressed(const Uint8* pStates);

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
