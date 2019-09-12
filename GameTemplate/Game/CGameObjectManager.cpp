#include "stdafx.h"
#include "CGameObjectManager.h"

CGameObjectManager g_goMgr;

void CGameObjectManager::Update()
{
	//登録されているゲームオブジェクトの更新処理を呼ぶ。
	for (auto go : m_goList) {
		go->Update();
	}
	//登録されているゲームオブジェクトの描画処理を呼ぶ。
	for (auto go : m_goList) {
		go->Render();
	}
	//全てのゲームオブジェクトの1フレーム分の処理が終わってから、削除する。
	for (auto it = m_goList.begin(); it != m_goList.end();) {
		if ((*it)->IsRequestDelete()) {
			//削除リクエストを受けているので削除。
			delete* it;
			it = m_goList.erase(it);
		}
		else {
			//リクエストを受けていないの。
			it++;
		}
	}
}