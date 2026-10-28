#pragma once
#include "../Collision/CollisionParameter.h"
struct PlayerData
{
	bool active;	//生存フラグ
	int handle;		//画像ハンドル
	Body body;		// 当たり判定ボディ
	bool isTurn;								// 左を向いているか
	bool isAir;									// 空中にいるか
	float posX;									// X座標
	float posY;									// Y座標
	float moveX;								// X移動量
	float moveY;								// Y移動量
	VECTOR pos;

};

void InitPlayer();
void LoadPlayer();
void StartPlayer();
void StepPlayer();
void UpdatePlayer();
void DrawPlayer();
void FinPlayer();

PlayerData* GetPlayer();