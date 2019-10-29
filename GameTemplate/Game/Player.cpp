#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	//cmo�t�@�C���̓ǂݍ��݁B
	m_model.Init(L"Assets/modelData/unityChan.cmo");

	//�L�����N�^�[�R���g���[���[�̏�����
	Characon.Init(
		0.8f,
		4.0f,
		m_position
	);
}


Player::~Player()
{
}

void Player::Update()
{
	//�ړ�����
	Move();
	//���[���h�s��̍X�V�B
	m_model.UpdateWorldMatrix(m_position, CQuaternion::Identity(), CVector3::One());

}
void Player::Draw()
{
	m_model.Draw(
		g_camera3D.GetViewMatrix(), 
		g_camera3D.GetProjectionMatrix()
	);
}

void Player::Move()
{
	//�ړ������i�\���L�[�j
	//���{�^���ō��ɓ�����
	if (g_pad->IsPress(enButtonLeft))
	{
		m_position.x += 5.0f;
	}
	//�E�{�^���ŉE�ɓ�����
	if (g_pad->IsPress(enButtonRight))
	{
		m_position.x -= 5.0f;
	}
	//��{�^���ŉ��ɓ�����
	if (g_pad->IsPress(enButtonUp))
	{
		m_position.z -= 5.0f;
	}
	//���{�^���Ŏ�O�ɓ�����
	if (g_pad->IsPress(enButtonDown))
	{
		m_position.z += 5.0f;
	}


	//�ړ������i���X�e�B�b�N�j
	//float lStick_x = g_pad->GetLStickXF;
	//float lStick_y = g_pad->GetLStickYF;
	////A�{�^���ŃW�����v
	//if (g_pad->IsTrigger(enButtonA))
	//{
	//	Characon.
	//}
}