#include "pch.h"
#include "IntroScene.h"

//#include "SceneManager.h"


struct TitleLogo
{
	const int nX = 35;
	const int nY = 16;

	const char* TitleMapData[] =
	{
		//0123456789012345678901234(34)
		 "WWWWWWWWWWWWWWWWWWWWWWWWW"//01
		 "W			              W"
		 "W	  =================   W"
		 "W			              W"
		 "W       S.P.A.C.E       W"
		 "W	    I.N.V.A.D.E.R     W"//5
		 "W			              W"
		 "W   =================   W"
		 "W				          W"
		 "W		                  W"
		 "W	    * START GAME      W"//10
		 "W				          W"
		 "W          EXIT         W"
		 "W				          W"
		 "W			              W"
		 "WWWWWWWWWWWWWWWWWWWWWWWWW"//15
	};

};


IntroScene::IntroScene(class SceneManager * a_pParent) : Scene(a_pParent)
{
}

IntroScene::~IntroScene()
{
}

eScene IntroScene::GetScene()
{
	return eScene::IntroScene;
}

void IntroScene::Init()
{
	cInit1;

	for (int y = 0; y < 16; y++)
	{
		for (int x = 0; x < 35; x++)
		{
			TitleMap[y][x] = stTitle.TitleMapData[y][x];
		}
	}
}

void IntroScene::Update(float a_fDeltaTime)
{
	SetCursor(5, 4);
	cout << a_fDeltaTime << endl;
}


const char* StateString(eInputState a_eState)
{
	switch (a_eState)
	{
	case eInputState::None:
		return "None";
		break;
	case eInputState::Down:
		return "KeepDown";
		break;
	case eInputState::Press:
		return "Press";
		break;
	case eInputState::Up:
		return "UP";
		break;
	default:
		break;
	}

	return "";
}


void IntroScene::Render()
{
	if (IsKeyDown(eKey::Space) == true && MenuSelect == 0)
	{
		m_refParent->ChangeScene(eScene::GameScene);
	}
	else if (IsKeyDown(eKey::Space) == true && MenuSelect == 1)
	{
		exit(0);
	}

	SColor_Y;	
}


void IntroScene::KeyInput(eKey a_eKey)
{
	if (IsKeyDown(eKey::Down) == true)
	{
		TitleMap[6][10] = ' ';
		TitleMap[9][13] = '*';
		MenuSelect = 1;
	}

	else if (IsKeyDown(eKey::Up) == true)
	{
		TitleMap[6][10] = ' ';
		TitleMap[9][13] = '*';
		MenuSelect = 0;
	}
}
