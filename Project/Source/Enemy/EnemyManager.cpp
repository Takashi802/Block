#include "../Player/Player.h"
#include "../Collision/Collision.h"
#include "../Collision/Collisionparameter.h"
#include "Enemyparameter.h"
#include "EnemyChip.h"
#include "Enemy.h"



// キャラクターの周囲何マスまでチェックするか
#define CHECK_ROUND_NUM (2)

// Map側に統合
void InitEnemies()
{
}

// Map側に統合
void LoadEnemies()
{
}

void StartEnemies()
{
	CreateEnemy();
}

void DrawEnemies()
{
	// ブロック描画
	DrawEnemy();
}

void FinEnemies()
{
}


void MoveWithEnemyCollision(Body* body)
{
	// X軸だけ移動する
	body->pos.x += body->move.x;

	// マップチップと当たり判定＆押し出し
	for (int y = 0; y < ENEMY_CHIP_Y_NUM; y++)
	{
		for (int x = 0; x < ENEMY_CHIP_X_NUM; x++)
		{
			// マップチップ取得
			EnemyChipData enemyChipData = GetEnemyChipData(x, y);
			// マップチップが0の場合は何もない
			if (enemyChipData.enemyChip == 0) continue;

			// ブロックを取り出して当たり判定
			EnemyData* enemy = enemyChipData.data;
			// 当たり判定
			if (CheckSquareSquare(body->pos.x, body->pos.y, body->width, body->height,
				enemy->pos.x, enemy->pos.y, enemy->width, enemy->height))
			{
				// 左からあたったか
				if (body->move.x > 0.0f)
				{
					// 左に押し出す
					body->pos.x -= (body->pos.x + body->width) - (enemy->pos.x);

				}
				// 右からあたったか
				else if (body->move.x < 0.0f)
				{
					// 右に押し出す
					body->pos.x += (enemy->pos.x + body->width) - (body->pos.x);

				}

				// 移動量は0にする
				body->move.x = 0.0f;
			}

		}
	}

	// Y軸だけ移動する
	body->pos.y += body->move.y;

	// マップチップと当たり判定＆押し出し
	for (int y = 0; y < ENEMY_CHIP_Y_NUM; y++)
	{
		for (int x = 0; x < ENEMY_CHIP_X_NUM; x++)
		{
			// マップチップ取得
			EnemyChipData enemyChipData = GetEnemyChipData(x, y);
			// マップチップが0の場合は何もない
			if (enemyChipData.enemyChip == 0) continue;

			// ブロックを取り出して当たり判定
			EnemyData* enemy = enemyChipData.data;
			// 当たり判定
			if (CheckSquareSquare(body->pos.x, body->pos.y, body->width, body->height,
				enemy->pos.x, enemy->pos.y, enemy->width, enemy->height))
			{
				// 上からあたったか
				if (body->move.y > 0.0f)
				{
					// 上に押し出す
					body->pos.y -= (body->pos.y + body->height) - (enemy->pos.y);

					// 空中フラグを折る
					body->isAir = false;
				}
				// 下からあたったか
				else if (body->move.y < 0.0f)
				{
					// 下に押し出す
					body->pos.y += (enemy->pos.y + body->width) - (body->pos.y);

				}

				// 移動量は0にする
				body->move.y = 0.0f;
			}

		}
	}
}

