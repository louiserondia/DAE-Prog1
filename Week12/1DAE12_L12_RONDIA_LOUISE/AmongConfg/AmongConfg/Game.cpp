#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	InitializeButtons();
	InitializeGrid();
	InitializeAssets();
	TextureFromFile("Resources/game.jpg", g_GameTexture);
	InitCrewMate();
}

void Draw()
{
	ClearBackground(g_PaleGreen.r, g_PaleGreen.g, g_PaleGreen.b);
	DrawButtons();

	switch (g_GameState) {
	case GameStates::color:
		DrawGrid();
		DrawColors();
		DrawCrewMate(g_CrewMates.back());
		break;
	case GameStates::hat:
		DrawGrid();
		DrawHats();
		DrawCrewMate(g_CrewMates.back());
		break;
	case GameStates::game:
		DrawTexture(g_GameTexture,
			Rectf{ 0.f, 0.f, g_WindowWidth, g_WindowHeight - g_Buttons[0].bounds.height },
			Rectf{ 0.f, 0.f, 880.f, 587.f });
		DrawCrewMates();
		break;
	default:
		break;
	};

}

void Update(float elapsedSec)
{
	const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	g_Dir.x = pStates[SDL_SCANCODE_RIGHT] ? 1.f : pStates[SDL_SCANCODE_LEFT] ? -1.f : 0.f;
	g_Dir.y = pStates[SDL_SCANCODE_DOWN] ? 1.f : pStates[SDL_SCANCODE_UP] ? -1.f : 0.f;

	UpdateCrewMatePosition(elapsedSec);
}

