#pragma once
#include "../Collision/CollisionParameter.h"

#define ENEMY_NUM		(3)
#define ENEMY_RADIUS	(128.0f)
#define ENEMY_WIDTH	(256.0f)
#define ENEMY_HEIGHT	(256.0f)

struct EnemyData
{
	bool active;	//生存フラグ
	int handle;		//画像ハンドル
	int hitFlag;	//当たり判定
	Body body;		// 当たり判定ボディ
};

// 関数のプロトタイプ宣言
void InitEnemy();
void LoadEnemy();
void StepEnemy();
void UpdateEnemy();
void DrawEnemy();
void FinEnemy();

// エネミー取得
EnemyData* GetEnemy();

// 当たり判定
void EnemyHitPlayer(int index);
