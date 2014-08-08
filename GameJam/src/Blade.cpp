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
	
	if (GM->Player->Speed > 0)
	{
		x = GM->Player->x + GM->Player->width;
	}
	if (GM->Player->Speed < 0)
	{
		x = GM->Player->x - GM->Player->width;
	}
		
	y = GM->Player->y + GM->Player->height/2;
}

void CBlade::Update()
{
	//Collision();
	Move();
}
void CBlade::Draw()
{
	drawFillBox(x, y, width, height, color);
}