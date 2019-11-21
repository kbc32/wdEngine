#include "stdafx.h"
#include "PlayerTwo.h"
#include "HID/Pad.h"


PlayerTwo::PlayerTwo()
{
	//�v���C���[�P
	//cmo�t�@�C���̓ǂݍ��݁B
	m_model.Init(L"Assets/modelData/unityChan.cmo");

	//�L�����N�^�[�R���g���[���[�̏�����
	Characon.Init(
		0.8f,
		4.0f,
		m_position
	);
}


PlayerTwo::~PlayerTwo()
{
}

void PlayerTwo::Update()
{
	//�ړ�����
	Move();
	//���[���h�s��̍X�V�B
	m_model.UpdateWorldMatrix(m_position, CQuaternion::Identity(), CVector3::One());
}
void PlayerTwo::Draw()
{
	m_model.Draw(
		g_camera3D.GetViewMatrix(),
		g_camera3D.GetProjectionMatrix()
	);
}

void PlayerTwo::Move()
{
	//A�{�^���ŃW�����v
	if (g_pad->IsTrigger(enButtonA) //A�{�^���������ꂽ��
		&& Characon.IsOnGround()  //���A�n�ʂɋ�����
		) {
		//�W�����v����B
		m_moveSpeed.y = 400.0f;	//������ɑ��x��ݒ肵�āA
	}
	//�ړ�����
	float lStick_x = g_pad->GetLStickXF();
	float lStick_y = g_pad->GetLStickYF();
	//XZ�����̈ړ����x���N���A�B
	m_moveSpeed.x = 0.0f;
	m_moveSpeed.z = 0.0f;
	//m_moveSpeed.y -= 980.0f * GameTime().GetFrameDeltaTime();
	m_moveSpeed.x -= lStick_x * 200.0f;	//�������ւ̈ړ����x�����Z�B
	m_moveSpeed.z -= lStick_y * 200.0f;		//�E�����ւ̈ړ����x�����Z�B
	//�d��
	m_moveSpeed.y -= 9.8f;
	//�L�����N�^�[�R���g���[���[���g�p���āA���W���X�V�B
	m_position = Characon.Execute(1.0f / 60.0f, m_moveSpeed);
}

CVector3 PlayerTwo::GetPlayerPosition()
{
	return m_position;
}
