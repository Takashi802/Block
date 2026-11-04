#pragma once
#include "../Collision/CollisionParameter.h"

#define CUBE_NUM		(3)
#define CUBE_RADIUS	(128.0f)
#define CUBE_WIDTH	(256.0f)
#define CUBE_HEIGHT	(256.0f)

struct CubeData
{
	bool active;	//生存フラグ
	int handle;		//画像ハンドル
	int hitFlag;	//当たり判定
	Body body;		// 当たり判定ボディ
};

// 関数のプロトタイプ宣言
void InitCube();
void LoadCube();
void StepCube();
void UpdateCube();
void DrawCube();
void FinCube();

// エネミー取得
CubeData* GetCube();

// 当たり判定
void CubeHitPlayer(int index);
