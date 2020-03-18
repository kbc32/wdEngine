#include "stdafx.h"
#include "Game.h"

Game* Game::m_instance = nullptr;

/// <summary>
/// �R���X�g���N�^
/// </summary>
Game::Game()
{
	//�T�E���h�G���W����������
	m_soundEngine.Init();

	//�m�F�p
	//�����V���b�g�Đ���SE
	m_se.Init(L"Assets/sound/coinGet.wav");

	m_instance = this;

	for (int i = 0; i < 4; i++)
	{
		playercamera[i].Start(i);
	}

	m_level.Init(L"Assets/level/stage_001.tkl", [&](LevelObjectData& objdata)->bool {
		//if (wcscmp(objdata.name, L"Coin") == 0)
		//{
		//	//�R�C���Ȃ�
		//	m_coin->SetPosition(objdata.position);
		//	return true;
		//}
		return false;
	});
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
	//�m�F�p
	if (g_pad[0].IsTrigger(enButtonA)) {
		//A�{�^���������ꂽ��SE��炷�B
		m_se.Play(false);
	}


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

	//�T�E���h�̍X�V
	m_soundEngine.Update();

	//�J�����̍X�V�B
	for (int i = 0; i < 4; i++)
	{
		g_camera3D[i].Update();
		weapon[i].Update(i);
		playercamera[i].Update(i);
	}
}

/// <summary>
/// �`�揈��
/// </summary>
void Game::Render(int cameraNo)
{
	//���x����`��
	m_level.Draw(cameraNo);
	//�v���C���[�l�l���̕`�揈��
	for (auto& pl : player) {
		//�`�揈��
		//pl.Draw(cameraNo);
	}
	for (int i = 0; i < 4; i++)
	{
		weapon[i].Draw(cameraNo);
	}
	//�}�b�v�̕`�揈��
	map.Render(cameraNo);
}