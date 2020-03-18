#pragma once
class Coin
{
public:
	Coin();
	~Coin();
	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();
	/// <summary>
	/// 描画処理
	/// </summary>
	void Render(int cameraNo);
	/// <summary>
	/// コインの座標を設定する
	/// </summary>
	/// <param name="position">座標</param>
	void SetPosition(CVector3 position);
private:
	SkinModel m_coin; //スキンモデル
	CVector3 m_position; //座標
	CQuaternion m_rotation; //回転


	
};

