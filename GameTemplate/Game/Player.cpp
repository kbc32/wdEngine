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

void Player::Draw(int cameraNo)
{
	m_model.Draw(
		g_camera3D[cameraNo].GetViewMatrix(),
		g_camera3D[cameraNo].GetProjectionMatrix()
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
	
	//XZ�����̈ړ����x���N���A�B
	m_moveSpeed.x = 0.0f;
	m_moveSpeed.z = 0.0f;
	
	//m_moveSpeed.y -= 980.0f * GameTime().GetFrameDeltaTime();
	m_moveSpeed.x -= lStick_x * 200.0f;		//�������ւ̈ړ����x�����Z�B
	m_moveSpeed.z -= lStick_y * 200.0f;		//�E�����ւ̈ړ����x�����Z�B
	
											
	m_moveSpeed.y -= 9.8f;				//�d��();

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