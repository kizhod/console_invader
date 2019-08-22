#include "pch.h"
#include "GameScene.h"
#include "MapData.h"

#include "MapObjectFactory.h"
#include "Object.h"
#include "Player.h"
#include "Enemy.h"
#include "Missile.h"
//#include "Block.h"
#include "Item.h"
#include "Wall.h"


GameScene::GameScene(class SceneManager* a_pParent) : Scene(a_pParent)
{
}

GameScene::~GameScene()
{
}

eScene GameScene::GetScene()
{
	return eScene::GameScene;
}


void GameScene::Init() // 초기 설정
{
	// 맵 생성
	m_mapData = GetMapData();

	int nX = m_mapData.nX; // nX = 35
	int nY = m_mapData.nY; // nY = 16
	const char* pData = m_mapData.sMap; /// const char* sMap 문자열의 주소를 담는 포인터

	for (int y = 0; y < nY; ++y)
	{
		for (int x = 0; x < nX; ++x)
		{
			// y와 x의 이중 for문으로 20x20 sMap 의 위치를 모두 체크
			int nIndex = nX * y + x;

			// 각 맵의 하나하나의 값이 어떤 Type인지 받아 옴
			eObjectType type = (eObjectType)(pData[nIndex] - '0'); /// 선언

			// 위에서 받아온 맵의 type값으로 obj를 생성 ex) x=0, y=0일때 type은 1 -> 벽 Wall생성 
			Object* pObj = MapObjectFactory::MakeMapObejct(x, y, type);

			// 지정되지 않은 type으로 pObj가 nullptr이 되었을때의 예외처리
			if (pObj == nullptr) { continue; }

			// 생성된 obj가 hero인경우
			if (type == eObjectType::Player)
			{
				// 영웅캐릭터를 하나만 만들기 위함
				// m_pHero가 이미 생성되어 있으면 프로그램 크래시 발생 (assert(false)가 되면 프로그램이 터짐)
				assert(m_pPlayer == nullptr && "map data error - multi hero");
				// 영웅캐릭터 생성
				m_pPlayer = (Player*)pObj;
				// 해당 캐릭터의 상태를 설정 (hp:100, pow:10)
				// m_pPlayer->SetStat(ST_Stat{ 100, 10 });
			}
			else
			{
				// 생성된 객체를 container에 담아 둠
				m_vcObject.push_back(pObj);
			}
		}
	}

	// 영웅캐릭터가 하나도 없으면 프로그램 크래시 발생
	assert(m_pPlayer != nullptr && "map data error - no hero");
}