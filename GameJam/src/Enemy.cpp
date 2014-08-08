#include "lib\appEnv.hpp"
#include "lib\random.hpp"

#include "Enemy.h"
#include "main.h"
#include "GameMain.h"
#include "Collision.h"



CEnemy::CEnemy()
{
	width = 16;
	height = 32;
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
	if (y < -Window::HEIGHT / 2 + height)
	{
		y -= Velocity_y;
	}

	Velocity_y = -3.8f;
}
void CEnemy::Collision()
{
	if (Collision::IsHit(GM->Enemy->x, GM->Enemy->y, GM->Enemy->width, GM->Enemy->height, GM->Player->x, GM->Player->y, GM->Player->width, GM->Player->height))
	{
		color = Color(0, 1, 0, 1);
	}
	else
	{
		color = Color(1, 0, 0, 1);
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