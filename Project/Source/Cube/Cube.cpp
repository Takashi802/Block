#include "DxLib.h"
#include "../Map/MapParameter.h"
#include "CubeParameter.h"
#include "Cube.h"
#include "../Camera/Camera.h"
#include "../Player/Player.h"


#define CUBE_MOVE_SPEED (1.0f)
// 変数

CubeData g_CubeData = { 0 };

CubeData g_Cubes[CUBE_MAX] = { 0 }; 
int g_CubeHandle[BLOCK_TYPE_MAX] = { 0 };


void InitCube()
{
	CubeData* cube = g_Cubes;
	for (int i = 0; i < CUBE_MAX; i++, cube++)
	{
		cube->active = false;
		cube->pos = VGet(0.0f, 0.0f, 0.0f);
		cube->type = MAP_CHIP_NONE;
		g_CubeData.body.move.x = 0.0f;
		g_CubeData.body.move.y = 0.0f;

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
	
	if(PLAYER_WIDTH==CUBE_WIDTH)
	{
		g_CubeData.body.move.x = CUBE_MOVE_SPEED * PLAYER_MOVE_SPEED;
	}

}

void UpdateCube()
{
}

void DrawCube()
{

	CameraData camera = GetCamera();

	CubeData* cube = g_Cubes;
	for (int i = 0; i < BLOCK_MAX; i++, cube++)
	{
		if (cube->active)
		{
			DrawGraph((int)(cube->pos.x - camera.pos.x), (int)(cube->pos.y - camera.pos.y), cube->handle, TRUE);
		}
	}
}

void FinCube()
{
	
}



CubeData* GetCube()
{
	return g_Cubes;
}


CubeData* CreateCubes(MapChipType type, VECTOR pos)
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

			cube->width = CUBE_CHIP_WIDTH;
			cube->height = CUBE_CHIP_HEIGHT;
			return cube;
		}
	}

	return nullptr;
}