void End()
{
	// free game resources here
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
	const Point2f mouse{ float(e.x), float(e.y) };

	const int buttonIndex{ GetButtonIdFromClick(mouse) };
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		if (buttonIndex != -1) {
			if ((buttonIndex == 0 || buttonIndex == 1) && g_GameState == GameStates::game) {
				InitCrewMate();
			}
			g_GameState = static_cast<GameStates>(buttonIndex);
			if (g_GameState == GameStates::game) {
				UpdateCrewMateForGame();
			}
		}
		else if (g_GameState != GameStates::game) {
			const int cellIndex{ GetCellIndex(mouse) };

			if (cellIndex != -1) {
				PrintCellIndex(mouse, cellIndex);
				UpdateHatAndColorIndex(cellIndex, mouse);
			}
		}
		else {
			const int mateIndex{ SelectCrewMate(mouse) };

			if (mateIndex != -1) {
				PutBackCrewMate(mateIndex);
			}
		}
		break;
	case SDL_BUTTON_RIGHT:
		if (g_GameState == GameStates::game) {
			const int mateIndex{ SelectCrewMate(mouse) };

			if (mateIndex != -1) {
				EraseCrewMate(mateIndex);
			}
		}
		break;
	case SDL_BUTTON_MIDDLE:
		break;
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

void InitializeButtons() {
	const float thirdWindow{ g_WindowWidth / 3 };
	const float height{ 50.f };
	const float top{ g_WindowHeight - height };

	for (int index{}; index < std::size(g_Buttons); ++index) {
		g_Buttons[index].bounds = Rectf{ thirdWindow * index, top, thirdWindow, height };
		TextureFromString(g_ButtonTexts[index], "Resources/among.ttf", 32, g_White, g_Buttons[index].captionTexture);
	}
}

void InitializeGrid() {
	const float border{ 15.f };

	g_GridBounds = Rectf{
		g_WindowWidth / 2 + border,
		border,
		g_WindowWidth / 2 - 2 * border,
		g_WindowHeight - 2 * border - g_Buttons[0].bounds.height
	};
	g_GridTileSize = { g_GridBounds.width / g_GridNumColumns };
	g_GridNumRows = { static_cast<int>(g_GridBounds.height / g_GridTileSize) };
}

void InitializeAssets() {
	TextureFromFile("Resources/colors.png", g_ColorsTexture);
	TextureFromFile("Resources/hats.png", g_HatsTexture);

	float	width{ g_ColorsTexture.width / 3 },
		height{ g_ColorsTexture.height / 5 };
	for (int index{}; index < g_NumColors; ++index) {
		g_ColorsFrames[index] = Rectf{ index % 3 * width, index / 3 * height, width, height };
	}

	width = g_HatsTexture.width / 5;
	height = g_HatsTexture.height / 6;
	for (int index{}; index < g_NumHats; ++index) {
		g_HatsFrames[index] = Rectf{ index % 3 * width, index / 3 * height, width, height };
	}
}

void InitCrewMate() {
	g_CrewMates.push_back(CrewMate{});
	g_CrewMates.back().dst = Rectf{
		g_WindowWidth / 4 - (g_ColorsTexture.width / 6),
		g_WindowHeight / 2 - g_ColorsTexture.height / 10,
		g_ColorsTexture.width / 3,
		g_ColorsTexture.height / 5
	};
	g_CrewMates.back().src = Rectf{ 0.f, 0.f, g_ColorsTexture.width / 3,  g_ColorsTexture.height / 5 };
}

void DrawButtons() {

	for (int index{}; index < std::size(g_Buttons); ++index) {
		const Button& button{ g_Buttons[index] };

		SetColor(g_DarkGreen);
		FillRect(button.bounds);
		SetColor(g_PaleGreen);
		DrawRect(button.bounds);
		if (static_cast<int>(g_GameState) == index) {
			SetColor(g_White);
			DrawRect(button.bounds, 3.f);
		}

		const Point2f textPos{
			button.bounds.left + button.bounds.width / 2 - button.captionTexture.width / 2,
			button.bounds.top + button.bounds.height / 2 - button.captionTexture.height / 2
		};
		DrawTexture(button.captionTexture, textPos);
	}
}

void DrawGrid() {
	const float gap{ 4.f };

	SetColor(g_DarkGreen);
	for (int row{}; row < g_GridNumRows; ++row) {
		for (int col{}; col < g_GridNumColumns; ++col) {
			FillRect(g_GridBounds.left + col * g_GridTileSize,
				g_GridBounds.top + row * g_GridTileSize,
				g_GridTileSize - gap,
				g_GridTileSize - gap);
		}
	}
}

void DrawColors() {
	const float gap{ 4.f };
	const float height{ g_GridTileSize - gap * 2 },
		width{ g_ColorsFrames[0].width / (g_ColorsFrames[0].height / height) };

	for (int index{}; index < g_NumColors; ++index) {
		const Rectf rect{ g_GridBounds.left + GetCol(index, g_GridNumColumns) * g_GridTileSize + g_GridTileSize / 2 - width / 2,
			g_GridBounds.top + GetRow(index, g_GridNumColumns) * g_GridTileSize + gap,
			width, height };

		DrawTexture(g_ColorsTexture, rect, g_ColorsFrames[index]);
	}
}

void DrawHats() {
	const float gap{ 4.f };

	for (int index{}; index < g_NumHats; ++index) {
		const Rectf rect{ g_GridBounds.left + GetCol(index, g_GridNumColumns) * g_GridTileSize,
			g_GridBounds.top + GetRow(index, g_GridNumColumns) * g_GridTileSize,
			g_GridTileSize - gap,
			g_GridTileSize - gap };

		DrawTexture(g_HatsTexture, rect, g_HatsFrames[index]);
	}
}

void DrawCrewMate(const CrewMate& mate) {

	const float hatWidth{ g_HatsTexture.width / 5 * mate.scale }, hatHeight{ g_HatsTexture.height / 6 * mate.scale };
	const Rectf hatDst{ mate.dst.left, mate.dst.top - hatHeight / 2, hatWidth, hatHeight };

	DrawTexture(g_ColorsTexture, mate.dst, g_ColorsFrames[mate.colorIdx]);
	if (mate.hatIdx != -1) {
		DrawTexture(g_HatsTexture, hatDst, g_HatsFrames[mate.hatIdx]);
	}
}

void DrawCrewMates() {
	for (const CrewMate& mate : g_CrewMates) {
		DrawCrewMate(mate);
	}
}

void UpdateHatAndColorIndex(int index, const Point2f& mouse) {
	switch (g_GameState) {
	case GameStates::hat:
		g_CrewMates.back().hatIdx = index >= g_NumHats ? -1 : index;
		break;
	case GameStates::color:
		g_CrewMates.back().colorIdx = index >= g_NumColors ? -1 : index;
		break;
	default:
		break;
	};
}

void UpdateCrewMateForGame() {
	const float gap{ g_WindowWidth / 3 };
	const float
		x{ rand() % static_cast<int>(g_WindowWidth - gap) + gap / 2 },
		y{ rand() % static_cast<int>(g_WindowHeight / 2 - g_Buttons[0].bounds.height) + g_WindowHeight / 2 };

	CrewMate& mate{ g_CrewMates.back() };
	mate.scale = 0.4f;
	mate.dst = Rectf{ x, y - mate.src.height * mate.scale, mate.src.width * mate.scale, mate.src.height * mate.scale };
}

int SelectCrewMate(const Point2f& mouse) {
	for (int index{}; index < g_CrewMates.size(); ++index) {
		const CrewMate& mate{ g_CrewMates[index] };

		if (IsInRectBounds(mouse, mate.dst)) {
			return index;
		}
	}
	return -1;
}

void PutBackCrewMate(int index) {
	CrewMate& mate{ g_CrewMates[index] };
	g_CrewMates.push_back(mate);
	g_CrewMates.erase(g_CrewMates.begin() + index);
}

void EraseCrewMate(int index) {
	g_CrewMates.erase(g_CrewMates.begin() + index);
}

void UpdateCrewMatePosition(float elapsedSec) {
	const float speed{ 150.f };
	CrewMate& mate{ g_CrewMates.back() };
	mate.dst.left += elapsedSec * speed * g_Dir.x;
	mate.dst.top += elapsedSec * speed * g_Dir.y;
}

int GetCellIndex(Point2f mouse) {
	const float gap{ 4.f };

	for (int row{}; row < g_GridNumRows; ++row) {
		for (int col{}; col < g_GridNumColumns; ++col) {
			const Rectf rect{ g_GridBounds.left + col * g_GridTileSize,
				g_GridBounds.top + row * g_GridTileSize,
				g_GridTileSize - gap,
				g_GridTileSize - gap };

			if (IsInRectBounds(mouse, rect))
				return row * g_GridNumColumns + col;
		}
	}
	return -1;
}

void PrintCellIndex(Point2f mouse) {
	std::cout << "Cell at [" << mouse.x << ", " << mouse.y << "] is " << GetCellIndex(mouse) << std::endl;
}

void PrintCellIndex(Point2f mouse, int index) {
	std::cout << "Cell at [" << mouse.x << ", " << mouse.y << "] is " << index << std::endl;
}

bool IsInRectBounds(const Point2f& mouse, const Rectf& bounds) {
	return (mouse.x >= bounds.left && mouse.x <= bounds.left + bounds.width
		&& mouse.y >= bounds.top && mouse.y <= bounds.top + bounds.height);
}

int GetButtonIdFromClick(const Point2f& mouse) {
	for (int index{}; index < std::size(g_Buttons); ++index) {
		if (IsInRectBounds(mouse, g_Buttons[index].bounds)) {
			return index;
		}
	}
	return -1;
}

int GetRow(int index, int nrCols) {
	return index / nrCols;
}

int GetCol(int index, int nrCols) {
	return index % nrCols;
}

int GetIndex(int row, int col, int nrCols) {
	return row * nrCols + col;
}

#pragma endregion ownDefinitions