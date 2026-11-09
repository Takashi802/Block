#pragma once
#include "../Collision/CollisionParameter.h"
#include "../Map/MapParameter.h"

#define CUBE_NUM		(3)
#define CUBE_MAX		(5)
#define CUBE_RADIUS	(128.0f)
#define CUBE_WIDTH	(256.0f)
#define CUBE_HEIGHT	(256.0f)


// 関数のプロトタイプ宣言
void InitCube();
void LoadCube();
void StepCube();
void UpdateCube();
void DrawCube();
void FinCube();




struct CubeData
{
	bool active;	//生存フラグ
	int handle;		//画像ハンドル
	int hitFlag;	//当たり判定
	VECTOR pos;
	CubeMapType type;
	float width;
	float height;
	Body body;		// 当たり判定ボディ

};


// エネミー取得
CubeData* GetCube();

CubeData* CreateCube(CubeMapType type, VECTOR pos);
// 当たり判定
void CubeHitPlayer(int index);
