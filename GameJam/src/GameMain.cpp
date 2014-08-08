#include "lib\appEnv.hpp"
#include "GameMain.h"
#include "OBJECT.h"
#include "Player.h"
#include "Blade.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Boss.h"
#include "main.h"

#include "Collision.h"

GameMain *GM;

GameMain::GameMain() :hoge("res/a.png"), floor("res/fl.png")
{
	Player.reset(new CPlayer());
	Blade.reset(new CBlade());
	Boss.reset(new CBoss());

	static const int Enemy1Num = 2;
	float Enemy1PosX[Enemy1Num] =
	{
		100,1000,
	};

	for (int i = 0; i < Enemy1Num; i++)
	{
		enemy.emplace_back(new CEnemy(Enemy1PosX[i]));
	}
	static const int Enemy2Num = 2;
	float Enemy2PosX[Enemy1Num] =
	{
		100, 1000,
	};
	float Enemy2Posy[Enemy1Num] =
	{
		(-Window::HEIGHT / 2 + 50), (-Window::HEIGHT / 2 + 50),
	};
	for (int i = 0; i < Enemy2Num; i++)
	{
		enemy2.emplace_back(new CEnemy2(Enemy2PosX[i]));
	}

	
}

void GameMain::Scroll()
{
	if (GM->Player->ScrollX < 0)  GM->Player->ScrollX = 0;

	drawTextureBox(-Window::WIDTH / 2, -Window::HEIGHT / 2, Window::WIDTH, Window::HEIGHT, 0 + GM->Player->ScrollX, 0, 1280, 720, hoge, Color(1, 1, 1));

	drawTextureBox(-Window::WIDTH / 2, -Window::HEIGHT / 2, Window::WIDTH, COBJECT::Margin+3, 0 + GM->Player->ScrollX, 883, 1024, 70, floor, Color(1, 1, 1));
}

void GameMain::Update()
{

	for (auto &i : enemy)
	{
		i->Update();
	}
	for (auto &i : enemy2)
	{
		i->Update();
	}

	//Enemy->Update();
	//Enemy2->Update();
	//Boss->Update();
	Player->Update();
	Blade->Update();
	
}

void GameMain::Draw()
{
	// •`‰æ€”õ
	app_env->setupDraw();

	Scroll();

	//Enemy->Draw();
	//Enemy2->Draw();
	for (auto &i : enemy)
	{
		i->Draw();
	}
	for (auto &i : enemy2)
	{
		i->Draw();
	}
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