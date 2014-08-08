#include "lib\appEnv.hpp"
#include "GameMain.h"
#include "Player.h"
#include "Blade.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Boss.h"
#include "main.h"


GameMain *GM;

GameMain::GameMain()
{
	Player.reset(new CPlayer());
	Blade.reset(new CBlade());
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
	Blade->Update();
	
}

void GameMain::Draw()
{
	// •`‰æ€”õ
	app_env->setupDraw();


	Enemy->Draw();
	Enemy2->Draw();
	Player->Draw();
	//Boss->Draw();

	// ‰æ–ÊXV
	app_env->update();
}

void GameMain::Main()
{
	Update();
	Draw();
}