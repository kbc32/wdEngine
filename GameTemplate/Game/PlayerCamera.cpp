#include "stdafx.h"
#include "PlayerCamera.h"


PlayerCamera::PlayerCamera()
{
	//�J�����̍��W�������Ă���
	m_toCameraPos = g_camera3D[0].GetPosition();
	
}


PlayerCamera::~PlayerCamera()
{
}

void PlayerCamera::Update(int PlayerNo)
{
	//�J�������X�V�B
	//�����_���v�Z����B
	CVector3 target = m_player->GetPlayerPosition();
	//�v���C���̑������炿����Ə�𒍎��_�Ƃ���B
	target.y += 50.0f;

	CVector3 toCameraPosOld = m_toCameraPos;
	//�p�b�h�̓��͂��g���ăJ�������񂷁B
	float x = g_pad[PlayerNo].GetRStickXF();
	float y = g_pad[PlayerNo].GetRStickYF();
	//Y������̉�]
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY(), 2.0f * x);
	qRot.Multiply({0.0f,0.0f,1.0f,0.0f});
	////X������̉�]�B
	//CVector3 axisX;
	//axisX.Cross(CVector3::AxisY, m_toCameraPos);
	//axisX.Normalize();
	//qRot.SetRotationDeg(axisX, 2.0f * y);
	//qRot.Apply(m_toCameraPos);

	//�J�����̉�]�̏�����`�F�b�N����B
	//�����_���王�_�܂ł̃x�N�g���𐳋K������B
	//���K������ƁA�x�N�g���̑傫�����P�ɂȂ�B
	//�傫�����P�ɂȂ�Ƃ������Ƃ́A�x�N�g�����狭�����Ȃ��Ȃ�A�����݂̂̏��ƂȂ�Ƃ������ƁB
	CVector3 toPosDir = m_toCameraPos;
	toPosDir.Normalize();
	if (toPosDir.y < -0.5f) {
		//�J����������������B
		m_toCameraPos = toCameraPosOld;
	}
	else if (toPosDir.y > 0.8f) {
		//�J�����������������B
		m_toCameraPos = toCameraPosOld;
	}

	//���_���v�Z����B
	CVector3 pos = target + m_toCameraPos;
	
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
