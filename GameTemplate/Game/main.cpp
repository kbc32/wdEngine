#include "stdafx.h"
#include "system/system.h"
#include "Player.h"
#include "level/Level.h"
#include "graphics/Camera.h"
#include "CGameObjectManager.h"
#include "Map.h"
#include "Game.h"


///////////////////////////////////////////////////////////////////
// ウィンドウプログラムのメイン関数。
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//ゲームの初期化。
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, "Game");

	//カメラを初期化。
	for (int cameraNo = 0; cameraNo < 4; cameraNo++) {
		g_camera3D[cameraNo].SetPosition({ 0.0f, 100.0f, 300.0f });
		g_camera3D[cameraNo].SetTarget({ 0.0f, 100.0f, 0.0f });
		g_camera3D[cameraNo].SetFar(10000.0f);
	}

	//ゲームクラスを作成
	Game m_game;

	//ゲームループ。
	while (DispatchWindowMessage() == true)
	{
		//GameObjectの更新
		g_goMgr.Update();
		
			
		//描画開始。
		g_graphicsEngine->BegineRender();

		//４画面分割描画処理
		for (int cameraNo = 0; cameraNo < 4; cameraNo++)
		{
			//書き込むビューポートを設定
			g_graphicsEngine->SetViewport(cameraNo);
			//ゲームパッドの更新。	
			for (auto& pad : g_pad) {
				pad.Update();
			}
			//ゲームクラスの描画
			m_game.Render(cameraNo);
			
		}

		//物理エンジンの更新。
		g_physics.Update();
		
		//ゲームクラスの更新
		m_game.Update();
		//描画終了。
		g_graphicsEngine->EndRender();
	}
}