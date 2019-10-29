#pragma once
#include "IGameObject.h"

class Map:public IGameObject
{
public:
	Map();
	~Map();
	void Update();
	void Render();
private:
	CQuaternion m_quarenion = { 0.0f, 0.0f, 0.0f, 1.0f };
	SkinModel m_MapModel;
	CVector3 m_position = { 0.0f,-100.0f,0.0f };		//マップの座標
	CVector3 m_size = { 3.0f,3.0f,3.0f };
};

