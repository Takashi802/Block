#pragma once
#include "DxLib.h"
#include "../Collision/CollisionParameter.h"
#include "../Map/MapParameter.h"


#define ENEMY_NUM		(3)
#define ENEMY_MAX	1024
#define ENEMY_RADIUS	(128.0f)
#define ENEMY_WIDTH	(256.0f)
#define ENEMY_HEIGHT	(256.0f)

#define ENEMY_CHIP_X_NUM (82)
#define ENEMY_CHIP_Y_NUM (20)
#define ENEMY_CHIP_WIDTH (24.0f)
#define ENEMY_CHIP_HEIGHT (24.0f)



struct EnemyData
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





struct EnemyChipData
{
	int enemyChip;
	EnemyData* data;
};
