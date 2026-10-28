#include "Player.h"
#include "../Input/Input.h"
#include "../Camera/Camera.h"



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


PlayerData g_PlayerData = { 0 };

void InitPlayer()
{
	g_PlayerData.active = false;
	g_PlayerData.handle = 0;
	g_PlayerData.body.pos = VGet(0.0f, 0.0f, 0.0f);
	g_PlayerData.body.move = VGet(0.0f, 0.0f, 0.0f);
	g_PlayerData.body.width = 0.0f;
	g_PlayerData.body.height = 0.0f;
}

void LoadPlayer()
{
	g_PlayerData.handle = LoadGraph("Data/Player/プレイヤー.png");
}

void StartPlayer()
{
	// 生存フラグを立てる
	g_PlayerData.active = true;

	// 初期位置設定
	g_PlayerData.body.pos.x = PLAYER_DEFAULT_POS_X;
	g_PlayerData.body.pos.y = PLAYER_DEFAULT_POS_Y;

	// サイズ設定
	g_PlayerData.body.width = PLAYER_WIDTH;
	g_PlayerData.body.height = PLAYER_HEIGHT;
}

void StepPlayer()
{
	// 死んでいたら何もしない
	if (!g_PlayerData.active)
	{
		return;
	}

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
		g_PlayerData.body.move.y = PLAYER_JUMP_POWER;
	}
}

void UpdatePlayer()
{
	// 死んでいたら処理しない
	if (!g_PlayerData.active) return;

	// 上昇しているもしくは落ちている場合は空中フラグを立てる
	if (g_PlayerData.moveY < 0.0f || g_PlayerData.moveY > PLAYER_GRAVITY)
	{
		g_PlayerData.isAir = true;
	}

	// 移動処理
	g_PlayerData.posX += g_PlayerData.moveX;
	g_PlayerData.posY += g_PlayerData.moveY;

}

void DrawPlayer()
{

	// 死んでいたら処理しない
	if (!g_PlayerData.active) return;

	// カメラ取得
	CameraData camera = GetCamera();

}

void FinPlayer()
{
}

PlayerData* GetPlayer()
{
	return nullptr;
}
