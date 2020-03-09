#pragma once
#include "CGameObjectManager.h"
#include "Player.h"

class Player;
class PlayerCamera
{
public:
	PlayerCamera();
	~PlayerCamera();
	/// <summary>
	/// �X�^�[�g�֐�
	/// </summary>
	void Start(int PlayerNo);
	/// <summary>
	/// �A�b�v�f�[�g�֐�
	/// </summary>
	void Update(int PlayerNo);

	/// <summary>
	/// �v���C���[�̔ԍ���ݒ�
	/// </summary>
	/// <param name="Nom">�ԍ��@int�^</param>
	void SetPlayerNo(int Nom);

	void SetCameraNo(int Nom);
	/// <summary>
	/// �v���C���[�J�����̍��W��ݒ肷��
	/// </summary>
	/// <param name="playerNo">�v���C���[�̔ԍ�</param>
	void SetCameraPos(int playerNo);
private:
	Player* m_player;	//�v���C���[
	CVector3 m_toCameraPos = CVector3::Zero(); //�J�����̍��W

	float m_angle;
	float m_angle2;
	CQuaternion m_rotation;

	int PlayerNom = 0;	//�v���C���[�̔ԍ�
	int CameraNom; //�p�b�h�̔ԍ�
	CVector3 CameraPos;	//�J�����̍��W
};

