#pragma once
#include "IGameObject.h"
#include <vector>

class CGameObjectManager
{
public:
	/// <summary>
	/// 更新。
	/// </summary>
	void Update();
	/// <summary>
	/// ゲームオブジェクトを追加する
	/// </summary>
	template<class T>
	T* NewGO()
	{
		//インスタンスを作成する
		T* newObj = new T;

		//作成したインスタンスを可変長列に追加する
		m_goList.push_back(newObj);

		//追加したオブジェクトを戻す
		return newObj;

	}
	/// <summary>
	/// ゲームオブジェクトをリストから削除する
	/// </summary>
	/// <param name="go"></param>
	void DeleteGO(IGameObject* go)
	{
		//引数で指定されたゲームオブジェクトを検索
		for (auto it = m_goList.begin();
			it != m_goList.end();
			it++
			)
		{
			if ((*it) == go) {
				//削除リクエストをおくる
				go->RequestDelete();
				return;
			}
		}
	}
	
	/// <summary>
	/// ゲームオブジェクトを検索する
	/// </summary>
	/// <param name="objectName">オブジェクトの名前</param>
	/// <returns></returns>
	/*template <class T>
	T* FindGO(const char* objectName)
	{

	}*/
private:
	std::vector<IGameObject*> m_goList;
};

extern CGameObjectManager g_goMgr;
