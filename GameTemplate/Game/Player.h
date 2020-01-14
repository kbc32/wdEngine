#pragma once
#include "character/CharacterController.h"
#include "PlayerCamera.h"

class Player
{
public:
	Player();
	~Player();
	/// <summary>
	/// �A�b�v�f�[�g�֐�
	/// </summary>
	void Update();
	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw(int cameraNo);
	/// <summary>
	/// �v���C���[�̍��W���擾����
	/// </summary>
	/// <returns>�v���C���[�̍��W</returns>
	CVector3 GetPlayerPosition();
	/// <summary>
	/// �g�p����p�b�h�̔ԍ���ݒ�
	/// </summary>
	/// <param name="Nom">�ԍ�</param>
	void SetPadNom(int Nom);
	/// <summary>
	/// �v���C���[�̍��W��ݒ�
	/// </summary>
	/// <param name="position">�ړ���������W</param>
	void SetPlayerPosition(CVector3 position);
	/// <summary>
	/// �ړ����x���擾����
	/// </summary>
	/// <returns>�ړ����x</returns>
	CVector3 GetMoveSpeed();
	/// <summary>
	/// �p�b�h�̔ԍ����擾����
	/// </summary>
	/// <param name="Nom">�ԍ�</param>
	int GetPadNo();
private:
	/// <summary>
	/// �v���C���[�̈ړ�����
	/// </summary>
	void Move();

	int PadNom;											//�p�b�h�̔ԍ�
	//�v���C���[
	CharacterController Characon;						//�L�������\���l���\�i�L�����N�^�[�R���g���[���[�j
	SkinModel m_model;									//�X�L�����f���B
	CVector3 m_position = CVector3::Zero();				//�v���C���[�̃|�W�V����
	CVector3 m_moveSpeed = CVector3::Zero();			//�ړ����x�B
	//PlayerCamera m_playerCamera;						//�v���C���[�Ǐ]�p�̃J����

	int CameraNo;										//�J�����̔ԍ�
	CVector3 m_CameraPosition;							//�J�������W
};

extern int g_playerNom;		//!<�v���C���[�l���B

