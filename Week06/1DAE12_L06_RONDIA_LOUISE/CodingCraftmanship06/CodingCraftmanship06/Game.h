#pragma once
#include <utils.h>
using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 600 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

const float MIN_BOUNCE_SPEED = 5.0f;
const float HOR_FRICTION = 0.95f;

const float	g_Gravity{ 600.f };

const Color4f	g_Blue{ 0.4f, 0.5f, 0.9f, 1.f };
const Color4f	g_Orange{ 0.9f, 0.7f, 0.4f, 1.f };
const Color4f	g_Grey{ 0.9f, 0.9f, 0.9f, 1.f };
const Color4f	g_DarkGrey{ 0.6f, 0.6f, 0.6f, 1.f };

// strength of movements, so x is how fast it will move horizontally and y is how high/fast it will jump
const Point2f g_MovesVelocity{200.f, -350.f}; 
bool	g_MvtKeyPressed{};

const float g_GroundHeight{ 150.f };
const Color4f g_GroundColor{ g_DarkGrey };

Rectf g_Ground{ 0.f, g_WindowHeight - g_GroundHeight, g_WindowWidth, g_GroundHeight };


//portal

const float g_PortalWidth{ 30.f };
const float g_PortalHeight{ 60.f };

struct Portal
{
	float	width;
	float	height;
	Point2f	center;
	Color4f color;
	bool	isOn;
	int		id;
};

Portal g_BluePortal{ g_PortalWidth , g_PortalHeight, Point2f{}, g_Blue, false, 0 };
Portal g_OrangePortal{ g_PortalWidth , g_PortalHeight, Point2f{}, g_Orange, false, 1 };

// ball

Point2f	g_BallCenter{ g_WindowWidth / 2, g_WindowHeight / 2 };
Point2f	g_BallVelocity{ 0.f, 0.f };
Color4f	g_BallColor{ g_Grey };
Point2f	g_BallRadius{ 20.f, 20.f };
bool	g_IsBallFalling{};
bool	g_IsBallJumping{};

const float g_BallJumpOffset{ 10.f };
const float g_BallBounceCoef{ -0.3f };


// Declare your own functions here

// portals

void DrawPortal(Portal portal);
void DrawPortal(float width, float height, Point2f center, Color4f color);
void DrawPortals();

void UpdatePortalPosition(Portal& portal, Point2f newCenter);
void UpdatePortalPosition(Portal& portal, float newCenterX, float newCenterY);

// ball

void DrawBall();

void UpdateBallPosition(float elapsedSec);
void BallFalling(float elapsedSec);
bool BallTeleportation(Portal src, Portal dst);
void ApplyBallBounce();
bool IsBallInPortal(Portal portal);


// ground

bool isBallColliding();

void DrawBackGround();

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
