#include "Player.h"
#include "main.h"
#include "lib\appEnv.hpp"

CPlayer::CPlayer()
{
	x = 100;
	y = 100;
	width = 16;
	height = 32;
	Velocity_x = 0;
	Speed = 5;

	color = Color(1,1,1,1);
}
void CPlayer::Mover()
{
	x += Velocity_x;
	
	//	‰E
	if (app_env->isPressKey(GLFW_KEY_RIGHT))
	{
		Velocity_x = Speed;
	}
	//	¶
	else if (app_env->isPressKey(GLFW_KEY_LEFT))
	{
		Velocity_x = -Speed;
	}
	else
	{
		Velocity_x = 0;
	}
}


void CPlayer::Draw()
{
	drawFillBox(x, y, width, height, color);

}
void CPlayer::Update()
{
	Mover();

}