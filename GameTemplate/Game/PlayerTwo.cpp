#include "stdafx.h"
#include "PlayerTwo.h"
#include "HID/Pad.h"


PlayerTwo::PlayerTwo()
{
	//プレイヤー１
	//cmoファイルの読み込み。
	m_model.Init(L"Assets/modelData/unityChan.cmo");

	//キャラクターコントローラーの初期化
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
	//移動処理
	Move();
	//ワールド行列の更新。
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
	//Aボタンでジャンプ
	if (g_pad->IsTrigger(enButtonA) //Aボタンが押されたら
		&& Characon.IsOnGround()  //かつ、地面に居たら
		) {
		//ジャンプする。
		m_moveSpeed.y = 400.0f;	//上方向に速度を設定して、
	}
	//移動処理
	float lStick_x = g_pad->GetLStickXF();
	float lStick_y = g_pad->GetLStickYF();
	//XZ成分の移動速度をクリア。
	m_moveSpeed.x = 0.0f;
	m_moveSpeed.z = 0.0f;
	//m_moveSpeed.y -= 980.0f * GameTime().GetFrameDeltaTime();
	m_moveSpeed.x -= lStick_x * 200.0f;	//奥方向への移動速度を加算。
	m_moveSpeed.z -= lStick_y * 200.0f;		//右方向への移動速度を加算。
	//重力
	m_moveSpeed.y -= 9.8f;
	//キャラクターコントローラーを使用して、座標を更新。
	m_position = Characon.Execute(1.0f / 60.0f, m_moveSpeed);
}

CVector3 PlayerTwo::GetPlayerPosition()
{
	return m_position;
}
