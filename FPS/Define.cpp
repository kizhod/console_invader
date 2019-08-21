#include "pch.h"
#include "Define.h"

void SetCursor(const COORD& Coord)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coord);
}

void SetCursor(int x, int y)
{
	SetCursor(COORD{ (short)x,(short)y });
}

