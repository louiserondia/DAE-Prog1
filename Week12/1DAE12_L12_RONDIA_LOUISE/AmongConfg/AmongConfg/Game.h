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
const Color4f g_Black{ 0.f, 0.f, 0.f, 1.f };

struct Button {
	Texture		captionTexture;
	Rectf		bounds;
};

enum class GameStates {
	color,
	hat,
	pet,
	game,
	eject
};

struct CrewMate {
	int		colorIdx{};
	int		hatIdx{ -1 };
	int		petIdx{ -1 };
	Rectf	src{};
	Rectf	dst{};
	float	scale{ 1 };
	bool	isImposter{};

	bool operator==(const CrewMate& rhs) {
		return colorIdx == rhs.colorIdx && hatIdx == rhs.hatIdx && petIdx == rhs.petIdx;
	}
};

struct Stars {
	Point2f pos;
	int		size;
	int		speed;
};

std::string g_ButtonTexts[]{ "color", "hat", "pet", "game" };
Button		g_Buttons[std::size(g_ButtonTexts)]{};
int			g_CurButton{};

Rectf		g_GridBounds{};
Texture		g_GameTexture{};

GameStates	g_GameState{};
const int	g_GridNumColumns{ 5 };
int			g_GridNumRows{};
float		g_GridTileSize{};

Texture		g_ColorsTexture{};
Texture		g_HatsTexture{};
Texture		g_PetsTexture{};
Texture		g_WasImposterTexture{};
Texture		g_WasNotImposterTexture{};

Point2f		g_TextDst{};
Rectf		g_TextSrc{};

const int	g_NumColors{ 13 };
Rectf		g_ColorsFrames[g_NumColors]{};
const int	g_NumColsColors{3};
const int	g_NumRowsColors{5};

const int	g_NumHats{ 29 };
Rectf		g_HatsFrames[g_NumHats]{};
const int	g_NumColsHats{5};
const int	g_NumRowsHats{6};

const int	g_NumPets{ 10 };
Rectf		g_PetsFrames[g_NumPets]{};
const int	g_NumColsPets{5};
const int	g_NumRowsPets{2};

std::vector<CrewMate> g_CrewMates;
Point2f		g_Dir{ 0.f, 0.f };
int			g_ImposterIndex{};

Stars		g_Stars[100]{};

// Declare your own functions here

void	InitializeButtons();
void	InitializeGrid();
void	InitializeAssets();
void	InitFrames(int nFeatures, int nRows, int nCols, Rectf* frames, const Texture& texture);
void	InitCrewMate();
void	InitStars();
void	InitTextPos();

void	DrawButtons();
void	DrawGrid();
void	DrawFeatures(int numFeatures, const Texture& texture, const Rectf* frames);
void	DrawCrewMate(const CrewMate& mate);
void	DrawCrewMates();
void	DrawStars();
void	DrawTextImposter();

void	UpdateFeaturesIndex(int index, const Point2f& mouse);
void	UpdateCrewMateForGame();

int		SelectCrewMate(const Point2f& mouse);
void	SelectNewImposter();

void	StartEjection();
void	UpdateEjectionAnimation(float elapsedSec);
void	UpdateStarsPosition(float elapsedSec);
void	UpdateTextFrame();
void	EndEjection();

void	PutBackCrewMate(int index);
void	EraseCrewMate(int index);

void	UpdateCrewMatePosition(float elapsedSec);

bool	IsDuplicate(const CrewMate& mate);
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
