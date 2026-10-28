#include "Player.h"
#include "../Input/Input.h"
#include "../Camera/Camera.h"

//プレイヤー設定関連
#define PLAYER_DEFAULT_POS_X (100.0f)
#define PLAYER_DEFAULT_POS_Y (300.0f)
#define PLAYER_MOVE_SPEED (1.0f)

//ジャンプ力
#define PLAYER_JUMP_POWER (12.0f)
//重力
#define PLAYER_GRAVITY (0.4f)


PlayerData g_PlayerData = { 0 };

void InitPlayer()
{
	g_PlayerData.pos.x = PLAYER_DEFAULT_POS_X;
	g_PlayerData.pos.y = PLAYER_DEFAULT_POS_Y;
	g_PlayerData.move.x = 0.0f;
	g_PlayerData.move.y = 0.0f;
}

void LoadPlayer()
{
	g_PlayerData.handle = LoadGraph("Data/Player/Player.png");
}


void StartPlayer()
{
	// 生存フラグを立てる
	g_PlayerData.active = true;
}

void StepPlayer()
{
	// 死んでいたら何もしない
	if (!g_PlayerData.active)
	{
		return;
	}

	// X移動量は毎回リセットする
	g_PlayerData.move.x = 0.0f;

	// Y移動量に重力を反映
	//g_PlayerData.move.y += PLAYER_GRAVITY;

	// 左入力
	if (IsInputKey(KEY_A))
	{
		g_PlayerData.move.x = -PLAYER_MOVE_SPEED;
	}
	else if (IsInputKey(KEY_D))
	{
		g_PlayerData.move.x = PLAYER_MOVE_SPEED;
	}

	// SPACE入力
	if (IsTriggerKey(KEY_SPACE))
	{
		g_PlayerData.move.y = PLAYER_JUMP_POWER;
	}
}

void UpdatePlayer()
{
	// 死んでいたら処理しない
	if (!g_PlayerData.active) return;

	// 上昇しているもしくは落ちている場合は空中フラグを立てる
	if (g_PlayerData.move.y < 0.0f || g_PlayerData.move.y > PLAYER_GRAVITY)
	{
		g_PlayerData.isAir = true;
	}

	// 移動処理
	g_PlayerData.pos.x += g_PlayerData.move.x;
	g_PlayerData.pos.y += g_PlayerData.move.y;

}

void DrawPlayer()
{
	// 死んでいたら処理しない
	if (!g_PlayerData.active) return;
	DrawGraph((int)g_PlayerData.pos.x, (int)g_PlayerData.pos.y, g_PlayerData.handle, TRUE);


	// カメラ取得
	CameraData camera = GetCamera();

}

void FinPlayer()
{
	DeleteGraph(g_PlayerData.handle);
}

PlayerData GetPlayer()
{
	return g_PlayerData;
}
