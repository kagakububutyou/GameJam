#pragma once
#include "lib/appEnv.hpp"

class COBJECT
{
public:
	COBJECT(){}
	~COBJECT(){}

	float x;			//	���W
	float y;			//	���W
	float width;		//	��
	float height;	//	����
	float Velocity_x;	//	���x
	float Velocity_y;	//	���x
	float Speed;

	const static int Margin = 32;	//	�]��

	float shotLR;
	float shot_x;
	float shot_y;
	float shotcount;
	float shotflag;
	float shotwidth;
	float shotheight;

	Color color;	//	�F

	virtual void Move(){}
	virtual void Draw(){}
	virtual void Update(){}
	virtual void Collision(){}
};

