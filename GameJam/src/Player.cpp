#include "Player.h"
#include "main.h"
#include "lib\appEnv.hpp"

CPlayer::CPlayer()
{
	
	width = 48;
	height = 96;
	x = 100;
	y = (-Window::HEIGHT / 2 + height);
	Velocity_x = 0;
	Velocity_y = 0;
	Speed = 5;

	color = Color(1,1,1,1);
}
void CPlayer::Move()
{
	x += Velocity_x;
	y += Velocity_y;
	
	if (app_env->isPressKey(GLFW_KEY_UP) && State != STATE::JUNP)
	{
		force = 13;
		State = STATE::JUNP;
	}

	if (State == STATE::JUNP)
	{
		force--;
		y += force;
		if (y < -Window::HEIGHT / 2 + height)
		{
			y -= Velocity_y;
			State = STATE::NORMAL;
		}
	}

	if (y < -Window::HEIGHT/2 + height)
	{
		y -= Velocity_y;
	}

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
	Velocity_y = -3.8f;
}


void CPlayer::Draw()
{
	drawFillBox(x, y, width, height, color);

}
void CPlayer::Update()
{
	Move();

}