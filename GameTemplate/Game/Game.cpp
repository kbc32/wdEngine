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
	//for (auto& ca : g_camera3D) {
	//	//更新処理
	//	ca.Update()
	//}
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
}

/// <summary>
/// 描画処理
/// </summary>
void Game::Render()
{
	//プレイヤー四人分の描画処理
	for (auto& pl : player) {
		//描画処理
		pl.Draw();
	}
	//マップの描画処理
	map.Render();
}