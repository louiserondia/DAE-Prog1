// 1DAE12 Louise Rondia

#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground();

	DrawRandomRectangles();

	// Put your own draw statements here

}

void Update(float elapsedSec)
{
}

void End()
{
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

void DrawRandomRectangles() {
	for (int i = 0; i < 100; i++) {

		const Point2f pos{
			std::max(10.f, rand() / float(RAND_MAX) * g_WindowWidth - 10.f),
			std::max(10.f, rand() / float(RAND_MAX) * g_WindowHeight - 10.f)
		};
		const float
			maxWidth{ g_WindowWidth - pos.x - 20.f },
			maxHeight{ g_WindowHeight - pos.y - 20.f };
		const float
			width{ rand() / float(RAND_MAX) * maxWidth },
			height{ rand() / float(RAND_MAX) * maxHeight };

		SetColor(0.f, 0.f, 0.f);
		DrawRect(pos, width, height);
		SetColor(rand() / float(RAND_MAX), rand() / float(RAND_MAX), rand() / float(RAND_MAX), 1.f);
		FillRect(pos, width, height);
	}
}

#pragma endregion ownDefinitions