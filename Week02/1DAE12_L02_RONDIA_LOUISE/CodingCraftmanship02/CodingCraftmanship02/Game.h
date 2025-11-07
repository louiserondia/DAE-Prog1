#pragma once
#include <utils.h>
#include <iostream>

using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "Coding Craftmanship 02 - Rondia, Louise - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 1080 };
float g_WindowHeight{ 720 };
#pragma endregion gameInformation


#pragma region ownDeclarations
// Declare your own global variables here

class CloudShape {
public:
	Rectf base{};
	Ellipsef leftCircle{};
	Ellipsef middleCircle{};
	Ellipsef rightCircle{};

	Point2f start;
	const float segment{ 20.f };
	CloudShape(Point2f);
};

CloudShape::CloudShape(Point2f start) : start(start) {
	base = Rectf(start.x - segment * 1.6f, start.y + segment * 0.5f, segment * 3.5f, segment);
	leftCircle = Ellipsef(start.x - segment * 1.5f, start.y + segment * 0.7f, segment * 0.8f, segment * 0.8f);
	middleCircle = Ellipsef(start, segment * 1.4f, segment * 1.4f);
	rightCircle = Ellipsef(start.x + segment * 1.8f, start.y + segment / 2, segment * 1.f, segment * 1.f);
}


class Cloud {
public:
	Color4f color;
	Point2f start;
	float size;
	const CloudShape shape;

	Cloud(Point2f, float, Color4f);
	void Draw();
};

Cloud::Cloud(Point2f start = Point2f(-1.f, -1.f), float size = 1.f, Color4f color = Color4f(0.85f, 0.85f, 0.85f, 1.f)) :
	start(start), size(size), color(color), shape(CloudShape(start)) {
}

void Cloud::Draw() {
	SetColor(color);
	FillRect(shape.base);
	FillEllipse(start, shape.segment * 1.4f, shape.segment * 1.4f);
	FillEllipse(start.x + shape.segment * 1.8f, start.y + shape.segment / 2, shape.segment * 1.f, shape.segment * 1.f);
	FillEllipse(start.x - shape.segment * 1.5f, start.y + shape.segment * 0.7f, shape.segment * 0.8f, shape.segment * 0.8f);
}

class Wave {
public:
	Color4f	color;
	Point2f start;
	bool	dir;
	float	speed;
	float	height;
	float	magnitude;

	Wave(Color4f, Point2f, bool, float, float, float);
};

Wave::Wave(
	Color4f color = Color4f(1.f, 1.f, 1.f, 1.f),
	Point2f start = Point2f(0.f, 0.f),
	bool dir = 0,
	float speed = 1.f,
	float magnitude = 30.f,
	float height = 300.f) :
	color(color), start(start), dir(dir), speed(speed), magnitude(magnitude), height(height) {
}

std::vector<Cloud> g_Clouds{};

Point2f g_MousePos{};
float g_Offset{0.0f};
float g_WaveOffset{.5f};

// Declare your own functions here

void DrawSea();
void DrawWave(Wave wave);
void DrawSun();
void DrawSky();
void DrawStars();
void DrawCloud(Point2f start);
void DrawClouds();
void DrawPlane();

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
