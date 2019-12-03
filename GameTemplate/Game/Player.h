#pragma once
#include "character/CharacterController.h"
#include "PlayerCamera.h"

class Player
{
public:
	Player();
	~Player();
	/// <summary>
	/// アップデート関数
	/// </summary>
	void Update();
	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();
	/// <summary>
	/// プレイヤーの座標を取得する
	/// </summary>
	/// <returns>プレイヤーの座標</returns>
	CVector3 GetPlayerPosition();
	/// <summary>
	/// 使用するパッドの番号を設定
	/// </summary>
	/// <param name="Nom">番号</param>
	void SetPadNom(int Nom);
	/// <summary>
	/// プレイヤーの座標を設定
	/// </summary>
	/// <param name="position">移動させる座標</param>
	void SetPlayerPosition(CVector3 position);
private:
	/// <summary>
	/// プレイヤーの移動処理
	/// </summary>
	void Move();
	int PadNom;											//パッドの番号
	//プレイヤー
	CharacterController Characon;						//キャラ蔵―魂斗羅―（キャラクターコントローラー）
	SkinModel m_model;									//スキンモデル。
	CVector3 m_position = CVector3::Zero();				//プレイヤーのポジション
	CVector3 m_moveSpeed = CVector3::Zero();			//移動速度。

	CVector3 m_CameraPosition;							//カメラ座標
};

