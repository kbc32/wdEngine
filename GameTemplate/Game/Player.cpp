#include "stdafx.h"
#include "Player.h"
#include "HID/Pad.h"
#include "PlayerCamera.h"

int g_playerNom = 4;//�v���C���[�l��

Player::Player()
{
	//�v���C���[
	//cmo�t�@�C���̓ǂݍ��݁B
	m_model.Init(L"Assets/modelData/unityChan.cmo");

	m_position.y += 4.0f;

	//�L�����N�^�[�R���g���[���[�̏�����
	Characon.Init(
		1.6f,
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
	m_model.UpdateWorldMatrix(m_position, m_rotation, CVector3::One());
}

void Player::Draw(int cameraNo)
{
	m_model.Draw(
		g_camera3D[cameraNo].GetViewMatrix(),
		g_camera3D[cameraNo].GetProjectionMatrix(),
		cameraNo
	);
}

void Player::Move()
{
	
	//A�{�^���ŃW�����v
	if (g_pad[PadNom].IsPress(enButtonA) //A�{�^���������ꂽ��
		&& Characon.IsOnGround()  //���A�n�ʂɋ�����
		) {
		//�W�����v����B
		m_moveSpeed.y = 200.0f;	//������ɑ��x��ݒ肵�āA
	}

	//�ړ�����
	float lStick_x = g_pad[PadNom].GetLStickXF();
	float lStick_y = g_pad[PadNom].GetLStickYF();
	//���_���璍���_�Ɍ������ĐL�т�x�N�g�������߂�
	CVector3 cameraDir = g_camera3D[PadNom].GetTarget() -
						g_camera3D[PadNom].GetPosition();
	//y�̒l������
	cameraDir.y = 0.0f;
	//���K��
	cameraDir.Normalize();

	CVector3 cameraDirX;
	cameraDirX.Cross(cameraDir, CVector3::AxisY());

	//XZ�����̈ړ����x���N���A�B
	m_moveSpeed.x = 0.0f;
	m_moveSpeed.z = 0.0f;
	m_moveSpeed.y -= 15.0f;				//�d��;

	m_moveSpeed += cameraDirX * lStick_x * -300.0f;		//�������ւ̈ړ����x�����Z�B
	m_moveSpeed += cameraDir * lStick_y * 300.0f;		//�E�����ւ̈ړ����x�����Z�B

	//�L�����N�^�[�R���g���[���[���g�p���āA���W���X�V�B
	m_position = Characon.Execute(1.0f / 60.0f, m_moveSpeed);
}

CVector3 Player::GetPlayerPosition()
{
	return m_position;
}

void Player::SetPadNom(int Nom)
{
	PadNom = Nom;
}

void Player::SetPlayerPosition(CVector3 position)
{
	m_position = position;
}

CVector3 Player::GetMoveSpeed()
{
	return m_moveSpeed;
}

int Player::GetPadNo()
{
	return PadNom;
}