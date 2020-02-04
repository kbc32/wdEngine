#include "stdafx.h"
#include "Game.h"

Game* Game::m_instance = nullptr;

/// <summary>
/// コンストラクタ
/// </summary>
Game::Game()
{
	//サウンドエンジンを初期化
	m_soundEngine.Init();

	//確認用
	//ワンショット再生のSE
	m_se.Init(L"Assets/sound/coinGet.wav");

	m_instance = this;
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
	//確認用
	if (g_pad[0].IsTrigger(enButtonA)) {
		//Aボタンが押されたらSEを鳴らす。
		m_se.Play(false);
	}


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

	//サウンドの更新
	m_soundEngine.Update();

	//カメラの更新。
	for (int i = 0; i < 4; i++)
	{
		g_camera3D[i].Update();
		playercamera[i].Update(i);
	}
}

/// <summary>
/// 描画処理
/// </summary>
void Game::Render(int cameraNo)
{
	//プレイヤー四人分の描画処理
	for (auto& pl : player) {
		//描画処理
		//pl.Draw(cameraNo);
	}
	//マップの描画処理
	map.Render(cameraNo);
}