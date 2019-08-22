#pragma once
#include "Scene.h"
class IntroScene : public Scene
{
public:
	IntroScene(SceneManager * a_pParent);
	virtual ~IntroScene();

	// Scene��(��) ���� ��ӵ�
	virtual eScene GetScene() override;

	virtual void Init() override;
	virtual void Update(float a_fDeltaTime) override;
	virtual void Render() override;

	virtual void KeyInput(eKey a_eKey) override;

public:

	int MenuSelect = 0;
	char TitleMap[16][35];
	//TitleLogo stTitle;
	//TitleLogo* pTitle = stTitle;
};

