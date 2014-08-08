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

	Color color;	//	色

	virtual void Move(){}
	virtual void Draw(){}
	virtual void Update(){}
	virtual void Collision(){}
};

