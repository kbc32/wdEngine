#include "stdafx.h"
#include "Weapon.h"
#include "Game.h"


Weapon::Weapon()
{
	m_weapon.Init(L"Assets/modelData/Sword.cmo");
}


Weapon::~Weapon()
{
}

void Weapon::Update(int PlayerNo)
{
	Game* game = Game::GetInstance();

	//カメラの右下に武器を表示
	//カメラのターゲットを代入
	CVector3 pos = g_camera3D[PlayerNo].GetTarget();
	pos.y = 0.0f;

	m_angle = CMath::RadToDeg(atan2(pos.x, pos.z));

	pos = g_camera3D[PlayerNo].GetTarget();
	float y = pos.y;
	pos.y = 0.0f;
	float x = pos.Length();
	m_angle2 = CMath::RadToDeg(atan2(-y, x));

	CQuaternion YRot;
	YRot.SetRotationDeg(CVector3::AxisY(), m_angle);

	CQuaternion XRot;
	XRot.SetRotationDeg(CVector3::AxisX(), m_angle2);

	m_rotation.Multiply(YRot, XRot);

	m_position = game->GetPlayerPosition(PlayerNo);

	CQuaternion PosRot;
	m_Pos = m_gunLocalPos;
	
	PosRot.SetRotationDeg(CVector3::AxisY(), m_angle);
	PosRot.Multiply(m_Pos);

	m_position += m_Pos;

	//ワールド行列の更新。
	m_weapon.UpdateWorldMatrix(/*m_position*/CVector3::Zero(),m_rotation, CVector3::One()*0.4f);
}

void Weapon::Draw(int PlayerNo)
{
	m_weapon.Draw(
		g_camera3D[PlayerNo].GetViewMatrix(),
		g_camera3D[PlayerNo].GetProjectionMatrix(),
		PlayerNo
	);
}
