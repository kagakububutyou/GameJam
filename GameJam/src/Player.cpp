#include "Player.h"
#include "main.h"
#include "GameMain.h"
#include "lib\appEnv.hpp"

CPlayer::CPlayer() : Player1("res/stA.png"), Player2("res/stB.png"), Player3("res/tkA.png"), Player4("res/tkB.png")
{
	width = 128;
	height = 128;
	x = 0;
	ScrollX = x;
	y = (-Window::HEIGHT / 2 + height);
	Velocity_x = 0;
	Velocity_y = 0;
	Speed = 5;

	Rush = 0;

	Count = 0;

	color = Color(1,1,1,1);
}
void CPlayer::Move()
{

	if (ScrollX > 0)
	{
		ScrollX += Velocity_x;
	}
		
	if (ScrollX <= 0)
	{
		x += Velocity_x;
		ScrollX += x;
	}
		
	y += Velocity_y;

	if (app_env->isPushKey(GLFW_KEY_UP) && State != STATE::JUNP)
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
	if (app_env->isPressKey(GLFW_KEY_RIGHT) && !app_env->isPressKey(GLFW_KEY_LEFT) && x < Window::WIDTH / 2 - width)
	{
		Speed = 5;
		Velocity_x = Speed;
	}
	//	¶
	else if (app_env->isPressKey(GLFW_KEY_LEFT) && !app_env->isPressKey(GLFW_KEY_RIGHT) && x > -Window::WIDTH / 2)
	{
		Speed = -5;
		Velocity_x = Speed;
	}
	else
	{
		Velocity_x = 0;
	}
	Velocity_y = -3.8f;

	//	‰å“Ë
	int Old_x = 0;
	if (app_env->isPressKey(GLFW_KEY_SPACE))
	{
		Count++;
		
	}
	if (app_env->isPullKey(GLFW_KEY_SPACE))
	{
		if (Count >= 120)
		{
			Rush = 1;
			Old_x = x;
		}
	}
	if (Rush == 1)
	{
		Velocity_x = Speed * 3;

		Count--;
		//if (Old_x + Window::WIDTH / 4 < x && Speed > 0 || Old_x - Window::WIDTH / 4 - width > x && Speed < 0)
		if (width-Window::WIDTH / 2 > x || Count <= 0)
		{
			Velocity_x = 0;
			Rush = 0;
		}
	}
		
}


void CPlayer::Draw()
{
	
	//drawFillBox(x, y, width, height, color);
	if (Speed > 0 && Rush == 0)
	{
		drawTextureBox(x, y, width, height, 0, 0, 128, 128, Player2, Color(1, 1, 1));
	}
	if (Speed < 0 && Rush == 0)
	{
		drawTextureBox(x, y, width, height, 0, 0, 128, 128, Player1, Color(1, 1, 1));
	}
	if (Speed > 0 && Rush == 1)
	{
		drawTextureBox(x, y, width * 2, height, 0, 0, 256, 128, Player4, Color(1, 1, 1));
	}
	if (Speed < 0 && Rush == 1)
	{
		drawTextureBox(x, y, width * 2, height, 0, 0, 256, 128, Player3, Color(1, 1, 1));
	}
	if (app_env->isPushKey(GLFW_KEY_SPACE))
	{
		GM->Blade->Draw();
	}

}
void CPlayer::Update()
{
	Move();

}