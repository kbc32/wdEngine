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

	//�J�����̍X�V�B
	for (int i = 0; i < 4; i++)
	{
		g_camera3D[i].Update();
		//playercamera[i].Update(i);
	}
	//playercamera.Update();
	//for (auto& plca : playercamera) {
	//	//�g�p����J�����̕ύX
	//	plca.SetCameraNo(CameraNom);
	//	plca.SetPlayerNo(CameraNom);
	//	//�J�����ԍ����P���Z
	//	CameraNom++;
	//	//�X�V����
	//	plca.Update();
	//}

}

/// <summary>
/// �`�揈��
/// </summary>
void Game::Render(int cameraNo)
{
	//�v���C���[�l�l���̕`�揈��
	for (auto& pl : player) {
		//�`�揈��
		pl.Draw(cameraNo);
	}
	//�}�b�v�̕`�揈��
	map.Render(cameraNo);
}