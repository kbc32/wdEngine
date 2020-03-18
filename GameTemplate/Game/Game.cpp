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

	for (int i = 0; i < 4; i++)
	{
		playercamera[i].Start(i);
	}

	m_level.Init(L"Assets/level/stage_001.tkl", [&](LevelObjectData& objdata)->bool {
		//if (wcscmp(objdata.name, L"Coin") == 0)
		//{
		//	//コインなら
		//	m_coin->SetPosition(objdata.position);
		//	return true;
		//}
		return false;
	});
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
		weapon[i].Update(i);
		playercamera[i].Update(i);
	}
}

/// <summary>
/// 描画処理
/// </summary>
void Game::Render(int cameraNo)
{
	//レベルを描画
	m_level.Draw(cameraNo);
	//プレイヤー四人分の描画処理
	for (auto& pl : player) {
		//描画処理
		//pl.Draw(cameraNo);
	}
	for (int i = 0; i < 4; i++)
	{
		weapon[i].Draw(cameraNo);
	}
	//マップの描画処理
	map.Render(cameraNo);
}