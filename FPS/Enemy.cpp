#include "pch.h"
#include "Enemy.h"
#include "Player.h"

/*
// IInteraction��(��) ���� ��ӵ�
ST_Result Enemy::Interaction(Player* a_player)
{
	ST_Result temp{ false, "" };

	// ������ �ش� ���� ��ġ�� ���� ���� ������ hp�� ���� Pow���� ���� ����
	// ����
	m_Stat.HP -= a_player->m_Stat.Power;
	a_player->m_Stat.HP -= m_Stat.Power;

	// �α�
	temp.sLog += "����ΰ� ���͸� ����!\n";
	temp.sLog += "����� ������ : ";
	temp.sLog += std::to_string(a_player->m_Stat.Pow);
	temp.sLog += "\n";
	temp.sLog += "���� ������ : ";
	temp.sLog += std::to_string(m_Stat.Pow);
	temp.sLog += "\n";

	// ����
	if (m_Stat.HP <= 0)
	{
		// �� �ֱ�
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