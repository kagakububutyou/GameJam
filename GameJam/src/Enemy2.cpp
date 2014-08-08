#include "lib\appEnv.hpp"
#include "lib\random.hpp"

#include "Enemy2.h"
#include "main.h"
#include "GameMain.h"
#include "Collision.h"

CEnemy2::CEnemy2()
{
	width = 25;
	height = 50;
	x = 300;
	y = (-Window::HEIGHT / 2 + height);;
	Velocity_x = 0;
	Velocity_y = 0;
	Speed = 2;

	color = Color(1, 0, 0, 1);

	//shot = 0;
}



void CEnemy2::Move()
{
	y += Velocity_y;
	if (y < -Window::HEIGHT / 2 + height)
	{
		y -= Velocity_y;
	}

	Velocity_y = -3.8f;



}

void CEnemy2::Collision()
{
	if (Collision::IsHit(GM->Enemy2->x, GM->Enemy2->y, GM->Enemy2->width, GM->Enemy2->height, GM->Player->x, GM->Player->y, GM->Player->width, GM->Player->height))
	{
		color = Color(0, 1, 0, 1);
	}
	else
	{
		color = Color(0, 0, 1, 1);
	}
}
void CEnemy2::Update()
{
	Collision();
	Move();
}
void CEnemy2::Draw()
{
	drawFillBox(x, y, width, height, color);

}