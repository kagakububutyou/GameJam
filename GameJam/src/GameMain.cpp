#include "lib\appEnv.hpp"
#include "GameMain.h"
#include "main.h"


GameMain *GM;

GameMain::GameMain()
{
	Player.reset(new CPlayer());
	Enemy.reset(new CEnemy());
}

void GameMain::Update()
{
	Player->Update();
	Enemy->Update();
}

void GameMain::Draw()
{
	// •`‰æ€”õ
	app_env->setupDraw();


	Enemy->Draw();
	Player->Draw();

	// ‰æ–ÊXV
	app_env->update();
}

void GameMain::Main()
{
	Update();
	Draw();
}