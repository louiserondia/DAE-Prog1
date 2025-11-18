#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	CreateTextures();
}

void Draw()
{
	ClearBackground();

	DrawCards();
}

void Update(float elapsedSec)
{
	const Uint8 *pStates = SDL_GetKeyboardState( nullptr );

	if ( pStates[SDL_SCANCODE_S] ) {
		ShuffleCards();
	}
}

void End()
{
	DeleteTextures();
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

void CreateTextures() {
	for (int index{}; index < g_NrCards; ++index) {
		const std::string path{ "Resources/" + std::to_string(((index / 13) + 1) * 100 + (index % 13) + 1) + ".png" };
		if (!TextureFromFile(path, g_Cards[index]))
			std::cout << "Error loading card n" << index << " with path " << path << std::endl;
	}
}

void DeleteTextures() {
	for (int index{}; index < g_NrCards; ++index) {
		DeleteTexture(g_Cards[index]);
	}
}

void DrawCards() {
	const int nrRow{ 4 }, nrCol{ 13 };
	const float width{ g_WindowWidth / nrCol }, height{ g_WindowHeight / nrRow };

	for (int index{}; index < g_NrCards; ++index) {
		const Texture texture{ g_Cards[index] };
		const Rectf pos{ index % nrCol * width, index / nrCol * height, width, texture.height * (width / texture.width)};
		DrawTexture(texture, pos);
	}
}

void SwapCards(int index1, int index2) {
		Texture tmp{ g_Cards[index1] };
		g_Cards[index1] = g_Cards[index2];
		g_Cards[index2] = tmp;
}

void ShuffleCards() {
	for (int i{}; i < 100; ++i) {
		const int index1{ rand() % g_NrCards };
		int index2{};
		do {
			index2 = rand() % g_NrCards;
		} while (index2 == index1);

		SwapCards(index1, index2);
	}
}


#pragma endregion ownDefinitions