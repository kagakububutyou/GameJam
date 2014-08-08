#include "lib\appEnv.hpp"

#include "Boss.h"
#include "main.h"
#include "GameMain.h"
#include "Collision.h"



CBoss::CBoss()
{
	width = 48;
	height = 96;
	x = 200;
	y = 200;
	Velocity_x = 0;
	Velocity_y = 0;
	Speed = 5;

	color = Color(0, 0, 1, 1);
}

void CBoss::Move()
{
	y += Velocity_y;
	if (y < -Window::HEIGHT / 2 + height)
	{
		y -= Velocity_y;
	}

	Velocity_y = -3.8f;
}
void CBoss::Collision()
{
	if (Collision::IsHit(GM->Boss->x, GM->Boss->y, GM->Boss->width, GM->Boss->height, GM->Player->x, GM->Player->y, GM->Player->width, GM->Player->height))
	{
		color = Color(0, 1, 0, 1);
	}
	else
	{
		color = Color(0, 0, 1, 1);
	}
}
void CBoss::Update()
{
	Collision();
	Move();
}
void CBoss::Draw()
{
	drawFillBox(x, y, width, height, color);
}