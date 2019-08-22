#include "pch.h"
#include "Player.h"

void Player::Move(int a_x, int a_y)
{
	// 이전에 내가 있던 위치에 출력된 값을 지워줌
	Clear_Map();

	// 위치를 새로 갱신
	x = a_x;
	y = a_y;
}
