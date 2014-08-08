#pragma once
#include <memory>
#include "Player.h"
#include "Enemy.h"
#include "OBJECT.h"

class GameMain
{
public:
	GameMain();
	~GameMain(){}
	

	std::unique_ptr<COBJECT> Player;
	std::unique_ptr<COBJECT> Enemy;

	void Draw();
	void Update();
	void Main();
};


extern GameMain *GM;

