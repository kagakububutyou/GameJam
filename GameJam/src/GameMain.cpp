#include "lib\appEnv.hpp"
#include "GameMain.h"


GameMain *GM;

GameMain::GameMain()
{
	Player.reset(new CPlayer());
}

void GameMain::Update()
{
	Player->Update();
}

void GameMain::Draw()
{
	Player->Draw();
	drawBox(100, 150, 50, 50, 1, color256(255, 0, 255, 255));
}

void GameMain::Main()
{
	Update();
	Draw();
}