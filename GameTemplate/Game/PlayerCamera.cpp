#include "stdafx.h"
#include "PlayerCamera.h"
#include "Game.h"

PlayerCamera::PlayerCamera()
{
	 
	
}


PlayerCamera::~PlayerCamera()
{
}

void PlayerCamera::Start(int PlayerNo)
{
	//�J�����̍��W�������Ă���
	m_toCameraPos.Set(g_camera3D[PlayerNo].GetPosition());
}

void PlayerCamera::Update(int PlayerNo)
{
	//�J�������X�V�B
	//�����_���v�Z����B
	Game* game = Game::GetInstance();

	CVector3 pos = game->GetPlayerPosition(PlayerNo);
	//�v���C���̑������炿����Ə�𒍎��_�Ƃ���B
	pos.y += 50.0f;

	CVector3 toCameraPosOld = m_toCameraPos;
	//�p�b�h�̓��͂��g���ăJ�������񂷁B
	float x = g_pad[PlayerNo].GetRStickXF()*1.5;
	float y = g_pad[PlayerNo].GetRStickYF()*-1.5;
	//Y������̉�]
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY(), 2.0f * x);
	qRot.Apply(m_toCameraPos);
	////X������̉�]�B
	CVector3 axisX;
	axisX.Cross(CVector3::AxisY(), m_toCameraPos);
	axisX.Normalize();
	qRot.SetRotationDeg(axisX, 2.0f * y);
	qRot.Apply(m_toCameraPos);

	//�J�����̉�]�̏�����`�F�b�N����B
	//�����_���王�_�܂ł̃x�N�g���𐳋K������B
	//���K������ƁA�x�N�g���̑傫�����P�ɂȂ�B
	//�傫�����P�ɂȂ�Ƃ������Ƃ́A�x�N�g�����狭�����Ȃ��Ȃ�A�����݂̂̏��ƂȂ�Ƃ������ƁB
	CVector3 toPosDir = m_toCameraPos;
	toPosDir.Normalize();
	if (toPosDir.y < -0.6f) {
		//�J����������������B
		m_toCameraPos = toCameraPosOld;
	}
	else if (toPosDir.y > 0.9f) {
		//�J�����������������B
		m_toCameraPos = toCameraPosOld;
	}

	//���_���v�Z����B
	CVector3 target = pos + m_toCameraPos;
	
	g_camera3D[PlayerNo].SetPosition(pos);
	g_camera3D[PlayerNo].SetTarget(target);
}

void PlayerCamera::SetPlayerNo(int Nom)
{
	PlayerNom = Nom;
}

void PlayerCamera::SetCameraNo(int Nom)
{
	CameraNom = Nom;
}

void PlayerCamera::SetCameraPos(int playerNo)
{
	m_toCameraPos.Set(g_camera3D[playerNo].GetPosition());
}

