#include "Player.h"
#include "main.h"
#include "GameMain.h"
#include "lib\appEnv.hpp"

CPlayer::CPlayer() : Player1("res/SCN_0003 3A.png"),Player2("res/SCN_0003 3B.png")
{


	width = 128;
	height = 128;
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
		if (y < -Window::HEIGHT / 2 + Margin)
		{
			y -= Velocity_y;
			State = STATE::NORMAL;
		}
	}

	if (y < -Window::HEIGHT / 2 + Margin)
	{
		y -= Velocity_y;
	}

	//	‰E
	if (app_env->isPressKey(GLFW_KEY_RIGHT))
	{
		Speed = 5;
		Velocity_x = Speed;
	}
	//	¶
	else if (app_env->isPressKey(GLFW_KEY_LEFT))
	{
		Speed = -5;
		Velocity_x = Speed;
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
	if (Speed > 0)
	{
		drawTextureBox(x, y, width, height, 0, 0, 128, 128, Player2, Color(1, 1, 1));
	}
	if (Speed < 0)
	{
		drawTextureBox(x, y, width, height, 0, 0, 128, 128, Player1, Color(1, 1, 1));
	}

	if (app_env->isPressKey(GLFW_KEY_SPACE))
	{
		GM->Blade->Draw();
	}

}
void CPlayer::Update()
{
	Move();

}