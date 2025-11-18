#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	g_NormVect = Vector2f{ Normalize(g_NormVect) };

	std::cout << ToString(g_VectorA) << std::endl;
	std::cout << ToString(g_VectorB) << std::endl << std::endl;

	const Vector2f hor{ 50.f, 0.f }, ver{ 0.f, 50.f }, paraVer{ 0.f, 25.f }, paraVerCopy{ 0.f, 25.f };

	std::cout << "hor : " << ToString(hor) << "	ver : " << ToString(ver) << "	Dot Product : " << DotProduct(hor, ver) << std::endl;
	std::cout << "ver : " << ToString(ver) << "	paraVer : " << ToString(paraVer) << "	Dot Product : " << DotProduct(paraVer, ver) << std::endl << std::endl;

	std::cout << "hor : " << ToString(hor) << "	ver : " << ToString(ver) << "	Cross Product : " << CrossProduct(hor, ver) << std::endl;
	std::cout << "ver : " << ToString(ver) << "	hor : " << ToString(hor) << "	Cross Product : " << CrossProduct(ver, hor) << std::endl << std::endl;

	std::cout << "Length of hor : " << Length(hor) << std::endl;
	std::cout << "Length of vectorA : " << Length(g_VectorA) << std::endl << std::endl;

	std::cout << "Normalized of " << ToString(g_VectorA) << " : " << ToString(Normalize(g_VectorA)) << " its length is " << Length(Normalize(g_VectorA)) << std::endl;

	std::cout << "Angle between " << ToString(g_VectorA) << " and " << ToString(g_VectorB) << " is "
		<< AngleBetween(g_VectorA, g_VectorB) << " radians or " << (AngleBetween(g_VectorA, g_VectorB) * 180.f / g_Pi) << " degrees" << std::endl;

	std::cout << "Angle between " << ToString(hor) << " and " << ToString(ver) << " is "
		<< AngleBetween(hor, ver) << " radians or " << (AngleBetween(hor, ver) * 180.f / g_Pi) << " degrees" << std::endl;

	std::cout << ToString(paraVer) << " and " << ToString(paraVerCopy) << " are equal ? " << AreEqual(paraVer, paraVerCopy) << std::endl;
}

void Draw()
{
	ClearBackground();

	Point2f start{ g_WindowWidth / 2, g_WindowHeight / 2 };
	Point2f pos{ 600.f, 300.f };

	SetColor(0.f, 0.f, 1.f);
	DrawVector(g_VectorA);
	DrawVector(g_VectorB, Point2f{ g_VectorA.x, g_VectorA.y });
	SetColor(1.f, 0.f, 0.f);
	DrawVector(Add(g_VectorB, g_VectorA));

	SetColor(0.f, 0.f, 1.f);
	DrawVector(g_VectorA, pos);
	DrawVector(g_VectorB, pos);
	SetColor(1.f, 0.f, 0.f);
	DrawVector(Substract(g_VectorA, g_VectorB), pos);

	const Vector2f proj{ Scale(g_NormVect, DotProduct(g_VectorA, g_NormVect)) };

	SetColor(1.f, 1.f, 1.f);
	DrawVector(g_VectorA, start);
	SetColor(1.f, 0.f, 0.f);
	DrawVector(proj, start);
}

void Update(float elapsedSec)
{
	const float velocity{ 1.f }, radius{ 100.f };

	g_VectorA.x = cosf(g_Time) * radius;
	g_VectorA.y = sinf(g_Time) * radius;

	g_Time += elapsedSec * velocity;
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
// Define your own functions here

#pragma endregion ownDefinitions