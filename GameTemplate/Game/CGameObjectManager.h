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
	template <class T>
	T* FindGO(const char* objectName,bool enableErrorMessage)
	{
		unsigned int nameKey = CUtil::MakeHash(objectName);
		for (auto goList : m_gameObjectListArray) {
			for (auto go : goList) {
				if (go->m_nameKey == nameKey) {
					//�������B
					T* p = dynamic_cast<T*>(go);
					if (p == nullptr && enableErrorMessage == true) {
						//�^�ϊ��Ɏ��s�B

						TK_WARNING_MESSAGE_BOX(
							"FingGameObject �F �^�ϊ��Ɏ��s���܂����B�e���v���[�g�������m�F���Ă��������BtypeName = %s, objectName = %s",
							typeid(T).name(),
							objectName
						);
					}
					return p;
				}
			}
		}
		if (enableErrorMessage == true) {
			TK_WARNING_MESSAGE_BOX("FindGO�֐��Ɏw�肳�ꂽ���O�̃C���X�^���X�������邱�Ƃ��ł��܂���ł����B\n"
				"���O���Ԉ���Ă��Ȃ����m�F�����ĉ������B\n"
				"\n\n�������ꂽ���O �y%s�z\n", objectName);
		}
		//������Ȃ������B
		return nullptr;
	}
private:
	std::vector<IGameObject*> m_goList;
};

extern CGameObjectManager g_goMgr;
