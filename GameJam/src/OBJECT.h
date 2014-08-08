#pragma once
#include "lib/appEnv.hpp"

class COBJECT
{
public:
	COBJECT(){}
	~COBJECT(){}

	float x;			//	���W
	float y;			//	���W
	float width;		//	��
	float height;	//	����
	float Velocity_x;	//	���x
	float Velocity_y;	//	���x
	float Speed;
	float Rush;

	float ScrollX;	//	�X�N���[��
	float MapX;
	const static int Margin = 64;	//	�]��

	float Direction;
	float shotdirection;		//�e�̌���
	float shot_x;		//�e�̍��W
	float shot_y;		//�e�̍��W
	float shottime;		//�e���ł���鎞��
	float shotcount;	//�e���ł���鎞�Ԃ����炷
	float shotflag;		//�e���ł���Ă��邩�̃t���O
	float shotwidth;	//�e�̑傫��
	float shotheight;	//�e�̑傫��
	float shotspeed;	//�e�̑���

	Color color;	//	�F

	virtual void Move(){}
	virtual void Draw(){}
	virtual void Update(){}
	virtual void Collision(){}
};

