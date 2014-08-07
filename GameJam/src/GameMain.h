#pragma once
#include <memory>
#include "Player.h"

class GameMain
{
public:
	GameMain();
	~GameMain(){}
	

	std::unique_ptr<CPlayer> Player;

	void Draw();
	void Update();
	void Main();
};


extern GameMain *GM;

