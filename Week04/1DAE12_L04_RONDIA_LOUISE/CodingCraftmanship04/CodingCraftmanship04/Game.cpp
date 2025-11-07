#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											


//			SPACE SNAAAAAAAKE
//		             ____
//		            / . .\
//		            \  ---<
//		             \  /
//		   __________/ /
//  	-_/___________/
// 
//		----------------
//	Press W to enable or disable walls
//	If you die, press any non directional key to restart
//		----------------

void Start()
{
	if (!g_IsGameOver)
	{
		StartMessage();
	}

	LoadTextures();
	InitGalaxy();
	g_Score = 0;
	g_Start = RandomMidPos();
	g_Snake = Snake();
	g_Fruit.notEaten = Out();
	g_Fruit.eaten = Out();
	g_IsGameOver = false;
}

void Draw()
{
	ClearBackground(g_MidnightBlue.r, g_MidnightBlue.g, g_MidnightBlue.b);

	DrawGalaxy();

	if (g_WallsEnabled)
		DrawWalls();

	if (g_BoostVisible)
		DrawBoost();

	DrawFruit();
	DrawSnake();

	if (g_IsGameOver)
		DrawGameOver();
}

void Update(float elapsedSec)
{
	g_Snake.CheckDeath();
	if (g_Snake.isDead || g_IsGameOver) {
		GameOver();
		return;
	}

	UpdateGalaxy(elapsedSec);
	UpdateSnake(elapsedSec);

	if (g_Fruit.notEaten.IsOut() && floor(g_Time) > 1.f)
		AddFruit();
	if (!g_Fruit.notEaten.IsOut() && g_Snake.pos[0] == g_Fruit.notEaten)
		EatFruit();

	if (g_BoostCooldown > 5.f)
		AddBoost();
	else if (g_BoostCooldown > -7.f)
		RemoveBoost();

	if (g_BoostVisible && g_Snake.pos[0] == g_Boost)
		ActivateBoost();
	if (g_BoostOn && g_BoostEffectTime > 5.f)
		DeactivateBoost();

	g_PosTime += elapsedSec;
	g_Time += elapsedSec;
	g_BoostCooldown += elapsedSec;
	g_BoostEffectTime += elapsedSec;
}

void End()
{
}
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{
}

bool IsDirectionKey(SDL_Keycode key) {
	return key == SDLK_LEFT || key == SDLK_RIGHT || key == SDLK_UP || key == SDLK_DOWN;
}

void OnKeyUpEvent(SDL_Keycode key)
{
	// Restart game by pressing any non-directional key
	if (g_IsGameOver && !IsDirectionKey(key))
		Start();
	else if (g_IsGameOver)
		return;

	if (key == SDLK_LEFT && g_Snake.dir != g_Dirs.right)
		g_Snake.dir = g_Dirs.left;
	else if (key == SDLK_UP && g_Snake.dir != g_Dirs.down)
		g_Snake.dir = g_Dirs.up;
	else if (key == SDLK_RIGHT && g_Snake.dir != g_Dirs.left)
		g_Snake.dir = g_Dirs.right;
	else if (key == SDLK_DOWN && g_Snake.dir != g_Dirs.up)
		g_Snake.dir = g_Dirs.down;

	if (key == SDLK_w && !g_WallsEnabled)
		EnableWalls();
	else if (key == SDLK_w && g_WallsEnabled)
		DisableWalls();
	g_PosTime = 0.11f;
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

void StartMessage() {
	std::cout << R"(
     SPACE SNAAAAAAKE
	     ____
	    / . .\
	    \  ---<
	     \  /
   __________/ /
-_/___________/
	)" << std::endl;

	std::cout << "\n--------------\n\n";
	std::cout << "Press W to enable or disable walls \n";
	std::cout << "If you die, press any non directional key to restart\n\n";
	std::cout << "--------------\n";
}

void LoadTextures() {
	TextureFromFile("./Resources/death.png", g_DeathTexture);
	TextureFromFile("./Resources/star_0.png", g_StarTexture[0]);
	TextureFromFile("./Resources/star_1.png", g_StarTexture[1]);
	TextureFromFile("./Resources/star_2.png", g_StarTexture[2]);
	TextureFromFile("./Resources/star_3.png", g_StarTexture[3]);
}

Coord2i RandomPosInGrid() {
	return Coord2i{
		rand() % (g_GridWidth - 2) + 1,
		rand() % (g_GridHeight - 2) + 1
	};
}

Coord2i RandomMidPos() {
	return Coord2i{
		rand() % (g_GridWidth - 10) + 5,
		rand() % (g_GridHeight - 10) + 5
	};
}

