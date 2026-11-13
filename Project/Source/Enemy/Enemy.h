#pragma once
#include "../Map/MapParameter.h"
#include "Enemyparameter.h"



// 関数のプロトタイプ宣言
void InitEnemy();
void LoadEnemy();
void StepEnemy();
void UpdateEnemy();
void DrawEnemy();
void FinEnemy();

// エネミー取得
EnemyData* GetEnemy();
EnemyData* CreateEnemy(MapChipType type, VECTOR pos);




// 当たり判定
void EnemyHitPlayer(int index);
