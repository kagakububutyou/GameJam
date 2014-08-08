#include "Blade.h"
#include "main.h"
#include "GameMain.h"
#include "lib\appEnv.hpp"

CBlade::CBlade()
{
	width = 128;
	height = 32;
	x = 100;
	y = 100;
	Velocity_x = 0;
	Velocity_y = 0;
	Speed = 5;

	color = Color(1, 1, 1, 1);
}

void CBlade::Move()
{
	
	if (GM->Player->Speed > 0 && GM->Player->Rush == 0)
	{
		x = GM->Player->x + width + 32;
	}
	if (GM->Player->Speed < 0 && GM->Player->Rush == 0)
	{
		x = GM->Player->x - GM->Player->width;
	}
	
	if (GM->Player->Speed > 0 && GM->Player->Rush == 1)
	{
		x = GM->Player->x + GM->Player->width;
	}
	if (GM->Player->Speed < 0 && GM->Player->Rush == 1)
	{
		x = GM->Player->x - GM->Player->width;
	}
	y = GM->Player->y + GM->Player->height/2;

	if (app_env->isPushKey(GLFW_KEY_SPACE))
	{

	}
}

void CBlade::Update()
{
	//Collision();
	Move();
}
void CBlade::Draw()
{
	/*
	static int hoge = 90;
	if (GM->Player->Speed > 0)	hoge -= 15;
	if (GM->Player->Speed < 0)	hoge += 15;
	
	drawFillBox(x, y, width, height, color, 3.14 / 180 * hoge, Vec2f(1, 1), Vec2f(0, 0));

	if (hoge < -90)
	{
		hoge = 90;
	}
	*/
	drawFillBox(x, y, width, height, color);
}