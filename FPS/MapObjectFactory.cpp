#include "pch.h"
#include "MapObjectFactory.h"

#include "MapObjectFactory.h"
#include "Wall.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"

Object* MapObjectFactory::MakeMapObejct(int x, int y, eObjectType a_eObjectType)
{
	// type�� �´� obj�� ����
	Object* returnObj = nullptr;
	switch (a_eObjectType)
	{
	case eObjectType::None: { return nullptr; }
	case eObjectType::Wall:
		returnObj = new Wall(x, y, GetData(a_eObjectType)); /// ���ڰ��� �޾Ƽ� ����.
		break;
	case eObjectType::Player:
		returnObj = new Player(x, y, GetData(a_eObjectType));
		break;
	case eObjectType::Enemy:
	{
		Enemy* pEnemy = new Enemy(x, y, GetData(a_eObjectType));
		//pEnemy->SetStat({ (short)100, (short)10 });
		returnObj = pEnemy;
	} break;
	//case eObjectType::SpeeUp:
	case eObjectType::Item:
	{
		Item* pItem = new Item(x, y, GetData(a_eObjectType));
		pItem->SetItemData(a_eObjectType);
		returnObj = pItem;
		break;
	}
/*
	// ��Ż obj
	case eType::Portal_Oneway:
	case eType::Portal_Portal:
	{
		static Portal* before = nullptr;

		Portal* pPortal = new Portal(x, y, GetData(a_eType));

		// before�� static��ü�� ������ �ٸ� ��Ż obj�� �����ϸ鼭 ������� ��Ż�� �ִ��� üũ
		if (before == nullptr)
		{
			before = pPortal;
		}

		switch (a_eType)
		{
			// Portal_Oneway�̸� ������ 5,5 ��ġ�� �����ش�.
		case eType::Portal_Oneway: pPortal->SetPortalData({ 5,5 }); break;
			// Portal_Portal�̸� ������ ������ before�� ��Ż ��ġ�� �����ش�.
		case eType::Portal_Portal: pPortal->SetPortalData(before); break;
		}

		returnObj = pPortal;
	} break;
	}
*/
	assert((returnObj != nullptr) && "arg error");
	return returnObj;
}