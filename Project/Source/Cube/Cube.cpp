#include "DxLib.h"
#include "Cube.h"

#define CUBE_WIDTH (25.0f)
#define CUBE_HEIGHT (25.0f)
#define CUBE_RADIUS	(20.0f)

// 変数

CubeData g_CubeData = { 0 };
void InitCube()
{

	for (int i = 0; i < CUBE_NUM; i++)
	{
		

	
	}
}

void LoadCube()
{
	
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

void CubeHitPlayer(int index)
{
	g_CubeData.hitFlag = true;
}
