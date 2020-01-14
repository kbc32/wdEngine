#pragma once
#include "IGameObject.h"
#include "physics/PhysicsStaticObject.h"

class Map:public IGameObject
{
public:
	Map();
	~Map();
	void Update();
	void Render(int cameraNo);
private:
	CQuaternion m_quarenion = { 0.0f, 0.0f, 0.0f, 1.0f };
	SkinModel m_MapModel;
	PhysicsStaticObject m_phyStaticObject;				//!<�ÓI�����I�u�W�F�N�g�B
	CVector3 m_position = { 0.0f,-150.0f,0.0f };		//�}�b�v�̍��W
};

