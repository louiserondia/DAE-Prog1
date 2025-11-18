#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	if (!TextureFromFile("Resources/crewmate.png", g_ImgCrewmate)) {
		std::cout << "crewmate img failed to load\n";
	}
	if (!TextureFromFile("Resources/sus.png", g_ImgSus)) {
		std::cout << "sus img failed to load\n";
	}
	if (!TextureFromString("Among Us",
		"Resources/Impostograph-Regular.ttf",
		150,
		Color4f{ g_White },
		g_TextAmongUs)) {

		std::cout << "text failed to load\n";
	}
	if (!TextureFromString("RED IS SUS!",
		"Resources/VCR_OSD_MONO_1.001.ttf",
		50,
		Color4f{ g_Red },
		g_TextRedIsSus)) {

		std::cout << "text failed to load\n";
	}

}

void Draw()
{
	const Rectf susBounds{
			g_WindowWidth / 4 - g_ImgCrewmate.width / 2,
			g_WindowHeight / 4 - g_ImgCrewmate.height / 2,
			g_ImgSus.width,
			g_ImgSus.height
	};
	const Rectf knifeCutout{ g_ImgSus.width - 64.f, 0.f, 64.f, g_ImgSus.height };
	const Rectf knifeBounds{
			g_WindowWidth / 8,
			g_WindowHeight / 8,
			knifeCutout.width / 2,
			knifeCutout.height / 2
	};

	ClearBackground();

	DrawTexture(g_ImgCrewmate,
		Rectf{
			g_WindowWidth / 2 - g_ImgCrewmate.width / 2,
			g_WindowHeight / 2 - g_ImgCrewmate.height / 2,
			g_ImgCrewmate.width,
			g_ImgCrewmate.height
		});

	DrawTexture(g_ImgSus, knifeBounds, knifeCutout);

	DrawTexture(g_TextAmongUs,
		Point2f{
			g_WindowWidth / 2 - g_TextAmongUs.width / 2,
			g_WindowHeight / 4 - g_TextAmongUs.height / 2
		});
	DrawTexture(g_TextRedIsSus,
		Point2f{
			g_WindowWidth / 2 - g_TextRedIsSus.width / 2,
			g_WindowHeight * .75f
		});

}

void Update(float elapsedSec)
{

}

void End()
{
	DeleteTexture(g_ImgCrewmate);
	DeleteTexture(g_TextAmongUs);
	DeleteTexture(g_TextRedIsSus);
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

#pragma endregion ownDefinitions