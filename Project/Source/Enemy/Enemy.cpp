#include "DxLib.h"
#include "Enemy.h"

#define ENEMY_WIDTH (25.0f)
#define ENEMY_HEIGHT (25.0f)
#define ENEMY_RADIUS	(20.0f)
#define ENEMY_DEFAULT_POS_X (500.0f)
#define ENEMY_DEFAULT_POS_Y (430.0f)

// 変数

EnemyData g_EnemyData = { 0 };
void InitEnemy()
{

	for (int i = 0; i < ENEMY_NUM; i++)
	{
		

		g_EnemyData.body.pos.x = ENEMY_DEFAULT_POS_X;
		g_EnemyData.body.pos.y = ENEMY_DEFAULT_POS_Y;
		
	}
}

void LoadEnemy()
{
	g_EnemyData.handle = LoadGraph("Data/Enemy/Enemy.png");
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
	return nullptr;
}

void EnemyHitPlayer(int index)
{
	g_EnemyData.hitFlag = true;
}
