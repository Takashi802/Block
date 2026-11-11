#include "../Player/Player.h"
#include "../Collision/Collision.h"
#include "../Collision/Collisionparameter.h"
#include "../Cube/Cube.h"
#include "CubeChip.h"
#include "CubeParameter.h"


// キャラクターの周囲何マスまでチェックするか
#define CHECK_ROUND_NUM (2)

// Map側に統合
void InitCubes()
{
}

// Map側に統合
void LoadCubes()
{
}

void StartCubes()
{
	CreateCube();
}

void DrawCubes()
{
	// ブロック描画
	DrawCube();
}

void FinCubes()
{
}


void MoveWithCubeCollision(Body* body)
{
	// X軸だけ移動する
	body->pos.x += body->move.x;

	// マップチップと当たり判定＆押し出し
	for (int y = 0; y < CUBE_CHIP_Y_NUM; y++)
	{
		for (int x = 0; x < CUBE_CHIP_X_NUM; x++)
		{
			// マップチップ取得
			CubeChipData cubeChipData = GetCubeChipData(x, y);
			// マップチップが0の場合は何もない
			if (cubeChipData.cubeChip == 0) continue;

			// ブロックを取り出して当たり判定
			CubeData* cube = cubeChipData.data;
			// 当たり判定
			if (CheckSquareSquare(body->pos.x, body->pos.y, body->width, body->height,
				cube->pos.x, cube->pos.y, cube->width, cube->height))
			{
				// 左からあたったか
				if (body->move.x > 0.0f)
				{
					// 左に押し出す
					body->pos.x -= (body->pos.x + body->width) - (cube->pos.x);

				}
				// 右からあたったか
				else if (body->move.x < 0.0f)
				{
					// 右に押し出す
					body->pos.x += (cube->pos.x + body->width) - (body->pos.x);

				}

				// 移動量は0にする
				body->move.x = 0.0f;
			}

		}
	}

	// Y軸だけ移動する
	body->pos.y += body->move.y;

	// マップチップと当たり判定＆押し出し
	for (int y = 0; y < CUBE_CHIP_Y_NUM; y++)
	{
		for (int x = 0; x < CUBE_CHIP_X_NUM; x++)
		{
			// マップチップ取得
			CubeChipData cubeChipData = GetCubeChipData(x, y);
			// マップチップが0の場合は何もない
			if (cubeChipData.cubeChip == 0) continue;

			// ブロックを取り出して当たり判定
			CubeData* cube = cubeChipData.data;
			// 当たり判定
			if (CheckSquareSquare(body->pos.x, body->pos.y, body->width, body->height,
				cube->pos.x, cube->pos.y, cube->width, cube->height))
			{
				// 上からあたったか
				if (body->move.y > 0.0f)
				{
					// 上に押し出す
					body->pos.y -= (body->pos.y + body->height) - (cube->pos.y);

					// 空中フラグを折る
					body->isAir = false;
				}
				// 下からあたったか
				else if (body->move.y < 0.0f)
				{
					// 下に押し出す
					body->pos.y += (cube->pos.y + body->width) - (body->pos.y);

				}

				// 移動量は0にする
				body->move.y = 0.0f;
			}

		}
	}
}

