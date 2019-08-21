#pragma once

using std::cout;
using std::endl;

enum class eUpdateState
{
	Run,
	Final,
};

enum class eKey
{
	None = 0,

	Left,
	Up,
	Right,
	Down,
};

enum class eScene
{
	TestScene,

	// ���̶��� ��������� ���� ���ϰ� ������ define ����� ��
	Scene_First = TestScene,
};

#define SAFE_DELETE(x)		{ if((x) != nullptr ) { delete (x); (x) = nullptr; } }
#define SAFE_DELETE_ARR(x)	{ if((x) != nullptr ) { delete[] (x); (x) = nullptr; } }

void SetCursor(const COORD& Coord);
void SetCursor(int x, int y);

using fpTask = void(*)();
