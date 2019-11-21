#pragma once
#include "character/CharacterController.h"

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
};

