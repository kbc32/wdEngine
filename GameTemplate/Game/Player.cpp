#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	//cmoファイルの読み込み。
	m_model.Init(L"Assets/modelData/unityChan.cmo");

	//キャラクターコントローラーの初期化
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
	//移動処理
	Move();
	//ワールド行列の更新。
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
	//移動処理（十字キー）
	//左ボタンで左に動かす
	if (g_pad->IsPress(enButtonLeft))
	{
		m_position.x += 5.0f;
	}
	//右ボタンで右に動かす
	if (g_pad->IsPress(enButtonRight))
	{
		m_position.x -= 5.0f;
	}
	//上ボタンで奥に動かす
	if (g_pad->IsPress(enButtonUp))
	{
		m_position.z -= 5.0f;
	}
	//下ボタンで手前に動かす
	if (g_pad->IsPress(enButtonDown))
	{
		m_position.z += 5.0f;
	}


	//移動処理（左スティック）
	//float lStick_x = g_pad->GetLStickXF;
	//float lStick_y = g_pad->GetLStickYF;
	////Aボタンでジャンプ
	//if (g_pad->IsTrigger(enButtonA))
	//{
	//	Characon.
	//}
}