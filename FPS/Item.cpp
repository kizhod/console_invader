#include "pch.h"
#include "Item.h"

#include "Player.h"

ST_Result Item::Interaction(Player* a_player)
{
	m_bShow = false;
	Clear_Map();

	// �� ������ �Ӽ��� �°� ������ ���¸� ������� �ش�
	// HP 50, Weapon 30, Armor 20
	switch (m_ItemType)
	{
	//case eObjectType::Item:		    a_player->AddHP(50); break;
	//case eObjectType::Weapon:		a_hero->AddStat(eStat::Power, 30); break;
	default: assert(false && "logic error"); break;
	}

	return ST_Result{ true };
}