#include "stdafx.h"
#include "Player.h"
#include "HID/Pad.h"


Player::Player()
{
	//プレイヤー
	//cmoファイルの読み込み。
	m_model.Init(L"Assets/modelData/unityChan.cmo");

	//キャラクターコントローラーの初期化
	Characon.Init(
		0.8f,
		4.0f,
		m_position
	);

	//カメラ移動用にカメラの初期座標を持ってくる
	m_CameraPosition = g_camera3D.GetPosition();
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
	
	//Aボタンでジャンプ
	if (g_pad[PadNom].IsPress(enButtonA) //Aボタンが押されたら
		&& Characon.IsOnGround()  //かつ、地面に居たら
		) {
		//ジャンプする。
		m_moveSpeed.y = 200.0f;	//上方向に速度を設定して、
	}

	//移動処理
	float lStick_x = g_pad[PadNom].GetLStickXF();
	float lStick_y = g_pad[PadNom].GetLStickYF();
	
	//XZ成分の移動速度をクリア。
	m_moveSpeed.x = 0.0f;
	m_moveSpeed.z = 0.0f;
	
	//m_moveSpeed.y -= 980.0f * GameTime().GetFrameDeltaTime();
	m_moveSpeed.x -= lStick_x * 200.0f;	//奥方向への移動速度を加算。
	m_moveSpeed.z -= lStick_y * 200.0f;		//右方向への移動速度を加算。
	
											
	m_moveSpeed.y -= 9.8f;				//重力

	//キャラクターコントローラーを使用して、座標を更新。
	m_position = Characon.Execute(1.0f/60.0f,m_moveSpeed);
	m_CameraPosition = Characon.Execute(1.0f / 60.0f, m_moveSpeed);
	g_camera3D.SetTarget(m_CameraPosition);
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