#pragma once
#include "Object.h"

class Enemy : public Object
{
public:
	Enemy(int x, int y, char c) : Object(x, y, c)
	{
	}

	// IInteraction��(��) ���� ��ӵ�
	virtual ST_Result Interaction(Player* a_player) override;
	virtual bool IsAlive();
};