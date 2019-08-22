#pragma once

#include "Object.h"

class Item : public Object
{
public:
	Item(int x, int y, char c) : Object(x, y, c) { }

	virtual bool IsAlive() { return m_bShow; }

	void SetItemData(eObjectType a_eType) { m_ItemType = a_eType; }

	// IInteraction을(를) 통해 상속됨
	virtual ST_Result Interaction(Player* a_hero) override;

private:
	bool m_bShow = true;
	eObjectType m_ItemType = eObjectType::None;
};