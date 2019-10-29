#pragma once
#include "character/CharacterController.h"

class Player
{
public:
	Player();
	~Player();
	void Update();
	void Draw();
private:
	/// <summary>
	/// �v���C���[�̈ړ�����
	/// </summary>
	void Move();
	CharacterController Characon;						//�L�������\���l���\�i�L�����N�^�[�R���g���[���[�j
	SkinModel m_model;									//�X�L�����f���B
	CVector3 m_position = CVector3::Zero();				//�v���C���[�̃|�W�V����
};

