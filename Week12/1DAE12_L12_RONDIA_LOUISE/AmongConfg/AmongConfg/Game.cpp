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
	TextureFromString("This was the Imposter", "Resources/among.ttf", 64, g_White, g_WasImposterTexture);
	TextureFromString("This was not the Imposter", "Resources/among.ttf", 64, g_White, g_WasNotImposterTexture);
	InitCrewMate();
	InitStars();
}

void Draw()
{
	ClearBackground(g_PaleGreen.r, g_PaleGreen.g, g_PaleGreen.b);
	DrawButtons();

	switch (g_GameState) {
	case GameStates::color:
		DrawGrid();
		DrawFeatures(g_NumColors, g_ColorsTexture, g_ColorsFrames);
		DrawCrewMate(g_CrewMates.back());
		break;
	case GameStates::hat:
		DrawGrid();
		DrawFeatures(g_NumHats, g_HatsTexture, g_HatsFrames);
		DrawCrewMate(g_CrewMates.back());
		break;
	case GameStates::pet:
		DrawGrid();
		DrawFeatures(g_NumPets, g_PetsTexture, g_PetsFrames);
		DrawCrewMate(g_CrewMates.back());
		break;
	case GameStates::game:
		DrawTexture(g_GameTexture,
			Rectf{ 0.f, 0.f, g_WindowWidth, g_WindowHeight - g_Buttons[0].bounds.height },
			Rectf{ 0.f, 0.f, 880.f, 587.f });
		DrawCrewMates();
		break;
	case GameStates::eject:
		DrawStars();
		DrawTextImposter();
		DrawCrewMate(g_CrewMates.back());
		break;
	default:
		break;
	};

}

void Update(float elapsedSec)
{
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);
	if (g_GameState == GameStates::game) {
		g_Dir.x = pStates[SDL_SCANCODE_RIGHT] ? 1.f : pStates[SDL_SCANCODE_LEFT] ? -1.f : 0.f;
		g_Dir.y = pStates[SDL_SCANCODE_DOWN] ? 1.f : pStates[SDL_SCANCODE_UP] ? -1.f : 0.f;
	}

	UpdateEjectionAnimation(elapsedSec);
	UpdateCrewMatePosition(elapsedSec);
}

