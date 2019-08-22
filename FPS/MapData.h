#pragma once
class MapData
{
public:
	MapData();
	~MapData();
};


struct StageMapData
{
	const static int nX = 35;
	const static int nY = 16;

	const char* sMap =
	{
		//0123456789012345678901234(34)
		"WWWWWWWWWWWWWWWWWWWWWWWWW" //01
		"W			             W"
		"W   M   M   M   M   M   W"
		"W				         W"
		"W	   M   M   M   M     W"
		"W			             W"
		"W   M   M   M   M   M   W"
		"W			             W"
		"W				         W"
		"W				         W"
		"W	 ~   ~   ~   ~   ~   W"
		"W   ~   ~   ~	 ~   ~   W"
		"W				         W"
		"W			 H	         W"
		"W			             W"
		"WWWWWWWWWWWWWWWWWWWWWWWWW"//15
	};
};