#pragma once
#include "../Collision/CollisionParameter.h"
#include "CubeParameter.h"

// 関数のプロトタイプ宣言
void InitCube();
void LoadCube();
void StepCube();
void UpdateCube();
void DrawCube();
void FinCube();

// エネミー取得
CubeData* GetCube();
CubeData* CreateCubes(CubeChipType type, VECTOR pos);

// 当たり判定
void CubeHitPlayer(int index);
