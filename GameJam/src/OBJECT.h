#pragma once
#include "lib/appEnv.hpp"

class COBJECT
{
public:
	COBJECT(){}
	~COBJECT(){}

	float x;			//	座標
	float y;			//	座標
	float width;		//	幅
	float height;	//	高さ
	float Velocity_x;	//	速度
	float Velocity_y;	//	速度
	float Speed;

	const static int Margin = 32;	//	余白

	float shotLR;
	float shot_x;
	float shot_y;
	float shotcount;
	float shotflag;
	float shotwidth;
	float shotheight;

	Color color;	//	色

	virtual void Move(){}
	virtual void Draw(){}
	virtual void Update(){}
	virtual void Collision(){}
};

