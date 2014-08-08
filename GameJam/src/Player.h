#pragma once
#include "OBJECT.h"
class CPlayer :public COBJECT
{
	float force;
	float Count;
public:
	CPlayer();
	~CPlayer(){}

	Texture Player1;
	Texture Player2;
	Texture Player3;
	Texture Player4;

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

