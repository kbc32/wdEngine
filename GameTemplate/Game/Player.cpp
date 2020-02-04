#include "stdafx.h"
#include "Player.h"
#include "HID/Pad.h"
#include "PlayerCamera.h"

int g_playerNom = 4;//プレイヤー人数

Player::Player()
{
	//プレイヤー
	//cmoファイルの読み込み。
	m_model.Init(L"Assets/modelData/unityChan.cmo");

	m_position.y += 4.0f;

	//キャラクターコントローラーの初期化
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
	//移動処理
	Move();
	//ワールド行列の更新。
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
	//視点から注視点に向かって伸びるベクトルを求める
	CVector3 cameraDir = g_camera3D[PadNom].GetTarget() -
						g_camera3D[PadNom].GetPosition();
	//yの値を消す
	cameraDir.y = 0.0f;
	//正規化
	cameraDir.Normalize();

	CVector3 cameraDirX;
	cameraDirX.Cross(cameraDir, CVector3::AxisY());

	//XZ成分の移動速度をクリア。
	m_moveSpeed.x = 0.0f;
	m_moveSpeed.z = 0.0f;
	m_moveSpeed.y -= 15.0f;				//重力;

	m_moveSpeed += cameraDirX * lStick_x * -300.0f;		//奥方向への移動速度を加算。
	m_moveSpeed += cameraDir * lStick_y * 300.0f;		//右方向への移動速度を加算。

	//キャラクターコントローラーを使用して、座標を更新。
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