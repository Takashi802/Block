#pragma once
#include "../Collision/CollisionParameter.h"


void InitCubes();
void LoadCubes();
void StartCubes();
void StepCubes();
void DrawCubes();
void FinCubes();


void MoveWithCubeCollision(Body* body);