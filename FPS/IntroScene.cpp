#include "pch.h"
#include "IntroScene.h"


IntroScene::IntroScene(SceneManager * a_pParent) : Scene(a_pParent)
{
}

IntroScene::~IntroScene()
{
}

eScene IntroScene::GetScene()
{
	return eScene::TestScene;
}

void IntroScene::Init()
{
}
void IntroScene::Update(float a_fDeltaTime)
{
	SetCursor(5, 4);
	cout << a_fDeltaTime << endl;
}
void IntroScene::Render()
{
	SetCursor(5, 5);
	cout << "Intro Scene" << endl;
	cout << "Space Invader 2100" << endl;
}

void IntroScene::KeyInput(eKey a_eKey)
{
}