void DrawSnake() {
	float offset{ };

	for (size_t i = 0; i < g_Snake.length; i++) {
		offset = 0.f;
		if (!g_Fruit.eaten.IsOut() && g_Snake.pos[i] == g_Fruit.eaten)
			offset = 5.f;

		SetColor(g_BoostOn ? g_SlateBlueTrans : g_SlateBlue);
		FillRect(
			g_Snake.pos[i].x * g_TileSizef - offset,
			g_Snake.pos[i].y * g_TileSizef - offset,
			g_TileSizef + 2 * offset,
			g_TileSizef + 2 * offset
		);

		SetColor(g_BoostOn ? g_SlateBlueTrans : g_SlateBlue);
		DrawRect(
			g_Snake.pos[i].x * g_TileSizef - offset,
			g_Snake.pos[i].y * g_TileSizef - offset,
			g_TileSizef + 2 * offset,
			g_TileSizef + 2 * offset,
			2.f
		);
	}

	SetColor(1.f, 1.f, 1.f);
	FillEllipse(g_Snake.pos[0].x * g_TileSizef + g_TileSizef / 2, g_Snake.pos[0].y * g_TileSizef + g_TileSizef / 2, 5.f, 5.f);
	SetColor(0.f, 0.f, 0.f);
	FillEllipse(g_Snake.pos[0].x * g_TileSizef + g_TileSizef / 2, g_Snake.pos[0].y * g_TileSizef + g_TileSizef / 2, 3.f, 3.f);
	DrawTongue();
}

void UpdateSnake(float elapsedSec) {
	if (!g_IsGameOver && g_PosTime > 0.1f) {
		g_Snake.Move();
		g_PosTime = 0.f;
	}
}

// kinda looks like a beak but maybe it's a space duck
void DrawTongue() {
	Point2f c1{}, c2{};

	c1.x = g_Snake.pos[0].x + .5f + (g_Snake.dir.x == 0 ? 0.0f : g_Snake.dir.x * 0.5f);
	c2.x = g_Snake.pos[0].x + 0.5f + (g_Snake.dir.x == 0 ? 0.0f : g_Snake.dir.x * 1.0f);
	c1.y = g_Snake.pos[0].y + 0.5f + (g_Snake.dir.y == 0 ? 0.0f : g_Snake.dir.y * 0.5f);
	c2.y = g_Snake.pos[0].y + 0.5f + (g_Snake.dir.y == 0 ? 0.0f : g_Snake.dir.y * 1.0f);

	c1.x *= g_TileSizef;
	c1.y *= g_TileSizef;
	c2.x *= g_TileSizef;
	c2.y *= g_TileSizef;

	SetColor(g_Pink);
	DrawLine(c1, c2, 4.f);
}

// Actually now the fruit is a star, but it can be seen as a fruit ? Since space snake eats it
void DrawFruit() {
	SetColor(g_Orange);

	if (!g_Fruit.notEaten.IsOut()) {
		const Rectf	srcRect{ 0.f, 0.f, g_StarTexture[g_StarIndex].width, g_StarTexture[g_StarIndex].height };
		const Rectf	dstRect{ g_Fruit.notEaten.x * g_TileSizef, g_Fruit.notEaten.y * g_TileSizef, g_TileSizef, g_TileSizef };
		DrawTexture(g_StarTexture[g_StarIndex], dstRect, srcRect);
	}
}

void	AddFruit() {
	g_Fruit.notEaten = RandomPosInGrid();
}

void	EatFruit() {
	++g_Score;
	g_Fruit.eaten = g_Fruit.notEaten;
	g_Fruit.notEaten = Out();
	g_StarIndex = rand() % 4;
}

bool	DeleteFruit(const Coord2i& position) {
	if (!g_Fruit.eaten.IsOut() && position == g_Fruit.eaten) {
		g_Fruit.eaten = Out();
	}
}

void DrawBoost() {
	const float cycle{ std::fmod(g_Time, 0.4f) };
	const float offset{ 5.f };

	SetColor(cycle < 0.2f ? g_Mint : g_MayaBlue);
	FillTriangle(
		g_Boost.x * g_TileSizef + (g_TileSizef / 2), g_Boost.y * g_TileSizef + offset,
		g_Boost.x * g_TileSizef + offset, g_Boost.y * g_TileSizef + g_TileSizef - offset,
		g_Boost.x * g_TileSizef + g_TileSizef - offset, g_Boost.y * g_TileSizef + g_TileSizef - offset
	);

}

void AddBoost() {
	g_BoostVisible = true;
	g_Boost = RandomPosInGrid();
	g_BoostCooldown = -10.f;
}
void RemoveBoost() {
	g_BoostVisible = false;
}

