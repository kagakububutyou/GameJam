#include "lib\appEnv.hpp"
#include "lib\random.hpp"

#include "Enemy2.h"
#include "main.h"
#include "GameMain.h"
#include "Collision.h"

CEnemy2::CEnemy2(float x)
{
	width = 48;
	height = 96;
	this->x = x;
	y = (-Window::HEIGHT / 2 + height);
	MapX = this->x;
	Velocity_x = 0;
	Velocity_y = 0;
	Speed = 2;

	color = Color(1, 0, 0, 1);

	Direction = 0;
	shotflag = 0;
	shot_x = x;
	shot_y = y + height / 2;
	shotwidth = 20;
	shotheight = 20;
	shotcount = 120;
}



void CEnemy2::Move()
{
	x = MapX - GM->Player->ScrollX;
	y += Velocity_y;
	if (y < -Window::HEIGHT / 2 + Margin)
	{
		y -= Velocity_y;
	}

	Velocity_y = -3.8f;

	if (x > GM->Player->x){
		Direction = 0;
		//color = Color(1, 1, 0, 1);
	}
	else
	{
		Direction = 1;
		//color = Color(0, 1, 1, 1);
	}


}
void CEnemy2::Attack()
{
	if (app_env->isPressKey(GLFW_KEY_UP))
	{
		shotflag = 1;
	}

	if (shotflag == 1){
		if (x > GM->Player->x){
			Direction = 1;   //shot_x -= 5;
		}
		else
		{
			Direction = 2;	//shot_x += 5;
		}

	}
	if (Direction == 1)
		shot_x -= 5;

	if (Direction == 2)
		shot_x += 5;

	if (shotflag == 1)
		drawFillBox(shot_x, shot_y, shotwidth, shotheight, Color(1, 0, 0, 1));

	if (shot_x < -Window::WIDTH / 2 || shot_x > Window::WIDTH / 2){
		shotflag = 0;
		shot_x = x;
		shot_y = y + height / 2;
	}

	for (auto &i : GM->enemy)
	{
		if (Collision::IsHit(shot_x, shot_y, shotwidth, shotheight, i->x, i->y, i->width, i->height))
		{
			color = Color(0, 0, 1, 1);
			shotflag = 0;
			shot_x = x;
			shot_y = y + height / 2;
		}
		else
		{
			color = Color(0, 0, 1, 1);
		}
	}

}
void CEnemy2::Collision()
{
	if (Collision::IsHit(x, y,width,height, GM->Player->x, GM->Player->y, GM->Player->width, GM->Player->height))
	{
		color = Color(0, 1, 0, 1);
	}
	else
	{
		color = Color(0, 0, 1, 1);
	}
	if (app_env->isPressKey(GLFW_KEY_SPACE))
	{
		if (Collision::IsHit(x, y, width, height, GM->Blade->x, GM->Blade->y, GM->Blade->width, GM->Blade->height))
		{
			color = Color(1, 0, 1, 1);
		}
	}
}
void CEnemy2::Update()
{
	Collision();
	Move();
}
void CEnemy2::Draw()
{
	if (Direction == 0)
	{
		drawFillBox(x, y, width, height, color);
	}
	else
	{
		drawFillBox(x, y, width, height, color);
	}
	Attack();

}