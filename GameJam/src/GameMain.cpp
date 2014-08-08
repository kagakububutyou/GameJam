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
	// �`�揀��
	app_env->setupDraw();


	Enemy->Draw();
	Player->Draw();

	// ��ʍX�V
	app_env->update();
}

void GameMain::Main()
{
	Update();
	Draw();
}