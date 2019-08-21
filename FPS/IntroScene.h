#pragma once
#include "Scene.h"
class IntroScene : public Scene
{
public:
	IntroScene(SceneManager * a_pParent);
	virtual ~IntroScene();

	// Scene을(를) 통해 상속됨
	virtual eScene GetScene() override;

	virtual void Init() override;
	virtual void Update(float a_fDeltaTime) override;
	virtual void Render() override;

	virtual void KeyInput(eKey a_eKey) override;

public:

	int MenuSelect = 0;
	//TitleLogo* pTitle;
	char TitleMap[16][35] = { 0, };
	TitleLogo stTitle;
};

