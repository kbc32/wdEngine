#include "stdafx.h"
#include "Game.h"

/// <summary>
/// コンストラクタ
/// </summary>
Game::Game()
{
}

/// <summary>
/// デストラクタ
/// </summary>
Game::~Game()
{
}

/// <summary>
/// 更新処理
/// </summary>
void Game::Update()
{
	//プレイヤー四人分の更新処理
	for (auto& pl : player) {
		//使用するゲームパッドの変更
		pl.SetPadNom(PadNom);
		//パッド番号を１加算
		PadNom++;
		//更新処理
		pl.Update();
	}
	//一通り更新処理が終わったのでパッド番号を初期化
	PadNom = 0;

	//マップの更新
	map.Update();

	//カメラの更新。
	for (int i = 0; i < 4; i++)
	{
		g_camera3D[i].Update();
		//playercamera[i].Update(i);
	}
	//playercamera.Update();
	//for (auto& plca : playercamera) {
	//	//使用するカメラの変更
	//	plca.SetCameraNo(CameraNom);
	//	plca.SetPlayerNo(CameraNom);
	//	//カメラ番号を１加算
	//	CameraNom++;
	//	//更新処理
	//	plca.Update();
	//}

}

/// <summary>
/// 描画処理
/// </summary>
void Game::Render(int cameraNo)
{
	//プレイヤー四人分の描画処理
	for (auto& pl : player) {
		//描画処理
		pl.Draw(cameraNo);
	}
	//マップの描画処理
	map.Render(cameraNo);
}