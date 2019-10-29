#pragma once
#include "IGameObject.h"
#include "Player.h"
#include "Map.h"

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
	
	Player player;			//プレイヤー
	Map map;				//マップ
};

