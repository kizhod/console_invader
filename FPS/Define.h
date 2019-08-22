#pragma once

using std::cout;
using std::endl;


//콘솔 색상
enum COLOR {
	BLACK,			//0
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKY_BLUE,
	DARK_RED,
	DARK_VIOLET,
	DARK_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKY_BLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,			//15
};


enum class eUpdateState
{
	Run,
	Final,
};

enum class eKey
{
	None = -1,

	A,
	Left,
	W,
	Up,
	S,
	Right,
	D,
	Down,
	Space,

	Max,
};

enum class eInputState : short
{
	None	= 0b00,
	Down	= 0b11,
	Press	= 0b01,
	Up		= 0b10,
};
enum class eScene
{
	IntroScene,
	GameScene,
	GameOverScene,

};

enum class eObjectType
{
	None = 0,
	Wall,
	Block,

	Item = 3,
	Missile,

	Enemy = 5,
	Player =6,
};

char GetData(eObjectType a_eObjectType)
{
	// obj속성에 따라 화면에 그려질 char값을 return
	switch (a_eObjectType)
	{
	case eObjectType::None: { return ' '; }
	case eObjectType::Wall: { return 'W'; }break;
	case eObjectType::Block: { return '~'; }break;

	case eObjectType::Player: { return 'H'; }break;
	case eObjectType::Enemy: { return 'M'; }break;

	//case eObjectType::Item: { return 'A'; }break;

	//case eObjectType::Portal_Oneway: { return 'P'; }break;
	}

	assert(false && "arg error");
	return 0;
}

enum class eItem
{
	None = -1,

	PowerUp,
	MissileSpeedUp,
	SpeedUp,

	Max,
};

struct ST_Result
{
	bool bMove = false;
	std::string sLog;

	void Clear()
	{
		bMove = true;
		sLog = "";
	}
};


enum eStat
{
	HP,
	Power,
	Speed,
};

struct ST_Stat
{
	int HP;
	int Power;
	int Speed;
};

enum eGame
{
	MaxStage = 1,
};

#define SAFE_DELETE(x)		{ if((x) != nullptr ) { delete (x); (x) = nullptr; } }
#define SAFE_DELETE_ARR(x)	{ if((x) != nullptr ) { delete[] (x); (x) = nullptr; } }

enum class CURSOR_TYPE { NOCURSOR, SOLIDCURSOR, NORMALCURSOR };

void SetCursor(const COORD& Coord);
void SetCursor(int x, int y);
void SetCursorType(CURSOR_TYPE c);

using fpTask = void(*)();

// 컬러, 화면크기
#define SColor_R  {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);}
#define SColor_W  {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}
#define SColor_Y  {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);}

#define cInit1 {system(" mode  con lines=20   cols=40 ");}