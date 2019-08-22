#pragma once

#include "Scene.h"

class GameScene : public Scene
{
	StageMapData GetMapData()
	{
		// 맵 만들거나 / 스테이지 관리자가 MapData 만들어줄거임
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

	// Scene을(를) 통해 상속됨
	virtual eScene GetScene() override;

private:
	// 관리대상
	std::vector<class Object*> m_vcObject;
	class Player* m_pPlayer = nullptr;

	// 로그
	ST_Result m_stInteractionResult;

	// 맵
	StageMapData m_mapData;
};