void End()
{
	DeleteTexture(g_ColorsTexture);
	DeleteTexture(g_HatsTexture);
	DeleteTexture(g_PetsTexture);
	DeleteTexture(g_GameTexture);
	DeleteTexture(g_WasImposterTexture);
	DeleteTexture(g_WasNotImposterTexture);
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{
}

void OnKeyUpEvent(SDL_Keycode key)
{
	if (key == SDLK_RETURN && g_CrewMates.size() > 1) {
		StartEjection();
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
	const Point2f mouse{ float(e.x), float(e.y) };

	const int buttonIndex{ GetButtonIdFromClick(mouse) };
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		if (buttonIndex != -1) {
			if (buttonIndex >= 0 && buttonIndex <= 2 && g_GameState == GameStates::game && !IsDuplicate(g_CrewMates.back())) {
				InitCrewMate();
				SelectNewImposter();
			}
			g_GameState = static_cast<GameStates>(buttonIndex);
			if (g_GameState == GameStates::game && !IsDuplicate(g_CrewMates.back())) {
				UpdateCrewMateForGame();
			}
		}
		else if (g_GameState != GameStates::game) {
			const int cellIndex{ GetCellIndex(mouse) };

			if (cellIndex != -1) {
				PrintCellIndex(mouse, cellIndex);
				UpdateFeaturesIndex(cellIndex, mouse);
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
	const float width{ g_WindowWidth / std::size(g_Buttons) };
	const float height{ 50.f };
	const float top{ g_WindowHeight - height };

	for (int index{}; index < std::size(g_Buttons); ++index) {
		g_Buttons[index].bounds = Rectf{ width * index, top, width, height };
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

void InitFrames(int nFeatures, int nRows, int nCols, Rectf* frames, const Texture& texture) {
	const float width{ texture.width / nCols };
	const float height{ texture.height / nRows };
	for (int index{}; index < nFeatures; ++index) {
		frames[index] = Rectf{ GetCol(index, nCols) * width, GetRow(index, nCols) * height, width, height };
	}
}

void InitializeAssets() {
	TextureFromFile("Resources/colors.png", g_ColorsTexture);
	TextureFromFile("Resources/hats.png", g_HatsTexture);
	TextureFromFile("Resources/pets.png", g_PetsTexture);

	InitFrames(g_NumColors, g_NumRowsColors, g_NumColsColors, g_ColorsFrames, g_ColorsTexture);
	InitFrames(g_NumHats, g_NumRowsHats, g_NumColsHats, g_HatsFrames, g_HatsTexture);
	InitFrames(g_NumPets, g_NumRowsPets, g_NumColsPets, g_PetsFrames, g_PetsTexture);
}

void InitCrewMate() {
	g_CrewMates.push_back(CrewMate{});
	g_CrewMates.back().dst = Rectf{
		g_WindowWidth / 4 - (g_ColorsTexture.width / g_NumColsColors / 2),
		g_WindowHeight / 2 - g_ColorsTexture.height / g_NumRowsColors / 2,
		g_ColorsTexture.width / g_NumColsColors,
		g_ColorsTexture.height / g_NumRowsColors
	};
	g_CrewMates.back().src = Rectf{ 0.f, 0.f, g_ColorsTexture.width / g_NumColsColors,  g_ColorsTexture.height / g_NumRowsColors };
}

void SelectNewImposter() {
	const size_t index{ rand() % g_CrewMates.size() };
	for (CrewMate& mate : g_CrewMates) {
		mate.isImposter = false;
	}
	g_CrewMates.at(index).isImposter = true;
}

void InitStars() {
	for (int index{}; index < std::size(g_Stars); ++index) {
		g_Stars[index].pos = Point2f{
			static_cast<float>(rand() % static_cast<int>(g_WindowWidth)),
			static_cast<float>(rand() % static_cast<int>(g_WindowHeight))
		};
		g_Stars[index].size = rand() % 3 + 1;
		g_Stars[index].speed = rand() % 17 + 4;
	}
}

void InitTextPos() {
	if (g_CrewMates.back().isImposter) {
		g_TextDst.x = (g_WindowWidth - g_WasImposterTexture.width) / 2;
	}
	else {
		g_TextDst.x = (g_WindowWidth - g_WasNotImposterTexture.width) / 2;
	}
	g_TextDst.y = (g_WindowHeight - g_WasImposterTexture.height) / 2;
	g_TextSrc.height = g_WasImposterTexture.height;
	g_TextSrc.width = 0.f;
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

void DrawFeatures(int nFeatures, const Texture& texture, const Rectf* frames) {
	const float gap{ 4.f };
	const float height{ g_GridTileSize - gap },
		width{ frames[0].width / (frames[0].height / height) };

	for (int index{}; index < nFeatures; ++index) {
		const Rectf rect{
			g_GridBounds.left + GetCol(index, g_GridNumColumns) * g_GridTileSize + g_GridTileSize / 2 - width / 2,
			g_GridBounds.top + GetRow(index, g_GridNumColumns) * g_GridTileSize,
			width, height
		};

		DrawTexture(texture, rect, frames[index]);
	}
}

void DrawCrewMate(const CrewMate& mate) {
	const float
		hatWidth{ g_HatsTexture.width / g_NumColsHats * mate.scale },
		hatHeight{ g_HatsTexture.height / g_NumRowsHats * mate.scale };
	const Rectf hatDst{ mate.dst.left, mate.dst.top - hatHeight / 2, hatWidth, hatHeight };

	const float
		petWidth{ g_PetsTexture.width / g_NumColsPets * mate.scale },
		petHeight{ g_PetsTexture.height / g_NumRowsPets * mate.scale };
	const Rectf petDst{ mate.dst.left - petWidth / 3, mate.dst.top + petHeight / 2, petWidth, petHeight };

	DrawTexture(g_ColorsTexture, mate.dst, g_ColorsFrames[mate.colorIdx]);
	if (mate.hatIdx != -1) {
		DrawTexture(g_HatsTexture, hatDst, g_HatsFrames[mate.hatIdx]);
	}
	if (mate.petIdx != -1) {
		DrawTexture(g_PetsTexture, petDst, g_PetsFrames[mate.petIdx]);
	}
}

void DrawCrewMates() {
	for (size_t index{}; index < g_CrewMates.size(); ++index) {
		const CrewMate& mate = g_CrewMates[index];
		if (!(index == g_CrewMates.size() - 1 && IsDuplicate(mate))) {
			DrawCrewMate(mate);
		}
	}
}

void DrawStars() {
	SetColor(g_Black);
	FillRect(0.f, 0.f, g_WindowWidth, g_WindowHeight);
	for (size_t index{}; index < std::size(g_Stars); ++index) {
		const float size{ static_cast<float>(g_Stars[index].size) };

		SetColor(g_White);
		DrawRect(g_Stars[index].pos.x, g_Stars[index].pos.y, size, size);
	}
}

void	DrawTextImposter() {
	if (g_GameState != GameStates::eject || !g_TextSrc.width) return;

	if (g_CrewMates.back().isImposter) {
		DrawTexture(g_WasImposterTexture, g_TextDst, g_TextSrc);
	}
	else {
		DrawTexture(g_WasNotImposterTexture, g_TextDst, g_TextSrc);
	}
}

void UpdateFeaturesIndex(int index, const Point2f& mouse) {
	switch (g_GameState) {
	case GameStates::hat:
		g_CrewMates.back().hatIdx = index >= g_NumHats ? -1 : index;
		break;
	case GameStates::color:
		g_CrewMates.back().colorIdx = index >= g_NumColors ? -1 : index;
		break;
	case GameStates::pet:
		g_CrewMates.back().petIdx = index >= g_NumPets ? -1 : index;
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
		if (IsInRectBounds(mouse, g_CrewMates[index].dst)) {
			return index;
		}
	}
	return -1;
}

void PutBackCrewMate(int index) {
	g_CrewMates.push_back(g_CrewMates[index]);
	g_CrewMates.erase(g_CrewMates.begin() + index);
}

void EraseCrewMate(int index) {
	g_CrewMates.erase(g_CrewMates.begin() + index);
}

void UpdateCrewMatePosition(float elapsedSec) {
	const float speed{ 150.f };

	g_CrewMates.back().dst.left += elapsedSec * speed * g_Dir.x;
	g_CrewMates.back().dst.top += elapsedSec * speed * g_Dir.y;
}

void StartEjection() {
	g_GameState = GameStates::eject;
	const int index{ rand() % static_cast<int>(g_CrewMates.size()) };
	PutBackCrewMate(index);
	CrewMate& mate{ g_CrewMates.back() };

	mate.dst.left = 0.f - mate.dst.width;
	mate.dst.top = (g_WindowHeight - mate.dst.height) / 2;
	g_Dir = Point2f{ 1.f, 0.f };
	InitTextPos();
}

void UpdateEjectionAnimation(float elapsedSec) {
	if (g_GameState != GameStates::eject) return;

	if (g_CrewMates.back().dst.left >= g_WindowWidth) {
		EndEjection();
	}
	else {
		UpdateTextFrame();
		UpdateStarsPosition(elapsedSec);
	}
}

void UpdateStarsPosition(float elapsedSec) {
	for (int index{}; index < std::size(g_Stars); ++index) {
		g_Stars[index].pos.x += elapsedSec * g_Stars[index].speed;
		if (g_Stars[index].pos.x >= g_WindowWidth) {
			g_Stars[index].pos.x = 0.f;
		}
	}
}

void UpdateTextFrame() {
	if (g_GameState != GameStates::eject) return;

	const float maxWidth{ g_CrewMates.back().isImposter ? g_WasImposterTexture.width : g_WasNotImposterTexture.width };
	if (g_CrewMates.back().dst.left > g_TextDst.x
		&& g_CrewMates.back().dst.left < g_TextDst.x + maxWidth) {
		g_TextSrc.width = g_CrewMates.back().dst.left - g_TextDst.x;
	}
}

void EndEjection() {
	g_GameState = GameStates::game;
	g_CrewMates.pop_back();
}

bool IsDuplicate(const CrewMate& mate) {
	return (std::find(g_CrewMates.begin(), g_CrewMates.end() - 1, mate) != g_CrewMates.end() - 1);
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