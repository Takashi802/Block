#include "Player.h"
#include "../Input/Input.h"
#include "../Camera/Camera.h"
#include "../Map/MapParameter.h"
#include "../Collision/Collision.h"
#include "../Map/MapManager.h"

//プレイヤー設定関連// プレイヤー設定関連
#define PLAYER_WIDTH (25.0f)
#define PLAYER_HEIGHT (25.0f)
#define PLAYER_RADIUS	(20.0f)
#define PLAYER_DEFAULT_POS_X (100.0f)
#define PLAYER_DEFAULT_POS_Y (300.0f)
#define PLAYER_MOVE_SPEED (1.0f)


// 矩形判定の位置補正
#define PLAYER_BOX_COLLISION_OFFSET_X (24)
#define PLAYER_BOX_COLLISION_OFFSET_Y (20)
// 矩形判定のサイズ
#define PLAYER_BOX_COLLISION_WIDTH (20)
#define PLAYER_BOX_COLLISION_HEIGHT (44)



//ジャンプ力
#define PLAYER_JUMP_POWER (1.0f)
//重力
#define PLAYER_GRAVITY (0.1f)


PlayerData g_PlayerData = { 0 };
PlayerData g_PrevPlayerData = { 0 };




void InitPlayer()
{
	g_PlayerData.body.pos.x = PLAYER_DEFAULT_POS_X;
	g_PlayerData.body.pos.y = PLAYER_DEFAULT_POS_Y;
	g_PlayerData.body.move.x = 0.0f;
	g_PlayerData.body.move.y = 0.0f;
	g_PlayerData.body.width = 0.0f;
	g_PlayerData.body.height = 0.0f;


	
}

void LoadPlayer()
{
	g_PlayerData.handle = LoadGraph("Data/Player/Player.png");
}


void StartPlayer()
{
	// 生存フラグを立てる
	g_PlayerData.active = true;


	//// 矩形判定設定
	//g_PlayerData.boxCollision.posX = PLAYER_BOX_COLLISION_OFFSET_X;
	//g_PlayerData.boxCollision.posY = PLAYER_BOX_COLLISION_OFFSET_Y;
	//g_PlayerData.boxCollision.width = PLAYER_BOX_COLLISION_WIDTH;
	//g_PlayerData.boxCollision.height = PLAYER_BOX_COLLISION_HEIGHT;
}

void StepPlayer()
{
	// 死んでいたら何もしない
	if (!g_PlayerData.active)
	{
		return;
	}

	// X移動量は毎回リセットする
	g_PlayerData.body.move.x = 0.0f;

	// Y移動量に重力を反映
	g_PlayerData.body.move.y += PLAYER_GRAVITY;

	// 左入力
	if (IsInputKey(KEY_A))
	{
		g_PlayerData.body.move.x = -PLAYER_MOVE_SPEED;
	}
	else if (IsInputKey(KEY_D))
	{
		g_PlayerData.body.move.x = PLAYER_MOVE_SPEED;
	}

	// SPACE入力
	if (IsTriggerKey(KEY_SPACE))
	{
		g_PlayerData.body.move.y = -PLAYER_JUMP_POWER;
	}
}

void UpdatePlayer()
{
	// 死んでいたら処理しない
	if (!g_PlayerData.active) return;

	//// 上昇しているもしくは落ちている場合は空中フラグを立てる
	//if (g_PlayerData.move.y < 0.0f || g_PlayerData.move.y > PLAYER_GRAVITY)
	//{
	//	g_PlayerData.isAir = true;
	//}

	// 移動処理
	g_PlayerData.body.pos.x += g_PlayerData.body.move.x;
	g_PlayerData.body.pos.y += g_PlayerData.body.move.y;

	// 当たり判定付きで移動
	MoveWithMapCollision(&g_PlayerData.body);

}

void DrawPlayer()
{
	
	//死んでたら処理しない
	if (!g_PlayerData.active) return;

	//カメラ取得
	CameraData camera = GetCamera();

	DrawGraph(
		(int)(g_PlayerData.body.pos.x - camera.pos.x),
		(int)(g_PlayerData.body.pos.y - camera.pos.y),
		g_PlayerData.handle,
		TRUE
	);

}

void FinPlayer()
{
	DeleteGraph(g_PlayerData.handle);
}



PlayerData GetPlayer()
{
	return g_PlayerData;
}

