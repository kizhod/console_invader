#include "pch.h"
#include "MapObjectFactory.h"

#include "MapObjectFactory.h"
#include "Wall.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"

Object* MapObjectFactory::MakeMapObejct(int x, int y, eObjectType a_eObjectType)
{
	// type에 맞는 obj를 생성
	Object* returnObj = nullptr;
	switch (a_eObjectType)
	{
	case eObjectType::None: { return nullptr; }
	case eObjectType::Wall:
		returnObj = new Wall(x, y, GetData(a_eObjectType)); /// 문자값을 받아서 리턴.
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
	// 포탈 obj
	case eType::Portal_Oneway:
	case eType::Portal_Portal:
	{
		static Portal* before = nullptr;

		Portal* pPortal = new Portal(x, y, GetData(a_eType));

		// before은 static객체로 이전에 다른 포탈 obj를 생성하면서 만들어진 포탈이 있는지 체크
		if (before == nullptr)
		{
			before = pPortal;
		}

		switch (a_eType)
		{
			// Portal_Oneway이면 무조건 5,5 위치로 보내준다.
		case eType::Portal_Oneway: pPortal->SetPortalData({ 5,5 }); break;
			// Portal_Portal이면 이전에 생성된 before의 포탈 위치로 보내준다.
		case eType::Portal_Portal: pPortal->SetPortalData(before); break;
		}

		returnObj = pPortal;
	} break;
	}
*/
	assert((returnObj != nullptr) && "arg error");
	return returnObj;
}