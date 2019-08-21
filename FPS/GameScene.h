#pragma once

#include "Scene.h"

class GameScene : public Scene
{
public:
	GameScene(class SceneManager* a_pParent);
	virtual ~GameScene();

	// Scene을(를) 통해 상속됨
	virtual eScene GetScene() override;
};
