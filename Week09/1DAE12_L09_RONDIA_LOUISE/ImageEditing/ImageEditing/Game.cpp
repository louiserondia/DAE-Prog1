#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	g_Path = "Resources/img" + std::to_string(rand() % 19) + ".jpg";
	if (!TextureFromFile(g_Path, g_Image))
		std::cout << "Impossible to load " + g_Path + "\n";
	g_Pos = Point2f{ (g_WindowWidth - g_Image.width) / 2, (g_WindowHeight - g_Image.height) / 2 };
	g_Pixels = GetPixelsFromTexture(g_Image);
	g_ModPixels = GetPixelsFromTexture(g_Image);
}

void Draw()
{
	ClearBackground();
	DrawPixels(g_Pixels, g_Pos);
}

void Update(float elapsedSec)
{
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);

	if (pStates[SDL_SCANCODE_RIGHT])
		g_Pos.x += elapsedSec * g_Speed;
	if (pStates[SDL_SCANCODE_LEFT])
		g_Pos.x -= elapsedSec * g_Speed;
	if (pStates[SDL_SCANCODE_UP])
		g_Pos.y -= elapsedSec * g_Speed;
	if (pStates[SDL_SCANCODE_DOWN])
		g_Pos.y += elapsedSec * g_Speed;
}

void End()
{
	DeleteTexture(g_Image);
	delete[] g_Pixels;
	delete[] g_ModPixels;
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{
}

void OnKeyUpEvent(SDL_Keycode key)
{
	PixelManipulationFromKey(key);
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

void	DrawPixels(const Color4f* pixels, Point2f start) {
	for (int row{}; row < g_Image.height; row++) {
		for (int col{}; col < g_Image.width; col++) {
			const Color4f color{ g_ModPixels[GetIndex(row, col, static_cast<int>(g_Image.width))] };
			SetColor(color);
			DrawPixel(start.x + col, start.y + row);
		}
	}
}

void	PixelManipulationFromKey(SDL_Keycode key) {
	const int arraySize{ static_cast<int>(g_Image.width * g_Image.height) };

	if (key == SDLK_n) {
		GetNeutralPixels(g_ModPixels, g_Pixels, arraySize);
	}
	else if (key == SDLK_s) {
		GetSepiaPixels(g_ModPixels, g_Pixels, arraySize);
	}
	else if (key == SDLK_g) {
		GetGreyScalePixels(g_ModPixels, g_Pixels, arraySize);
	}
	else if (key == SDLK_b) {
		GetBrighterPixels(g_ModPixels, g_Pixels, arraySize);
	}
	else if (key == SDLK_d) {
		GetDarkerPixels(g_ModPixels, g_Pixels, arraySize);
	}
}

void GetNeutralPixels(Color4f* modPixels, const Color4f* pixels, int arraySize) {
	for (int index{}; index < arraySize; ++index) {
		modPixels[index].r = pixels[index].r;
		modPixels[index].g = pixels[index].g;
		modPixels[index].b = pixels[index].b;
	}
}

void GetGreyScalePixels(Color4f* modPixels, const Color4f* pixels, int arraySize) {
	for (int index{}; index < arraySize; ++index) {
		const float greyScale{ pixels[index].r * .3f + pixels[index].g * .59f + pixels[index].b * .11f };
		modPixels[index].r = greyScale;
		modPixels[index].g = greyScale;
		modPixels[index].b = greyScale;
	}
}

void GetSepiaPixels(Color4f* modPixels, const Color4f* pixels, int arraySize) {
	for (int index{}; index < arraySize; ++index) {
		const float sepiaScale{ pixels[index].r * .11f + pixels[index].g * .59f + pixels[index].b * .3f };
		modPixels[index].r = sepiaScale;
		modPixels[index].g = sepiaScale;
		modPixels[index].b = sepiaScale;
	}
}

void GetBrighterPixels(Color4f* modPixels, const Color4f* pixels, int arraySize) {
	for (int index{}; index < arraySize; ++index) {
		const float greyScale{ pixels[index].r * .3f + pixels[index].g * .59f + pixels[index].b * .11f };
		modPixels[index].r = pixels[index].r * 1.5f;
		modPixels[index].g = pixels[index].g * 1.5f;
		modPixels[index].b = pixels[index].b * 1.5f;
	}
}

void GetDarkerPixels(Color4f* modPixels, const Color4f* pixels, int arraySize) {
	for (int index{}; index < arraySize; ++index) {
		modPixels[index].r = pixels[index].r * .8f;
		modPixels[index].g = pixels[index].g * .8f;
		modPixels[index].b = pixels[index].b * .8f;
	}
}

#pragma endregion ownDefinitions