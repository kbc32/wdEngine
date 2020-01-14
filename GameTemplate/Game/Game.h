#pragma once
#include "IGameObject.h"
#include "Player.h"
#include "Map.h"
#include "graphics/Camera.h"
#include "PlayerCamera.h"


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
	//Camera g_camera3D;		//3Dカメラ。
private:
	
	//プレイヤー4人分
	Player player[4];
	//プレイヤーカメラ
	PlayerCamera playercamera[4];
	Map map;				//マップ
	int PadNom = 0;			//パッドの番号
	int CameraNom = 0;		//カメラの番号
};

