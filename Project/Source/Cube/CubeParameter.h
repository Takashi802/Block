#pragma once
#include "DxLib.h"
#include "../Collision/CollisionParameter.h"



#define CUBE_NUM		(3)
#define CUBE_RADIUS	(128.0f)
#define CUBE_WIDTH	(256.0f)
#define CUBE_HEIGHT	(256.0f)

#define CUBE_CHIP_X_NUM (82)
#define CUBE_CHIP_Y_NUM (20)
#define CUBE_CHIP_WIDTH (24.0f)
#define CUBE_CHIP_HEIGHT (24.0f)



enum CubeChipType
{
	CUBE_CHIP_NONE,
	CUBE1,
	CUBE2,
	CUBE3,
	CUBE4,
	CUBE5,
	CUBE6,
	CUBE7,
	CUBE_TYPE_MAX,
};



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
	CubeChipType type;
};





struct CubeChipData
{
	int cubeChip;
	CubeData* data;
};
