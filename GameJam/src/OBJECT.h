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

	Color color;	//	�F


	virtual void Draw() = 0;
	virtual void Update() = 0;
};

