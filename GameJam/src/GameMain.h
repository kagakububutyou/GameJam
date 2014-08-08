#pragma once
#include <memory>
#include "Player.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Boss.h"
#include "OBJECT.h"

class GameMain
{
public:
	GameMain();
	~GameMain(){}
	

	std::unique_ptr<COBJECT> Player;
	std::unique_ptr<COBJECT> Enemy;
	std::unique_ptr<COBJECT> Enemy2;
	std::unique_ptr<COBJECT> Boss;

	void Draw();
	void Update();
	void Main();
};


extern GameMain *GM;

