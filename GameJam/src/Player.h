#pragma once
#include "OBJECT.h"
class CPlayer :public COBJECT
{
public:
	CPlayer();
	~CPlayer(){}

	void Mover();
	void Draw();
	void Update();

};

