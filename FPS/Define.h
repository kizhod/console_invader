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

	// 씬이랑은 관계없지만 나름 편하게 쓸법한 define 비슷한 값
	Scene_First = TestScene,
};

#define SAFE_DELETE(x)		{ if((x) != nullptr ) { delete (x); (x) = nullptr; } }
#define SAFE_DELETE_ARR(x)	{ if((x) != nullptr ) { delete[] (x); (x) = nullptr; } }

void SetCursor(const COORD& Coord);
void SetCursor(int x, int y);

using fpTask = void(*)();
