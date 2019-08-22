#include "pch.h"
#include "Enemy.h"
#include "Player.h"

/*
// IInteraction을(를) 통해 상속됨
ST_Result Enemy::Interaction(Player* a_player)
{
	ST_Result temp{ false, "" };

	// 유저가 해당 몹의 위치에 가면 몹과 영웅의 hp가 몹의 Pow값에 따라 깎임
	// 동작
	m_Stat.HP -= a_player->m_Stat.Power;
	a_player->m_Stat.HP -= m_Stat.Power;

	// 로그
	temp.sLog += "히어로가 몬스터를 공격!\n";
	temp.sLog += "히어로 데미지 : ";
	temp.sLog += std::to_string(a_player->m_Stat.Pow);
	temp.sLog += "\n";
	temp.sLog += "몬스터 데미지 : ";
	temp.sLog += std::to_string(m_Stat.Pow);
	temp.sLog += "\n";

	// 동작
	if (m_Stat.HP <= 0)
	{
		// 몹 주금
		Clear_Map();
		temp.bMove = true;
	}

	return temp;
}

bool Monster::IsAlive()
{
	return m_Stat.HP > 0;
}

*/