void ActivateBoost() {
	g_BoostVisible = false;
	g_BoostOn = true;
	g_BoostEffectTime = 0.f;
}

void DeactivateBoost() {
	g_BoostOn = false;
}


Point2f	RandomPoint2f() {
	return Point2f{ float(rand() % int(g_WindowWidth)), float(rand() % int(g_WindowHeight)) };
}

void InitGalaxy() {
	for (int i = 0; i < 500; i++) {
		const float		size = float(rand()) / RAND_MAX * 4.f;
		const Point2f	pos = RandomPoint2f();

		g_GalaxyStars[i] = Rectf{ pos.x, pos.y, size, size };
	}
}

static Point2f getDirStrength(float x, float y) {
	const float	winW = g_WindowWidth / 2;
	const float	winH = g_WindowHeight / 2;

	const float	distX{ x - winW };
	const float	distY{ y - winH };

	const float	forceX{ distX / winW };
	const float	forceY{ distY / winH };
	return Point2f(forceX * 2.f, forceY * 2.f);
}

void UpdateGalaxy(float elapsedSec) {
	for (int i = 0; i < 500; i++) {
		const Point2f dir = getDirStrength(g_GalaxyStars[i].left, g_GalaxyStars[i].top);
		g_GalaxyStars[i].left += elapsedSec * 75 * dir.x;
		g_GalaxyStars[i].top += elapsedSec * 75 * dir.y;
		g_GalaxyStars[i].width += 3.f / (g_WindowWidth / 2);
		g_GalaxyStars[i].height += 3.f / (g_WindowHeight / 2);

		if (g_GalaxyStars[i].top < 0 || g_GalaxyStars[i].top > g_WindowHeight
			|| g_GalaxyStars[i].left < 0 || g_GalaxyStars[i].left > g_WindowWidth
			|| g_GalaxyStars[i].width > 5.f) {
			const Point2f pos{ RandomPoint2f() };
			g_GalaxyStars[i] = Rectf{ pos.x, pos.y, 1.f, 1.f };
		}
	}
}

void DrawGalaxy() {

	for (int i = 0; i < 500; i++) {
		// fade out if star is too big
		const float	alpha{ g_GalaxyStars[i].width > 4.f ? (0.5f - (g_GalaxyStars[i].width - 4) / 2) : 0.5f };

		SetColor(1.f, 1.f, 1.f, alpha);
		FillRect(g_GalaxyStars[i].left, g_GalaxyStars[i].top, g_GalaxyStars[i].width, g_GalaxyStars[i].height);
	}
}

void	DrawWalls() {
	for (int i = 0; i < g_GridWidth; i++) {
		SetColor(g_SlateBlue);
		FillRect(i * g_TileSizef, 0, g_TileSizef, g_TileSizef);
		FillRect(i * g_TileSizef, g_WindowHeight - g_TileSizef, g_TileSizef, g_TileSizef);

		SetColor(g_Mint);
		DrawRect(i * g_TileSizef, 0, g_TileSizef, g_TileSizef, 2.f);
		DrawRect(i * g_TileSizef, g_WindowHeight - g_TileSizef, g_TileSizef, g_TileSizef, 2.f);
	}
	for (int i = 0; i < g_GridHeight; i++) {
		SetColor(g_SlateBlue);
		FillRect(0, i * g_TileSizef, g_TileSizef, g_TileSizef);
		FillRect(g_WindowWidth - g_TileSizef, i * g_TileSizef, g_TileSizef, g_TileSizef);

		SetColor(g_Mint);
		DrawRect(0, i * g_TileSizef, g_TileSizef, g_TileSizef, 2.f);
		DrawRect(g_WindowWidth - g_TileSizef, i * g_TileSizef, g_TileSizef, g_TileSizef, 2.f);
	}
}

void	EnableWalls() {
	g_WallsEnabled = true;
}

void	DisableWalls() {
	g_WallsEnabled = false;
}

void GameOver() {
	if (!g_IsGameOver) {
		std::cout << "\nGame Over :(\nScore : " << g_Score << std::endl;
		g_IsGameOver = true;
		RemoveBoost();
		DeleteFruit();
	}
}

void	DrawGameOver() {
	SetColor(.8f, .8f, .8f, 0.65f);
	FillRect(0.f, 0.f, g_WindowWidth, g_WindowHeight);

	const Point2f pos{
		(g_WindowWidth - g_DeathTexture.width) / 2,
		(g_WindowHeight - g_DeathTexture.height) / 2
	};
	DrawTexture(g_DeathTexture, pos);
}


#pragma endregion ownDefinitions