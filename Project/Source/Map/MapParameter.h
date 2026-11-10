#pragma once
#include "DxLib.h"

#define BLOCK_MAX 1024
#define MAP_CHIP_X_NUM (82)
#define MAP_CHIP_Y_NUM (20)
#define MAP_CHIP_WIDTH (24.0f)
#define MAP_CHIP_HEIGHT (24.0f)

enum MapChipType
{
	MAP_CHIP_NONE,		
	BLOCK1,				//‚±‚Ì”š‚ÆƒGƒNƒZƒ‹‚Ì”š‚ª“¯‚¶
	BLOCK2,
	
	BLOCK_TYPE_MAX,
};

enum CubeMapType
{
	CUBE_MAP_NONE,
	CUBE1,
	CUBE2,
	CUBE3,
	CUBE4,
	CUBE5,
	CUBE6,
	CUBE7,
	CUBE_TYPE_MAX,
};

struct BlockData
{
	bool active;
	int handle;
	float width;
	float height;
	MapChipType type;
	VECTOR pos;
};

struct MapChipData
{
	int mapChip;
	BlockData* data;
};