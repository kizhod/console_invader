#pragma once
#include "Scene.h"

class GameOverScene : public Scene
{
public:
	GameOverScene(class SceneManager* a_pParent);
	virtual ~GameOverScene();

	// Scene��(��) ���� ��ӵ�
	virtual eScene GetScene() override;
};
