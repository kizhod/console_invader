#pragma once
#include "Object.h"

class Player: public Object
{
public:
	Player(int x, int y, char c) : Object(x, y, c) { }

	void Move(int a_x, int a_y);

	// Character을(를) 통해 상속됨
	virtual ST_Result Interaction(Player* a_hero) override
	{
		assert(false);
		return ST_Result();
	}
};
