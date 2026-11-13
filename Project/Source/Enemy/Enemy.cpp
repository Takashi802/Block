#include "DxLib.h"
#include "Enemy.h"
#include "Enemyparameter.h"
#include "EnemyManager.h"

// 変数

EnemyData g_Enemy[ENEMY_MAX] = { 0 };
EnemyData g_EnemyData = { 0 };

int g_EnemyHandle[BLOCK_TYPE_MAX] = { 0 };

void InitEnemy()
{

	EnemyData* enemy = g_Enemy;
	for (int i = 0; i < ENEMY_MAX; i++, enemy++)
	{
		enemy->active = false;
		enemy->pos = VGet(0.0f, 0.0f, 0.0f);
		enemy->type = MAP_CHIP_NONE;
		g_EnemyData.body.move.x = 0.0f;
		g_EnemyData.body.move.y = 0.0f;

	}
}

void LoadEnemy()
{
	g_EnemyHandle[ENEMY1] = LoadGraph("Data/Map/Enemy1.png");
	
}


void StepEnemy()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		// ヒットフラグをリセット
		g_EnemyData.hitFlag = false;
	}
}

void UpdateEnemy()
{
}

void DrawEnemy()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		DrawGraph((int)g_EnemyData.body.pos.x, (int)g_EnemyData.body.pos.y, g_EnemyData.handle, TRUE);

		if (g_EnemyData.hitFlag)
		{
			DrawString(0, 20, "プレイヤーが当たった", GetColor(255, 255, 255));
		}
	}
}

void FinEnemy()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		DeleteGraph(g_EnemyData.handle);
	}
}

EnemyData* GetEnemy()
{
	return g_Enemy;
}

EnemyData* CreateEnemy(MapChipType type, VECTOR pos)
{
	return nullptr;
}

void EnemyHitPlayer(int index)
{
	g_EnemyData.hitFlag = true;
}
