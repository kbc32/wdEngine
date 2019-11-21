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
	for (auto& pl : player) {
		pl.Update();
	}
	map.Update();
}

/// <summary>
/// 描画処理
/// </summary>
void Game::Render()
{
	for (auto& pl : player) {
		pl.Draw();
	}
	map.Render();
}