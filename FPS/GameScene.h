#pragma once

#include "Scene.h"

class GameScene : public Scene
{
	StageMapData GetMapData()
	{
		// �� ����ų� / �������� �����ڰ� MapData ������ٰ���
		return StageMapData();
	}
	static eKey GetKey(char c);


public:
	GameScene(class SceneManager* a_pParent);
	virtual ~GameScene();

	void Init();
	void Destroy();
	void Update(float fDeltaTime);
	void Render();

	// Scene��(��) ���� ��ӵ�
	virtual eScene GetScene() override;

private:
	// �������
	std::vector<class Object*> m_vcObject;
	class Player* m_pPlayer = nullptr;

	// �α�
	ST_Result m_stInteractionResult;

	// ��
	StageMapData m_mapData;
};
