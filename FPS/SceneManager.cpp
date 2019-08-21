#include "pch.h"

#include "SceneManager.h"
#include "Scene.h"

#include "SceneFactory.h"

SceneManager::SceneManager()
{
	int nIndex = 0;

	m_arrKeys[(int)eKey::A] = 'A';
	m_arrKeys[(int)eKey::Left] = VK_LEFT;
	m_arrKeys[(int)eKey::W] = 'W';
	m_arrKeys[(int)eKey::Up] = VK_UP;
	m_arrKeys[(int)eKey::D] = 'S';
	m_arrKeys[(int)eKey::Right] = VK_RIGHT;
	m_arrKeys[(int)eKey::S] = 'D';
	m_arrKeys[(int)eKey::Down] = VK_DOWN;
	m_arrKeys[(int)eKey::Space] = VK_SPACE;

	for (eInputState& state : m_KeyState)
	{
		state = eInputState::None;
	}
}

SceneManager::~SceneManager()
{
	SAFE_DELETE(m_pNowScene);
}

void SceneManager::Init()
{
	ChangeScene(eScene::IntroScene);
}

void SceneManager::ChangeScene(eScene a_eScene)
{
	SAFE_DELETE(m_pNowScene);

	m_pNowScene = SceneFactory::Make(this, a_eScene);

	assert((m_pNowScene != nullptr) && "error");

	system("cls");

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
	for (int i = 0; i < (int)eKey::Max; ++i)
	{
		/*
		eInputState eNow = (GetAsyncKeyState(m_arrKeys[i]) & 0x8000) ? eInputState::Press : eInputState::None;

		if (m_BeforeKeyState[i] == eInputState::Press)
		{
			m_KeyState[i] = (eNow == eInputState::Press) ? eInputState::Down : eInputState::Up;
		}
		else // m_BeforeKeyState[i] == eInputState::None
		{
			m_KeyState[i] = (eNow == eInputState::Press) ? eInputState::Press : eInputState::None;
		}

		m_BeforeKeyState[i] = eNow;
		*/

		int nNowPress = (GetAsyncKeyState(m_arrKeys[i]) & 0x8000) ? 1 : 0;
		m_KeyState[i] = (eInputState)(nNowPress | m_BeforeKeyState[i]);
		m_BeforeKeyState[i] = (nNowPress << 1);
	}
}

eInputState SceneManager::GetKeyState(eKey a_eKey)
{
	return m_KeyState[(int)a_eKey];
}
