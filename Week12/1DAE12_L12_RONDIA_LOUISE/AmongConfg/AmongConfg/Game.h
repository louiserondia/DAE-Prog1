#pragma once

#include <utils.h>
using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "AmongConfg - Rondia, Louise - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 880 };
float g_WindowHeight{ 600 };
#pragma endregion gameInformation

#pragma region ownDeclarations
// Declare your own global variables here

const Color4f g_PaleGreen{ 0.7f, 1.f, 0.7f, 1.f };
const Color4f g_DarkGreen{ 0.5f, 0.8f, 0.5f, 1.f };
const Color4f g_White{ 1.f, 1.f, 1.f, 1.f };

struct Button {
	Texture		captionTexture;
	Rectf		bounds;
};

enum class GameStates {
	color,
	hat,
	game
};

struct CrewMate {
	int		colorIdx{};
	int		hatIdx{ -1 };
	Rectf	src{};
	Rectf	dst{};
	float	scale{ 1 };
};

std::string g_ButtonTexts[]{ "color", "hat", "game" };
Button		g_Buttons[std::size(g_ButtonTexts)]{};
int			g_CurButton{};

Rectf		g_GridBounds{};
Texture		g_GameTexture{};

GameStates	g_GameState{};
const int	g_GridNumColumns{ 5 };
int			g_GridNumRows{};
float		g_GridTileSize{};

const int	g_NumHats{ 29 };
Rectf		g_HatsFrames[g_NumHats]{};
Texture		g_ColorsTexture{};
Texture		g_HatsTexture{};

const int	g_NumColors{ 13 };
Rectf		g_ColorsFrames[g_NumColors]{};

std::vector<CrewMate> g_CrewMates{};
Point2f		g_Dir{ 0.f, 0.f };

// Declare your own functions here

void	InitializeButtons();
void	InitializeGrid();
void	InitializeAssets();
void	InitCrewMate();

void	DrawButtons();
void	DrawGrid();
void	DrawHats();
void	DrawColors();
void	DrawCrewMate(const CrewMate& mate);
void	DrawCrewMates();

void	UpdateHatAndColorIndex(int index, const Point2f& mouse);
void	UpdateCrewMateForGame();

int		SelectCrewMate(const Point2f& mouse);

void	PutBackCrewMate(int index);
void	EraseCrewMate(int index);

void	UpdateCrewMatePosition(float elapsedSec);

bool	IsInRectBounds(const Point2f& mouse, const Rectf& bounds);
int		GetButtonIdFromClick(const Point2f& mouse);
int		GetCellIndex(Point2f mouse);
void	PrintCellIndex(Point2f mouse);
void	PrintCellIndex(Point2f mouse, int index);

int		GetRow(int index, int nrCols);
int		GetCol(int index, int nrCols);
int		GetIndex(int row, int col, int nrCols);

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
