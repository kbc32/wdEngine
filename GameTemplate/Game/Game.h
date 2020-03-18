#pragma once
#include "IGameObject.h"
#include "Player.h"
#include "Map.h"
#include "graphics/Camera.h"
#include "PlayerCamera.h"
#include "Weapon.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"
#include "level/Level.h"
#include "Coin.h"



class Game : public IGameObject
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Game();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Game();
	/// <summary>
	/// �X�V�����B
	/// </summary>
	void Update();
	/// <summary>
	/// �`�揈���B
	/// </summary>
	void Render(int cameraNo);
	static Game* GetInstance()
	{
		return m_instance;
	}
	/// <summary>
	/// �v���C���[�̍��W�������Ă���
	/// </summary>
	/// <param name="PlayerNo">�v���C���[�̔ԍ�</param>
	/// <returns>�v���C���[�̍��W</returns>
	CVector3 GetPlayerPosition(int PlayerNo)
	{
		return player[PlayerNo].GetPlayerPosition();
	}
	//Camera g_camera3D;		//3D�J�����B
private:
	CSoundEngine m_soundEngine;		//�T�E���h�G���W��
	//�v���C���[4�l��
	Player player[4];
	//����4�l��
	Weapon weapon[4];
	//�v���C���[�J����
	PlayerCamera playercamera[4];
	//Map map;				//�}�b�v
	int PadNom = 0;			//�p�b�h�̔ԍ�
	int CameraNom = 0;		//�J�����̔ԍ�
	static Game* m_instance;
	Level m_level;
	Coin* m_coin = nullptr;

	//�m�F�p
	CSoundSource m_se;
};

