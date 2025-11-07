// Rondia, Louise, 1DAE12

#include "pch.h"
#include "Game.h"
#include <iostream>

bool g_ShowBlink{ true };
float g_BlinkTimer{ 0.f };
float g_BlinkMax{ 1.f };
float g_BlinkDuration{.5f};

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground();

	float left{ g_WindowWidth / 6 };
	float top {g_WindowHeight / 6};
	float width {g_WindowWidth / 3 * 2};
	float height {g_WindowHeight / 3 * 2};

	float offset{ 20.f };
	float miniOffset{ 3.f };


	// GREY SHAPES

	SetColor(0.451f, 0.451f, 0.416f, 1.f); // mid grey
	FillRect(left, top, width, height);

	// BLACK SHAPES

	float insideBoxLength{ 200.f };

	SetColor(0.271f, 0.271f, 0.271f, 1.f); // dark grey
	FillRect(left + offset, top + 50, width - 40, height - 70); 
	FillRect(left + offset, top + offset, insideBoxLength, 30); // tab

	FillRect(offset, offset, 50.f, 2 * offset); // desktop icon rectangle

	// WHITE SHAPES

	SetColor(0.902f, 0.902f, 0.89f, 1.f); // light grey

		// tab cross

	float crossX1{ left - offset + insideBoxLength + 3 * miniOffset };
	float crossY1{ top + 30 + miniOffset };
	float crossX2{ left + insideBoxLength + miniOffset };
	float crossY2{ top + 30 + offset - miniOffset };
	DrawLine(crossX1,crossY1, crossX2, crossY2, 3.f);

		// I dont know if I can reassign values or if I should create new variables
	crossX1 = left + insideBoxLength + miniOffset;
	crossY1 = top + 30 + miniOffset;
	crossX2 = left - offset + insideBoxLength + 3 * miniOffset;
	crossY2 = top + 30 + offset - miniOffset;
	DrawLine(crossX1, crossY1, crossX2, crossY2, 3.f);

		// window cross

	crossX1 = left + width - 2 * offset + miniOffset;
	crossY1 = top + 10 + miniOffset;
	crossX2 = left + width - offset - miniOffset;
	crossY2 = top + 10 + offset - miniOffset;
	DrawLine(crossX1, crossY1, crossX2, crossY2, 3.f);

	crossX1 = left + width - offset - miniOffset;
	crossY1 = top + 10 + miniOffset;
	crossX2 = left + width - 2 * offset + miniOffset;
	crossY2 = top + 10 + offset - miniOffset;
	DrawLine(crossX1, crossY1, crossX2, crossY2, 3.f);

		// full screen rectangle and minus logo

	DrawRect(left + width - 3 * offset - miniOffset, top + 10 + miniOffset, offset - 2 * miniOffset, offset - 2 * miniOffset, 2.f);
	DrawLine(left + width - 4 * offset - 10, top + offset, left + width - 4 * offset + miniOffset, top + offset, 2.f);

		// desktop icon

	DrawLine(offset, offset, offset + 50.f, offset, 5.f); // top line
	DrawLine(2.25f * offset, offset * 2.5f, 3 * offset, offset * 2.5f, 5.f); // bottom horizontal line
	DrawLine(1.5f * offset, offset * 2, 2 * offset, offset * 2.25f, 5.f); // arrow top
	DrawLine(1.5f * offset, offset * 2.5f, 2 * offset, offset * 2.25f, 5.f); // arrow bottom

	DrawTriangle(width, height + miniOffset, width, height + offset, width + 10.f, height + offset - miniOffset, 2.f);
	DrawLine(width + 5.f, height + offset-miniOffset, width + 8.f, height + offset + 7.5f, 2.f);

		// text rectangles

	FillRect(left + 2 * offset, top + 30, 130, 20); // tab name

	FillRect(left + 2 * offset, top + 70, width - 80, offset);
	FillRect(left + 2 * offset, top + 100, width - 180, offset);
	FillRect(left + 2 * offset, top + 130, width - 300, offset);
	FillRect(left + 2 * offset, top + 160, width - 100, offset);
	if (g_ShowBlink) {
		FillRect(left + 2 * offset, top + 190, 10, offset);
	}

}

void Update(float elapsedSec)
{

	g_BlinkTimer += elapsedSec;

	if (g_BlinkTimer >= g_BlinkMax) {
		g_BlinkTimer = 0.f;
	}

	g_ShowBlink = (g_BlinkTimer < g_BlinkDuration);

	// process input, do physics 

	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
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
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	// SAMPLE CODE: print mouse position
	//const float mouseX{ float(e.x) };
	//const float mouseY{ float(e.y) };
	//std::cout << "  [" << mouseX << ", " << mouseY << "]\n";
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	// SAMPLE CODE: print mouse position
	//const float mouseX{ float(e.x) };
	//const float mouseY{ float(e.y) };
	//std::cout << "  [" << mouseX << ", " << mouseY << "]\n";
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	// SAMPLE CODE: print mouse position
	//const float mouseX{ float(e.x) };
	//const float mouseY{ float(e.y) };
	//std::cout << "  [" << mouseX << ", " << mouseY << "]\n";

	// SAMPLE CODE: check which mouse button was pressed
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//	//std::cout << "Left mouse button released\n";
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

#pragma endregion ownDefinitions