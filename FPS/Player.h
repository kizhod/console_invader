#pragma once
#include "Object.h"

class Player: public Object
{
public:
	Player(int x, int y, char c) : Object(x, y, c) { }

	void Move(int a_x, int a_y);

	// Character��(��) ���� ��ӵ�
	virtual ST_Result Interaction(Player* a_hero) override
	{
		assert(false);
		return ST_Result();
	}
};
