#include "lib\appEnv.hpp"

#include "Enemy.h"
#include "main.h"
#include "GameMain.h"
#include "Collision.h"



CEnemy::CEnemy()
{
	width = 48;
	height = 96;
	x = 100;
	y = 100;
	Velocity_x = 0;
	Velocity_y = 0;
	Speed = 5;

	color = Color(1, 0, 0, 1);
}

void CEnemy::Move()
{
	y += Velocity_y;
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
	if (app_env->isPressKey(GLFW_KEY_SPACE))
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
}