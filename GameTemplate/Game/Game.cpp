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
	player.Update();
	map.Update();
}

/// <summary>
/// 描画処理
/// </summary>
void Game::Render()
{
	player.Draw();
	map.Render();
}