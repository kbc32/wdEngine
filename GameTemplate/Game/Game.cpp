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
	//�v���C���[�l�l���̍X�V����
	//for (auto& ca : g_camera3D) {
	//	//�X�V����
	//	ca.Update()
	//}
	//�v���C���[�l�l���̍X�V����
	for (auto& pl : player) {
		//�g�p����Q�[���p�b�h�̕ύX
		pl.SetPadNom(PadNom);
		//�p�b�h�ԍ����P���Z
		PadNom++;
		//�X�V����
		pl.Update();
	}
	//��ʂ�X�V�������I������̂Ńp�b�h�ԍ���������
	PadNom = 0;
	//�}�b�v�̍X�V
	map.Update();
}

/// <summary>
/// �`�揈��
/// </summary>
void Game::Render()
{
	//�v���C���[�l�l���̕`�揈��
	for (auto& pl : player) {
		//�`�揈��
		pl.Draw();
	}
	//�}�b�v�̕`�揈��
	map.Render();
}