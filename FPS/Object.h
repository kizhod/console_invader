#pragma once
class Object
{
public:

	Object(int a_nX, int a_nY, char a_cData) : x(a_nX), y(a_nY), data(a_cData) {}

	char GetData() { return data; }
	COORD GetCoord() { return COORD{ (short)x, (short)y }; }
	bool IsCross(int a_x, int a_y) { return ((x == a_x) && (y == a_y)); } // 충돌을 어떻게 판별?
	void Clear_Map()
	{
		SetCursor(x, y);
		cout << ' ';
	}

	virtual bool IsAlive() { return true; }
	virtual ST_Result Interaction(class Player* a_player) = 0;

protected:
	int x;
	int y;

private:
	char data;


	//-----------------------------



	ST_Stat m_ActiveStat;
	ST_Stat m_Stat;

	void SetStat(const ST_Stat stat)
	{
		m_ActiveStat = stat;
		m_Stat = stat;
	}

	void AddHP(int a_nAmount)
	{
		// hp값을 더함 -값이 들어오면 깎일 수도 있음
		m_ActiveStat.HP += a_nAmount;

		if (m_ActiveStat.HP < 0)
		{
			m_ActiveStat.HP = 0;
		}

		else if (m_ActiveStat.HP > m_Stat.HP)
		{
			m_ActiveStat.HP = m_Stat.HP;
		}
	}

	void AddStat(eStat a_eType, int a_nAmount)
	{
		// 각 type에 맞게 상태값을 갱신시켜줌
		switch (a_eType)
		{
		case HP:
			m_ActiveStat.HP += a_nAmount;
			m_Stat.HP += a_nAmount;
			break;
		case Power:
			m_ActiveStat.Power += a_nAmount;
			m_Stat.Power += a_nAmount;
			break;
		default:
			break;
		}
	}
};

