#pragma once
#include "DxLib.h"

#define BLOCK_MAX 1024
#define MAP_CHIP_X_NUM (60)
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

struct BlockData
{
	bool active;
	int handle;
	MapChipType type;
	VECTOR pos;
};

struct MapChipData
{
	int mapChip;
	BlockData* data;
};