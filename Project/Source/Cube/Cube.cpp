#include "DxLib.h"
#include "Cube.h"
#include "../Map/MapParameter.h"
#include "../Camera/Camera.h"


// 変数

CubeData g_Cubes[CUBE_MAX] = { 0 };

CubeData g_CubeData = { 0 };
int g_CubeHandle[CUBE_TYPE_MAX] = { 0 };


void InitCube()
{
	CubeData* cube = g_Cubes;
	for (int i = 0; i < CUBE_MAX; i++)
	{
		
		cube->active = false;
		cube->pos = VGet(0.0f, 0.0f, 0.0f);
		cube->type = CUBE_MAP_NONE;
	}
}

void LoadCube()
{
	g_CubeHandle[CUBE1] = LoadGraph("Data/Cube/Cube1.png");
	g_CubeHandle[CUBE2] = LoadGraph("Data/Cube/Cube2.png");
	g_CubeHandle[CUBE3] = LoadGraph("Data/Cube/Cube3.png");
	g_CubeHandle[CUBE4] = LoadGraph("Data/Cube/Cube4.png");
	g_CubeHandle[CUBE5] = LoadGraph("Data/Cube/Cube5.png");
	g_CubeHandle[CUBE6] = LoadGraph("Data/Cube/Cube6.png");
	g_CubeHandle[CUBE7] = LoadGraph("Data/Cube/Cube7.png");
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
	// スクロールのためカメラを取得
	CameraData camera = GetCamera();

	CubeData* cube = g_Cubes;
	for (int i = 0; i < CUBE_MAX; i++, cube++)
	{
		if (cube->active)
		{
			DrawGraph((int)(cube->pos.x - camera.pos.x), (int)(cube->pos.y - camera.pos.y), cube->handle, TRUE);
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


CubeData* CreateCube(CubeMapType type, VECTOR pos)
{
	// 未使用のブロックを探す
	CubeData* cube = g_Cubes;
	for (int i = 0; i < CUBE_MAX; i++, cube++)
	{
		if (!cube->active)
		{
			// ブロック生成
			cube->active = true;
			cube->handle = g_CubeHandle[type];
			cube->pos = pos;
			cube->type = type;

			cube->width = MAP_CHIP_WIDTH;
			cube->height = MAP_CHIP_HEIGHT;
			return cube;
		}
	}

	return nullptr;
}


CubeData* GetCube()
{
	return g_Cubes;
}

void CubeHitPlayer(int index)
{
	g_CubeData.hitFlag = true;
}
