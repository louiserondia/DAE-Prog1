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
const Color4f g_Orange{ 1.f, 0.7f, 0.2f, 1.f };

struct Scene {
	Texture bgTexture{};
	Texture fgTexture{};
	//std::vector<float> altitude(static_cast<unsigned int>(g_WindowWidth)) {};
	std::vector<float> altitude{};

};

Texture g_Cloud{};
Point2f	g_CloudPos{};
int		g_CloudDir{ 1 };

Ellipsef	g_Sun{ g_WindowWidth / 2, g_WindowHeight / 3 + 25.f, 35.f, 35.f };

struct World {
	static const int nrScenes{ 2 };
	Scene	scenes[nrScenes]{};
	int		currentScene{ 1 };
};

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

float		g_Time{};
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

const float g_MaxAltitude{ 200.f };
const float g_MinAltitude{ g_WindowHeight - 200.f };

World		g_World{};
Fox			g_Fox{};
Rectf		g_Ground{ 0.f, g_MinAltitude, g_WindowWidth, g_WindowHeight };

std::vector<float>	g_Altitude(static_cast<unsigned int>(g_WindowWidth));

std::map<std::string, AnimationFrame> g_AnimFrames{};

// Declare your own functions here

void	InitWorldScenes();
void	UpdateWorldScene();
void	DrawBackground();
void	DrawForeground();

void	DrawSteps();
void	UpdateSteps(float elapsedSec);

void	InitFox();
void	InitFoxSteps();
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
float GetAltitude(float index);

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
