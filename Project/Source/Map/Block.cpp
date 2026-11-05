#include "Block.h"
#include "../Camera/Camera.h"
#include "MapChip.h"

BlockData g_Blocks[BLOCK_MAX] = { 0 };
int g_BlockHandle[BLOCK_TYPE_MAX] = { 0 };


void InitBlock()
{
	BlockData* block = g_Blocks;
	for (int i = 0; i < BLOCK_MAX; i++, block++)
	{
		block->active = false;
		block->pos = VGet(0.0f, 0.0f, 0.0f);
		block->type = MAP_CHIP_NONE;
	}
}

void LoadBlock()
{
	g_BlockHandle[BLOCK1] = LoadGraph("Data/Map/Block1.png");
	g_BlockHandle[BLOCK2] = LoadGraph("Data/Map/Block2.png");
	g_BlockHandle[BLOCK3] = LoadGraph("Data/Map/Block3.png");
	g_BlockHandle[BLOCK4] = LoadGraph("Data/Map/Block4.png");
	g_BlockHandle[BLOCK5] = LoadGraph("Data/Map/Block5.png");
	g_BlockHandle[BLOCK6] = LoadGraph("Data/Map/Block6.png");
	g_BlockHandle[BLOCK7] = LoadGraph("Data/Map/Block7.png");
	g_BlockHandle[BLOCK8] = LoadGraph("Data/Map/Block8.png");
	g_BlockHandle[BLOCK9] = LoadGraph("Data/Map/Block9.png");
	
}

void StartBlock()
{
}

void StepBlock()
{
}

void DrawBlock()
{
	// スクロールのためカメラを取得
	CameraData camera = GetCamera();

	BlockData* block = g_Blocks;
	for (int i = 0; i < BLOCK_MAX; i++, block++)
	{
		if (block->active)
		{
			DrawGraph((int)(block->pos.x - camera.pos.x), (int)(block->pos.y - camera.pos.y), block->handle, TRUE);
		}
	}
}

void FinBlock()
{
}

BlockData* CreateBlock(MapChipType type, VECTOR pos)
{
	// 未使用のブロックを探す
	BlockData* block = g_Blocks;
	for (int i = 0; i < BLOCK_MAX; i++, block++)
	{
		if (!block->active)
		{
			// ブロック生成
			block->active = true;
			block->handle = g_BlockHandle[type];
			block->pos = pos;
			block->type = type;

			block->width = MAP_CHIP_WIDTH;
			block->height = MAP_CHIP_HEIGHT;
			return block;
		}
	}

	return nullptr;
}

BlockData* GetBlocks()
{
	return g_Blocks;
}
