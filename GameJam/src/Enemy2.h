#pragma once
#include "OBJECT.h"

class CEnemy2 : public COBJECT
{
public:
	CEnemy2();
	~CEnemy2(){};
	

	void Move();
	void Draw();
	void Update();
	void Collision();

	void Attack();

	//const float shot;

};

