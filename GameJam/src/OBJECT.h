#pragma once
#include "lib/appEnv.hpp"

class COBJECT
{
public:
	COBJECT(){}
	~COBJECT(){}

	float x;			//	座標
	float y;			//	座標
	float width;		//	幅
	float height;	//	高さ
	float Velocity_x;	//	速度
	float Velocity_y;	//	速度
	float Speed;
	float Rush;

	float ScrollX;	//	スクロール
	float MapX;
	const static int Margin = 64;	//	余白

	float Direction;
	float shotdirection;		//弾の向き
	float shot_x;		//弾の座標
	float shot_y;		//弾の座標
	float shottime;		//弾が打たれる時間
	float shotcount;	//弾が打たれる時間を減らす
	float shotflag;		//弾が打たれているかのフラグ
	float shotwidth;	//弾の大きさ
	float shotheight;	//弾の大きさ
	float shotspeed;	//弾の速さ

	Color color;	//	色

	virtual void Move(){}
	virtual void Draw(){}
	virtual void Update(){}
	virtual void Collision(){}
};

