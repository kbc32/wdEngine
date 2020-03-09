#pragma once
#include "CGameObjectManager.h"
#include "Player.h"

class Player;
class PlayerCamera
{
public:
	PlayerCamera();
	~PlayerCamera();
	/// <summary>
	/// スタート関数
	/// </summary>
	void Start(int PlayerNo);
	/// <summary>
	/// アップデート関数
	/// </summary>
	void Update(int PlayerNo);

	/// <summary>
	/// プレイヤーの番号を設定
	/// </summary>
	/// <param name="Nom">番号　int型</param>
	void SetPlayerNo(int Nom);

	void SetCameraNo(int Nom);
	/// <summary>
	/// プレイヤーカメラの座標を設定する
	/// </summary>
	/// <param name="playerNo">プレイヤーの番号</param>
	void SetCameraPos(int playerNo);
private:
	Player* m_player;	//プレイヤー
	CVector3 m_toCameraPos = CVector3::Zero(); //カメラの座標

	float m_angle;
	float m_angle2;
	CQuaternion m_rotation;

	int PlayerNom = 0;	//プレイヤーの番号
	int CameraNom; //パッドの番号
	CVector3 CameraPos;	//カメラの座標
};

