#pragma once
#include <memory>
#include <vector>
#include "OBJECT.h"
#include "lib\appEnv.hpp"

class GameMain
{
public:
	GameMain();
	~GameMain(){}
	
	Texture hoge;
	Texture floor;

	std::unique_ptr<COBJECT> Player;
	std::unique_ptr<COBJECT> Blade;
	//std::unique_ptr<COBJECT> Enemy;
	//std::unique_ptr<COBJECT> Enemy2;

	std::vector<std::unique_ptr<COBJECT>> enemy;
	

	std::vector<std::unique_ptr<COBJECT>> enemy2;
	int Enemy2Num;

	std::unique_ptr<COBJECT> Boss;

	void Scroll();

	void Draw();
	void Update();
	void Main();
};


extern GameMain *GM;

