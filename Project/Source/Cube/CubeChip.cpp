#include "DxLib.h"
#include "CubeChip.h"
#include "CubeParameter.h"
#include "../GameSetting/GameSetting.h"
#include "Cube.h"


CubeChipData g_CubeChip[CUBE_CHIP_Y_NUM][CUBE_CHIP_X_NUM] = { 0 };




void LoadCubeChipData()
{
	FILE* fp;
	if (fopen_s(&fp, "Data/Map/Map.bin", "rb") != 0) return;

	for (int i = 0; i < CUBE_CHIP_Y_NUM; i++)
	{
		for (int j = 0; j < CUBE_CHIP_X_NUM; j++)
		{
			//マップ情報は1バイトずつ保存されるので、
			//fgetc関数でちょうど1バイト取得できる
			int map = fgetc(fp);
			g_CubeChip[i][j].cubeChip = map;
		}
	}
}

void CreateCube()
{
	for (int i = 0; i < CUBE_CHIP_Y_NUM; i++)
	{
		for (int j = 0; j < CUBE_CHIP_X_NUM; j++)
		{
			//マップチップに合わせてブロック生成
			MapChipType type = (MapChipType)g_CubeChip[i][j].cubeChip;

			//MAP_CHIP_NONEの場合は何もしない
			if (type == MAP_CHIP_NONE)continue;

			//インデックスから座標を計算
			VECTOR pos = VGet(j * CUBE_CHIP_WIDTH, i * CUBE_CHIP_HEIGHT, 0.0f);
			//生成したブロックはMapChipDataで参照しておく
			g_CubeChip[i][j].data = CreateCubes(type, pos);
		}
	}
}










CubeChipData GetCubeChipData(int x, int y)
{
	return g_CubeChip[y][x];
}
