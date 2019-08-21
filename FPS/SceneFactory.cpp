#include "pch.h"
#include "SceneFactory.h"

#include "SceneManager.h"
#include "TestScene.h"

Scene* SceneFactory::Make(eScene a_eScene)
{
	SceneManager* pParent = SceneMng();
	Scene* pMakedScene = nullptr;

	switch (a_eScene)
	{
	case eScene::TestScene:
		pMakedScene = new TestScene(pParent);
		break;
	default:
		assert(false && "arg error");
		break;
	}

	return pMakedScene;
}


