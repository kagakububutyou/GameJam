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

	shotLR = 0;
	shotflag = 0;
	shot_x = x;
	shot_y = y + height / 2;
	shotwidth = 20;
	shotheight = 20;
	shotcount = 120;
}



void CEnemy2::Move()
{
	y += Velocity_y;
	if (y < -Window::HEIGHT / 2 + Margin)
	{
		y -= Velocity_y;
	}

	Velocity_y = -3.8f;



}
void CEnemy2::Attack()
{
	if (app_env->isPressKey(GLFW_KEY_UP))
	{
		shotflag = 1;
	}

	if (shotflag == 1){
		if (GM->Enemy2->x > GM->Player->x){
			shotLR = 1;   //shot_x -= 5;
		}
		else
		{
			shotLR = 2;	//shot_x += 5;
		}

	}
	if (shotLR == 1)
		shot_x -= 5;

	if (shotLR == 2)
		shot_x += 5;

	if (shotflag == 1)
		drawFillBox(shot_x, shot_y, shotwidth, shotheight, Color(1, 0, 0, 1));

	if (shot_x < -Window::WIDTH / 2 || shot_x > Window::WIDTH / 2){
		shotflag = 0;
		shot_x = x;
		shot_y = y + height / 2;
	}

	if (Collision::IsHit(GM->Enemy2->shot_x, GM->Enemy2->shot_y, GM->Enemy2->shotwidth, GM->Enemy2->shotheight, GM->Enemy->x, GM->Enemy->y, GM->Enemy->width, GM->Enemy->height))
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
	Attack();

}