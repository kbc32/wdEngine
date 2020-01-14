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
	PhysicsStaticObject m_phyStaticObject;				//!<静的物理オブジェクト。
	CVector3 m_position = { 0.0f,-150.0f,0.0f };		//マップの座標
};

