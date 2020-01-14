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
	template <class T>
	T* FindGO(const char* objectName,bool enableErrorMessage)
	{
		unsigned int nameKey = CUtil::MakeHash(objectName);
		for (auto goList : m_gameObjectListArray) {
			for (auto go : goList) {
				if (go->m_nameKey == nameKey) {
					//見つけた。
					T* p = dynamic_cast<T*>(go);
					if (p == nullptr && enableErrorMessage == true) {
						//型変換に失敗。

						TK_WARNING_MESSAGE_BOX(
							"FingGameObject ： 型変換に失敗しました。テンプレート引数を確認してください。typeName = %s, objectName = %s",
							typeid(T).name(),
							objectName
						);
					}
					return p;
				}
			}
		}
		if (enableErrorMessage == true) {
			TK_WARNING_MESSAGE_BOX("FindGO関数に指定された名前のインスタンスを見つけることができませんでした。\n"
				"名前が間違っていないか確認をして下さい。\n"
				"\n\n検索された名前 【%s】\n", objectName);
		}
		//見つからなかった。
		return nullptr;
	}
private:
	std::vector<IGameObject*> m_goList;
};

extern CGameObjectManager g_goMgr;
