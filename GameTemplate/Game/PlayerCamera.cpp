#include "stdafx.h"
#include "PlayerCamera.h"


PlayerCamera::PlayerCamera()
{
	//カメラの座標を持ってくる
	m_toCameraPos = g_camera3D[0].GetPosition();
	
}


PlayerCamera::~PlayerCamera()
{
}

void PlayerCamera::Update(int PlayerNo)
{
	//カメラを更新。
	//注視点を計算する。
	CVector3 target = m_player->GetPlayerPosition();
	//プレイヤの足元からちょっと上を注視点とする。
	target.y += 50.0f;

	CVector3 toCameraPosOld = m_toCameraPos;
	//パッドの入力を使ってカメラを回す。
	float x = g_pad[PlayerNo].GetRStickXF();
	float y = g_pad[PlayerNo].GetRStickYF();
	//Y軸周りの回転
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY(), 2.0f * x);
	qRot.Multiply({0.0f,0.0f,1.0f,0.0f});
	////X軸周りの回転。
	//CVector3 axisX;
	//axisX.Cross(CVector3::AxisY, m_toCameraPos);
	//axisX.Normalize();
	//qRot.SetRotationDeg(axisX, 2.0f * y);
	//qRot.Apply(m_toCameraPos);

	//カメラの回転の上限をチェックする。
	//注視点から視点までのベクトルを正規化する。
	//正規化すると、ベクトルの大きさが１になる。
	//大きさが１になるということは、ベクトルから強さがなくなり、方向のみの情報となるということ。
	CVector3 toPosDir = m_toCameraPos;
	toPosDir.Normalize();
	if (toPosDir.y < -0.5f) {
		//カメラが上向きすぎ。
		m_toCameraPos = toCameraPosOld;
	}
	else if (toPosDir.y > 0.8f) {
		//カメラが下向きすぎ。
		m_toCameraPos = toCameraPosOld;
	}

	//視点を計算する。
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
