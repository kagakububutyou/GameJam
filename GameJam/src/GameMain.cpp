#include "lib\appEnv.hpp"
#include "GameMain.h"
#include "main.h"


GameMain *GM;

GameMain::GameMain()
{
	Player.reset(new CPlayer());
	Enemy.reset(new CEnemy());
	Enemy2.reset(new CEnemy2());
	Boss.reset(new CBoss());
}

void GameMain::Update()
{

	Enemy->Update();
	Enemy2->Update();
	//Boss->Update();
	Player->Update();
	
}

void GameMain::Draw()
{
	// 描画準備
	app_env->setupDraw();


	Enemy->Draw();
	Enemy2->Draw();
	Player->Draw();
	//Boss->Draw();

	// 画面更新
	app_env->update();
}

void GameMain::Main()
{
	Update();
	Draw();
}