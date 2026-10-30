#pragma once
#include "../Collision/CollisionParameter.h"
#include "../Map/MapParameter.h"
#include "../Collision/Collision.h"


struct PlayerData
{
	bool active;	//生存フラグ
	int handle;		//画像ハンドル
	Body body;		// 当たり判定ボディ
};

void InitPlayer();
void LoadPlayer();
void StartPlayer();
void StepPlayer();
void UpdatePlayer();
void DrawPlayer();
void FinPlayer();


PlayerData GetPlayer();
