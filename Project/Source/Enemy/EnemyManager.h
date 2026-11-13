#pragma once
#include "../Collision/CollisionParameter.h"


void InitEnemies();
void LoadEnemies();
void StartEnemies();
void DrawEnemies();
void FinEnemies();


void MoveWithEnemyCollision(Body* body);