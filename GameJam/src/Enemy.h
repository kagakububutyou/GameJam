#pragma once
#include "OBJECT.h"

class CEnemy :public COBJECT
{
public:
	CEnemy(float x);
	~CEnemy(){};

	void Move();
	void Draw();
	void Update();
	void Collision();

private:

};