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


void GameScene::Init() // �ʱ� ����
{
	// �� ����
	m_mapData = GetMapData();

	int nX = m_mapData.nX; // nX = 35
	int nY = m_mapData.nY; // nY = 16
	const char* pData = m_mapData.sMap; /// const char* sMap ���ڿ��� �ּҸ� ��� ������

	for (int y = 0; y < nY; ++y)
	{
		for (int x = 0; x < nX; ++x)
		{
			// y�� x�� ���� for������ 20x20 sMap �� ��ġ�� ��� üũ
			int nIndex = nX * y + x;

			// �� ���� �ϳ��ϳ��� ���� � Type���� �޾� ��
			eObjectType type = (eObjectType)(pData[nIndex] - '0'); /// ����

			// ������ �޾ƿ� ���� type������ obj�� ���� ex) x=0, y=0�϶� type�� 1 -> �� Wall���� 
			Object* pObj = MapObjectFactory::MakeMapObejct(x, y, type);

			// �������� ���� type���� pObj�� nullptr�� �Ǿ������� ����ó��
			if (pObj == nullptr) { continue; }

			// ������ obj�� hero�ΰ��
			if (type == eObjectType::Player)
			{
				// ����ĳ���͸� �ϳ��� ����� ����
				// m_pHero�� �̹� �����Ǿ� ������ ���α׷� ũ���� �߻� (assert(false)�� �Ǹ� ���α׷��� ����)
				assert(m_pPlayer == nullptr && "map data error - multi hero");
				// ����ĳ���� ����
				m_pPlayer = (Player*)pObj;
				// �ش� ĳ������ ���¸� ���� (hp:100, pow:10)
				// m_pPlayer->SetStat(ST_Stat{ 100, 10 });
			}
			else
			{
				// ������ ��ü�� container�� ��� ��
				m_vcObject.push_back(pObj);
			}
		}
	}

	// ����ĳ���Ͱ� �ϳ��� ������ ���α׷� ũ���� �߻�
	assert(m_pPlayer != nullptr && "map data error - no hero");
}