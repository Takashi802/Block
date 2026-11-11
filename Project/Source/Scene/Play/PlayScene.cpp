#include "DxLib.h"
#include "../../Scene/SceneManager.h"
#include "../../Map/MapManager.h"
#include "../../Player/Player.h"
#include "../../Camera/Camera.h"
#include "../../Collision/Collision.h"
#include "../../Cube/CubeManager.h"


// 背景のスピード
#define BACK_GROUND_SPEED (-1.5f)

void InitPlayScene()
{
	// プレイヤー初期化
	InitPlayer();

	// マップ初期化
	InitMap();

	// カメラ初期化
	InitCamera();

	//InitEnemy();

	//InitCubes();
}

void LoadPlayScene()
{
	// プレイヤーロード
	LoadPlayer();

	// マップをロード
	LoadMap();

	//LoadEnemy();

	//LoadCubes();
}

void StartPlayScene()
{
	// プレイヤー開始
	StartPlayer();

	// マップを開始
	StartMap();

	StartCubes();
}

void StepPlayScene()
{
	// プレイヤーステップ
	StepPlayer();

	// カメラステップ
	StepCamera();

	// StepEnemy();

	// StepCube();
}

void UpdatePlayScene()
{
	// マップ更新
	// プレイヤー更新
	UpdatePlayer();

	// UpdateEnemy();

	// 当たり判定
	//CheckCollision();
}

void DrawPlayScene()
{
	// プレイヤー描画
	DrawPlayer();

	// マップ描画
	DrawMap();

	// DrawEnemy();

	// カメラ描画
	DrawCamera();

	DrawCubes();
}

void FinPlayScene()
{
	// プレイヤー終了
	FinPlayer();

	// マップ終了
	FinMap();

	// FinEnemy();

	FinCubes();
}
