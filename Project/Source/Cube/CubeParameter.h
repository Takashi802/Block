#pragma once
#include "DxLib.h"
#include "../Collision/CollisionParameter.h"
#include "../Map/MapParameter.h"


#define CUBE_NUM		(3)
#define CUBE_MAX	1024
#define CUBE_RADIUS	(128.0f)
#define CUBE_WIDTH	(256.0f)
#define CUBE_HEIGHT	(256.0f)

#define CUBE_CHIP_X_NUM (82)
#define CUBE_CHIP_Y_NUM (20)
#define CUBE_CHIP_WIDTH (24.0f)
#define CUBE_CHIP_HEIGHT (24.0f)




struct CubeData
{
	bool active;	//生存フラグ
	int handle;		//画像ハンドル
	int hitFlag;	//当たり判定
	Body body;		// 当たり判定ボディ
	VECTOR pos;
	VECTOR move;
	float width;
	float height;
	MapChipType type;
};





struct CubeChipData
{
	int cubeChip;
	CubeData* data;
};
