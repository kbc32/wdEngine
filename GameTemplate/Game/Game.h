#pragma once
#include "IGameObject.h"
#include "Player.h"
#include "Map.h"
#include "graphics/Camera.h"
#include "PlayerCamera.h"
#include "Weapon.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"
#include "level/Level.h"
#include "Coin.h"



class Game : public IGameObject
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Game();
	/// <summary>
	/// デストラクタ
	/// </summary>
	~Game();
	/// <summary>
	/// 更新処理。
	/// </summary>
	void Update();
	/// <summary>
	/// 描画処理。
	/// </summary>
	void Render(int cameraNo);
	static Game* GetInstance()
	{
		return m_instance;
	}
	/// <summary>
	/// プレイヤーの座標を持ってくる
	/// </summary>
	/// <param name="PlayerNo">プレイヤーの番号</param>
	/// <returns>プレイヤーの座標</returns>
	CVector3 GetPlayerPosition(int PlayerNo)
	{
		return player[PlayerNo].GetPlayerPosition();
	}
	//Camera g_camera3D;		//3Dカメラ。
private:
	CSoundEngine m_soundEngine;		//サウンドエンジン
	//プレイヤー4人分
	Player player[4];
	//武器4人分
	Weapon weapon[4];
	//プレイヤーカメラ
	PlayerCamera playercamera[4];
	//Map map;				//マップ
	int PadNom = 0;			//パッドの番号
	int CameraNom = 0;		//カメラの番号
	static Game* m_instance;
	Level m_level;
	Coin* m_coin = nullptr;

	//確認用
	CSoundSource m_se;
};

