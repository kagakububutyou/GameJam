#pragma once
#include "OBJECT.h"
class CPlayer :public COBJECT
{
	float force;
public:
	CPlayer();
	~CPlayer(){}

	enum STATE
	{
		NORMAL,
		JUNP,

	};

	STATE State;

	void Move();
	void Draw();
	void Update();
	//void Collision();

};

