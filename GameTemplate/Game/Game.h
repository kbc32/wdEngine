#pragma once
#include "IGameObject.h"
#include "Player.h"
#include "Map.h"
#include "graphics/Camera.h"


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
	void Render();

private:

	//プレイヤー4人分
	Player player[4];
	//カメラ4人分
	//Camera g_camera3D[4];
	Map map;				//マップ
	int PadNom = 0;			//パッド番号
};

