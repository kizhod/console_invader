#include "pch.h"
#include "Player.h"

void Player::Move(int a_x, int a_y)
{
	// ������ ���� �ִ� ��ġ�� ��µ� ���� ������
	Clear_Map();

	// ��ġ�� ���� ����
	x = a_x;
	y = a_y;
}
