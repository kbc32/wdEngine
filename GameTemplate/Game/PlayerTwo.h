#pragma once
#include "character/CharacterController.h"

class PlayerTwo
{
public:
	PlayerTwo();
	~PlayerTwo();
	void Update();
	void Draw();
	CVector3 GetPlayerPosition();
private:
	/// <summary>
	/// プレイヤーの移動処理
	/// </summary>
	void Move();
	int PadNom = 1;
	//プレイヤー
	CharacterController Characon;						//キャラ蔵―魂斗羅―（キャラクターコントローラー）
	SkinModel m_model;									//スキンモデル。
	CVector3 m_position = CVector3::Zero();				//プレイヤーのポジション
	CVector3 m_moveSpeed = CVector3::Zero();			//移動速度。
};

