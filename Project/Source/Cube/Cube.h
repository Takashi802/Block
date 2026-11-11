#pragma once
#include "../Collision/CollisionParameter.h"
#include "CubeParameter.h"
#include "../Map/MapParameter.h"

// 関数のプロトタイプ宣言
void InitCube();
void LoadCube();
void StepCube();
void UpdateCube();
void DrawCube();
void FinCube();

// エネミー取得
CubeData* GetCube();
CubeData* CreateCubes(MapChipType type, VECTOR pos);

// 当たり判定
void CubeHitPlayer(int index);
