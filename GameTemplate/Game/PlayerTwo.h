#pragma once
#include "character/CharacterController.h"

class PlayerTwo
{
public:
	PlayerTwo();
	~PlayerTwo();
	void Update();
	void Draw();
	CVector3 GetPlayerPosition();
private:
	/// <summary>
	/// �v���C���[�̈ړ�����
	/// </summary>
	void Move();
	int PadNom = 1;
	//�v���C���[
	CharacterController Characon;						//�L�������\���l���\�i�L�����N�^�[�R���g���[���[�j
	SkinModel m_model;									//�X�L�����f���B
	CVector3 m_position = CVector3::Zero();				//�v���C���[�̃|�W�V����
	CVector3 m_moveSpeed = CVector3::Zero();			//�ړ����x�B
};

