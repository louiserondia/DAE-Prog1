#pragma once
#include <utils.h>
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
const Color4f g_Black{ 0.f, 0.f, 0.f, 1.f };

enum class Facing
{
	Right,
	Left
};

enum class MoveState
{
	Grounded,
	Jumping,
	Falling
};

enum class AnimState {
	Idle,
	Walk,
	Jump,
	Fall,
	Sit
};

struct WolfTexture {
	Texture		texture{};
	const int	nrCols{ 6 };
	const int	nrRows{ 5 };
};

struct Frame {
	Rectf		rect{};
	int			index{};
	int			startIndex{};
	int			nrFrames{};
	float		width{};
	float		height{};
	const int	idleNrFrames{ 1 };
	const int	walkNrFrames{ 7 };
	const int	jumpNrFrames{ 4 };
};

struct Wolf {
	Point2f		pos{};
	Point2f		dir{};
	Frame		frame{};
	WolfTexture	texture{};
	MoveState	moveState{};
	AnimState	animState{};
	float		vx{};
	float		vy{};
};

float		g_FrameTime{};
const float g_Gravity{ 800.f };
const float g_JumpPower{ -400.f };
const float g_WolfSpeed{ 200.f };
Wolf g_Wolf{};
Rectf g_Ground{ 0.f, g_WindowHeight * .75f, g_WindowWidth, g_WindowHeight };

// Declare your own functions here

void	InitWolf();
void	DrawWolf();
void	UpdateWolfPos(float elapsedSec);
void	UpdateWolfFrame(float elapsedSec);
void	UpdateWolfFrameStartIndex();

Rectf	GetFrameRectf(int index);

int GetIndex(int rowIdx, int colIdx, int nrCols);
int GetRow(int index, int nrCols);
int GetCol(int index, int nrCols);

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
