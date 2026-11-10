#include "DxLib.h"
#include "../Map/MapParameter.h"
#include "CubeParameter.h"
#include "Cube.h"

// 変数

CubeData g_CubeData = { 0 };
int g_CubeHandle[CUBE_TYPE_MAX] = { 0 };


void InitCube()
{

	for (int i = 0; i < CUBE_NUM; i++)
	{
		

	
	}
}

void LoadCube()
{
	g_CubeHandle[CUBE1] = LoadGraph("Data/Map/Block3.png");
	g_CubeHandle[CUBE2] = LoadGraph("Data/Map/Block4.png");
	g_CubeHandle[CUBE3] = LoadGraph("Data/Map/Block5.png");
	g_CubeHandle[CUBE4] = LoadGraph("Data/Map/Block6.png");
	g_CubeHandle[CUBE5] = LoadGraph("Data/Map/Block7.png");
	g_CubeHandle[CUBE6] = LoadGraph("Data/Map/Block8.png");
	g_CubeHandle[CUBE7] = LoadGraph("Data/Map/Block9.png");
}


void StepCube()
{
	for (int i = 0; i < CUBE_NUM; i++)
	{
		// ヒットフラグをリセット
		g_CubeData.hitFlag = false;
	}
}

void UpdateCube()
{
}

void DrawCube()
{
	for (int i = 0; i < CUBE_NUM; i++)
	{
		DrawGraph((int)g_CubeData.body.pos.x, (int)g_CubeData.body.pos.y, g_CubeData.handle, TRUE);

		if (g_CubeData.hitFlag)
		{
			DrawString(0, 20, "プレイヤーが当たった", GetColor(255, 255, 255));
		}
	}
}

void FinCube()
{
	for (int i = 0; i < CUBE_NUM; i++)
	{
		DeleteGraph(g_CubeData.handle);
	}
}

CubeData* GetCube()
{
	return nullptr;
}

CubeData* CreateCubes(CubeChipType type, VECTOR pos)
{
	return nullptr;
}

void CubeHitPlayer(int index)
{
	g_CubeData.hitFlag = true;
}
