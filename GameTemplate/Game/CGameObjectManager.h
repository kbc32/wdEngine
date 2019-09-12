#pragma once
#include "IGameObject.h"
#include <vector>

class CGameObjectManager
{
public:
	/// <summary>
	/// �X�V�B
	/// </summary>
	void Update();
	/// <summary>
	/// �Q�[���I�u�W�F�N�g��ǉ�����
	/// </summary>
	template<class T>
	T* NewGO()
	{
		//�C���X�^���X���쐬����
		T* newObj = new T;

		//�쐬�����C���X�^���X���ϒ���ɒǉ�����
		m_goList.push_back(newObj);

		//�ǉ������I�u�W�F�N�g��߂�
		return newObj;

	}
	/// <summary>
	/// �Q�[���I�u�W�F�N�g�����X�g����폜����
	/// </summary>
	/// <param name="go"></param>
	void DeleteGO(IGameObject* go)
	{
		//�����Ŏw�肳�ꂽ�Q�[���I�u�W�F�N�g������
		for (auto it = m_goList.begin();
			it != m_goList.end();
			it++
			)
		{
			if ((*it) == go) {
				//�폜���N�G�X�g��������
				go->RequestDelete();
				return;
			}
		}
	}
	
	/// <summary>
	/// �Q�[���I�u�W�F�N�g����������
	/// </summary>
	/// <param name="objectName">�I�u�W�F�N�g�̖��O</param>
	/// <returns></returns>
	/*template <class T>
	T* FindGO(const char* objectName)
	{

	}*/
private:
	std::vector<IGameObject*> m_goList;
};

extern CGameObjectManager g_goMgr;
