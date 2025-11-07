#include "pch.h"
#include "Game.h"

float increment{ 1.f };

//Basic game functions
#pragma region gameFunctions											
void Start()
{
}

void Draw()
{
	ClearBackground();

	DrawSky();
	DrawSun();
	DrawSea();
	DrawStars();
	DrawPlane();
	DrawClouds();

}

void Update(float elapsedSec)
{

	g_WaveOffset += .5f * elapsedSec;
	g_Offset += increment * elapsedSec;
	if (int(g_Offset) == 23 || int(g_Offset) == -1)
		increment *= -1;

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
	//g_MousePos = Point2f(float(e.x), float(e.y));
	// SAMPLE CODE: print mouse position
	//const float mouseX{ float(e.x) };
	//const float mouseY{ float(e.y) };
	//std::cout << "  [" << mouseX << ", " << mouseY << "]\n";
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	g_MousePos = Point2f(float(e.x), float(e.y));

	g_Clouds.push_back(Cloud(g_MousePos));
	std::cout << g_MousePos.x << " clouds size : " << g_Clouds.size() << std::endl;

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

static float quad(float base, float flat, float exp = 2.f) {
	return pow(base, exp) / flat;
}

void DrawSky() {
	SetColor(0.741f - quad(g_Offset, 500), 0.847f - quad(g_Offset, 600), 1 - quad(g_Offset, 1000), 1.f);
	FillRect(0.f, 0.f, g_WindowWidth, g_WindowHeight);
}

void DrawStars() {
	const Point2f win{ g_WindowWidth, g_WindowHeight };
	const float size{ 4.f };
	SetColor(1.f, 1.f, 1.f, 0.f + quad(g_Offset, 250));

	// stars from top to bottom
	FillRect(win.x / 1.5f, win.y / 15, size, size);
	FillRect(win.x / 7, win.y / 9, size, size);
	FillRect(win.x / 3.3f, win.y / 6, size, size);
	FillRect(win.x / 1.2f, win.y / 5.2f, size, size);
	FillRect(win.x / 2.3f, win.y / 4, size, size);
	FillRect(win.x / 5, win.y / 3.5f, size, size);
	FillRect(win.x / 3, win.y / 3, size, size);
	FillRect(win.x / 1.3f, win.y / 2, size, size);
	FillRect(win.x / 1.1f, win.y / 1.8f, size, size);
	FillRect(win.x / 9, win.y / 1.7f, size, size);
}

void DrawSun() {
	SetColor(1.f - quad(g_Offset, 1000), 0.8f - quad(g_Offset, 500), 0.f);
	const Point2f start{ g_WindowWidth / 2 , g_WindowHeight / 2 + g_Offset * 10 };
	const float radius{ 75.f };
	FillEllipse(start, radius, radius);
}

void DrawWave(Wave wave) {

	SetColor(wave.color);
	float segmentLength{ 5.f };


	for (float i = 0.f; i < g_WindowWidth; i++) {
		float waveMove{ cosf(i / 10 + g_WaveOffset * wave.speed) };
		if (wave.dir) waveMove = cosf(i / 10 - g_WaveOffset * wave.speed);

		FillRect(
			wave.start.x + segmentLength * i,
			wave.start.y + waveMove * wave.magnitude,
			segmentLength,
			wave.height
		);
	}
} // multiplying wave instead of adding it in drawLine will do the spring (boooing)

void DrawSea() {
	Wave
		whiteWave(Color4f(1.f, 1.f, 1.f, 1.f), Point2f(0.f, g_WindowHeight * 2.f / 3), 1, 1.f),
		lightBlueWave(Color4f(0.6f, 0.85f, 1.f, 1.f), Point2f(0.f, g_WindowHeight * 2.1f / 3), 0, 1.2f),
		medBlueWave(Color4f(0.3f, 0.7f, 0.9f, 1.f), Point2f(0.f, g_WindowHeight * 2.3f / 3), 1, 2.f),
		blueWave(Color4f(0.071f, 0.365f, 0.659f, 1.f), Point2f(0.f, g_WindowHeight * 2.55f / 3), 0, 2.f);

	DrawWave(whiteWave);
	DrawWave(lightBlueWave);
	DrawWave(medBlueWave);
	DrawWave(blueWave);
}

void DrawPlane() {
	Point2f start{ float(int(g_WaveOffset * 100) % int(g_WindowWidth)), g_WindowHeight / 7 };
	float w = { 35.f };
	float h = { 15.f };

	SetColor(1.f, 0.f, 0.f);
	FillTriangle(start.x - w / 6, start.y, start.x + w * 2 / 3, start.y + h / 2, start.x - w / 6, start.y + h); // reactor

	SetColor(.9f, 0.9f, .9f);
	FillRect(start.x, start.y, w, h); // capsule

	SetColor(1.f, 0.f, 0.f);
	FillTriangle(start.x + w, start.y, start.x + w * 1.5f, start.y + h / 2, start.x + w, start.y + h); // pointe
	FillTriangle(start.x, start.y, start.x, start.y - h / 2, start.x + w / 3, start.y); // top wing
	FillTriangle(start.x, start.y + h, start.x, start.y + h * 1.5f, start.x + w / 3, start.y + h); // bottom wing

	SetColor(1.f, 0.75f, 0.3f);
	FillEllipse(start.x + w * 5 / 6, start.y + h / 2, w / 10, w / 10); // hublo
}

void DrawCloud(Point2f start) {
	std::cout << start.x << ", y : " << start.y << std::endl;

	Cloud cloud = Cloud(start);
	cloud.Draw();
}

void DrawClouds() {
	for (int i = 0; i < g_Clouds.size(); i++) {
		if (g_Clouds[i].start.x >= 0)
			g_Clouds[i].Draw();
	}
}

#pragma endregion ownDefinitions