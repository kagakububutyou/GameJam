#pragma once
#include "OBJECT.h"

class CBoss :public COBJECT
{
public:
	CBoss();
	~CBoss(){};

	void Move();
	void Draw();
	void Update();
	void Collision();

private:

};