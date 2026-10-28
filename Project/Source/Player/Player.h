#pragma once
#include "../Collision/CollisionParameter.h"

// プレイヤー設定関連
#define PLAYER_WIDTH (25.0f)
#define PLAYER_HEIGHT (25.0f)
#define PLAYER_RADIUS	(20.0f)
#define PLAYER_DEFAULT_POS_X (600.0f)
#define PLAYER_DEFAULT_POS_Y (500.0f)
#define PLAYER_MOVE_SPEED (4.0f)

// ジャンプ力
#define PLAYER_JUMP_POWER (-12.0f)
// 重力
#define PLAYER_GRAVITY (0.4f)



struct PlayerData
{
	bool active;	//生存フラグ
	int handle;		//画像ハンドル
	Body body;		// 当たり判定ボディ
	bool isTurn;								// 左を向いているか
	bool isAir;									// 空中にいるか
	VECTOR pos;
	VECTOR move;
};

void InitPlayer();
void LoadPlayer();
void StartPlayer();
void StepPlayer();
void UpdatePlayer();
void DrawPlayer();
void FinPlayer();

PlayerData GetPlayer();