#pragma once
#include "../Collision/CollisionParameter.h"
#include "../Map/MapParameter.h"
#include "../Collision/Collision.h"


//プレイヤー設定関連// プレイヤー設定関連
#define PLAYER_WIDTH (50.0f)
#define PLAYER_HEIGHT (50.0f)
#define PLAYER_RADIUS	(20.0f)
#define PLAYER_DEFAULT_POS_X (100.0f)
#define PLAYER_DEFAULT_POS_Y (300.0f)
#define PLAYER_MOVE_SPEED (1.0f)


// 矩形判定の位置補正
#define PLAYER_BOX_COLLISION_OFFSET_X (24)
#define PLAYER_BOX_COLLISION_OFFSET_Y (20)
// 矩形判定のサイズ
#define PLAYER_BOX_COLLISION_WIDTH (50)
#define PLAYER_BOX_COLLISION_HEIGHT (50)



//ジャンプ力
#define PLAYER_JUMP_POWER (5.0f)
//重力
#define PLAYER_GRAVITY (0.1f)




struct PlayerData
{
	bool active;	//生存フラグ
	int handle;		//画像ハンドル
	Body body;		// 当たり判定ボディ
	BoxCollision boxCollision;
};

void InitPlayer();
void LoadPlayer();
void StartPlayer();
void StepPlayer();
void UpdatePlayer();
void DrawPlayer();
void FinPlayer();


PlayerData GetPlayer();
