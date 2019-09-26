#pragma once
#include "character/CharacterController.h"

class Player
{
public:
	Player();
	~Player();
	void Update();
	void Draw();
private:
	/// <summary>
	/// プレイヤーの移動処理
	/// </summary>
	void Move();
	CharacterController Characon;
	SkinModel m_model;									//スキンモデル。
	CVector3 m_position = CVector3::Zero();				//プレイヤーのポジション
};

