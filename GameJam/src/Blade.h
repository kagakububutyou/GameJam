#pragma once
#include "OBJECT.h"

class CBlade :public COBJECT
{
public:
	CBlade();
	~CBlade(){};

	void Move();
	void Draw();
	void Update();
	//void Collision();

private:

};