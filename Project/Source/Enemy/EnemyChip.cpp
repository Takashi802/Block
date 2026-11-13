#include "DxLib.h"
#include "Enemy.h"
#include "../GameSetting/GameSetting.h"
#include "Enemyparameter.h"
#include "EnemyChip.h"

EnemyChipData g_EnemyChip[ENEMY_CHIP_Y_NUM][ENEMY_CHIP_X_NUM] = { 0 };




void LoadEnemyChipData()
{
	FILE* fp;
	if (fopen_s(&fp, "Data/Map/Map.bin", "rb") != 0) return;

	for (int i = 0; i < ENEMY_CHIP_Y_NUM; i++)
	{
		for (int j = 0; j < ENEMY_CHIP_X_NUM; j++)
		{
			//マップ情報は1バイトずつ保存されるので、
			//fgetc関数でちょうど1バイト取得できる
			int map = fgetc(fp);
			g_EnemyChip[i][j].enemyChip = map;
		}
	}
}

void CreateEnemy()
{
	for (int i = 0; i < ENEMY_CHIP_Y_NUM; i++)
	{
		for (int j = 0; j < ENEMY_CHIP_X_NUM; j++)
		{
			//マップチップに合わせてブロック生成
			MapChipType type = (MapChipType)g_EnemyChip[i][j].enemyChip;

			//MAP_CHIP_NONEの場合は何もしない
			if (type == MAP_CHIP_NONE)continue;

			//インデックスから座標を計算
			VECTOR pos = VGet(j * ENEMY_CHIP_WIDTH, i * ENEMY_CHIP_HEIGHT, 0.0f);
			//生成したブロックはMapChipDataで参照しておく
			g_EnemyChip[i][j].data = CreateEnemy(type, pos);
		}
	}
}










EnemyChipData GetEnemyChipData(int x, int y)
{
	return g_EnemyChip[y][x];
}
