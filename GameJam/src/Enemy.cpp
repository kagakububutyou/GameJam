#include "lib\appEnv.hpp"

#include "Enemy.h"
#include "main.h"
#include "GameMain.h"
#include "Collision.h"



CEnemy::CEnemy(float x)
{
	width = 48;
	height = 96;
	this->x = x;
	y = (-Window::HEIGHT / 2 + height);
	MapX = this->x;
	Velocity_x = 0;
	Velocity_y = 0;
	Speed = 2;
	Direction = 0;

	color = Color(1, 0, 0, 1);
}

void CEnemy::Move()
{
	x = MapX - GM->Player->ScrollX;
	y += Velocity_y;
	MapX += Velocity_x;
	if (y < -Window::HEIGHT / 2 + Margin)
	{
		y -= Velocity_y;
	}
	/*
	if (GM->Enemy->x > GM->Player->x){
		Velocity_x = -Speed;;
		x = x + Velocity_x;
	}
	else
	{
		Velocity_x = Speed;;
		x = x + Velocity_x;
	}*/

	if (GM->Player->x + GM->Player->ScrollX - MapX < Window::WIDTH / 2 && GM->Player->x + GM->Player->ScrollX - MapX > -Window::WIDTH / 2)
	{
		if (MapX > GM->Player->x + GM->Player->ScrollX){
			Velocity_x = -Speed;
			//x = x + Velocity_x;
			Direction = 0;
			//color = Color(1, 1, 0, 1);
		}
		else 
		{
			Velocity_x = Speed;
			//x = x + Velocity_x;
			Direction = 1;
			//color = Color(0, 1, 1, 1);
		}
	}
	else
	{
		Velocity_x = 0;
	}
	//*/
	Velocity_y = -3.8f;
}
void CEnemy::Collision()
{
	
	if (Collision::IsHit(x, y,width, height, GM->Player->x, GM->Player->y, GM->Player->width, GM->Player->height))
	{
		color = Color(0, 1, 0, 1);
	}
	else
	{
		color = Color(1, 0, 0, 1);
	}
	if (app_env->isPushKey(GLFW_KEY_SPACE) || GM->Player->Rush == 1)
	{
		if (Collision::IsHit(x, y, width, height, GM->Blade->x, GM->Blade->y, GM->Blade->width, GM->Blade->height))
		{
  			color = Color(0, 0, 1, 1);
		}
	}
}
void CEnemy::Update()
{
	Collision();
	Move();
}
void CEnemy::Draw()
{
	drawFillBox(x, y, width, height, color);

	if (Direction == 0)
	{
		drawFillBox(x, y, width, height, color);
	}
	else
	{
		drawFillBox(x, y, width, height, color);
	}
}