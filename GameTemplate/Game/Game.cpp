#include "stdafx.h"
#include "Game.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Game::Game()
{
	
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Game::~Game()
{
}

/// <summary>
/// �X�V����
/// </summary>
void Game::Update()
{
	for (auto& pl : player) {
		pl.Update();
	}
	map.Update();
}

/// <summary>
/// �`�揈��
/// </summary>
void Game::Render()
{
	for (auto& pl : player) {
		pl.Draw();
	}
	map.Render();
}