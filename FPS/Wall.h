#pragma once

#include "Object.h"

class Wall : public Object
{
public:

	Wall(int x, int y, char c) : Object(x, y, c) { }

	// IInteraction을(를) 통해 상속됨
	virtual ST_Result Interaction(Player* a_player) override
	{
		return ST_Result{ false };
	}
};