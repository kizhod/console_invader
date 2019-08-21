#include "pch.h"

#include "SceneManager.h"
#include "Scene.h"

#include "SceneFactory.h"

eKey SceneManager::GetKey_withChar(char c)
{
	switch (c)
	{
		case 'w':
		{
			return eKey::Up;
		} break;
		case 'a':
		{
			return eKey::Left;
		} break;
		case 's':
		{
			return eKey::Down;
		} break;
		case 'd':
		{
			return eKey::Right;
		} break;
		default:
		{
			return eKey::None;
		} break;
	}
}

SceneManager::~SceneManager()
{
	SAFE_DELETE(m_pNowScene);
}

void SceneManager::Init()
{
	ChangeScene(eScene::Scene_First);
}

void SceneManager::ChangeScene(eScene a_eScene)
{
	SAFE_DELETE(m_pNowScene);

	m_pNowScene = SceneFactory::Make(a_eScene);

	assert((m_pNowScene != nullptr) && "error");

	m_pNowScene->Init();
}

void SceneManager::Update(float a_fDeltaTime)
{
	KeyCheck();
	m_pNowScene->Update(a_fDeltaTime);
}

void SceneManager::Render()
{
	m_pNowScene->Render();
}

void SceneManager::KeyCheck()
{
	// m_pNowScene->KeyInput(e);
}

