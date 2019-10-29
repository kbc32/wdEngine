#include "stdafx.h"
#include "Map.h"


Map::Map()
{
	//cmo�t�@�C���̓ǂݍ��݁B
	m_MapModel.Init(L"Assets/modelData/Map001.cmo");
	m_quarenion.SetRotationDeg(CVector3::AxisX(), 90.0f);
}


Map::~Map()
{
}

void Map::Update()
{
	//���[���h�s��̍X�V�B
	m_MapModel.UpdateWorldMatrix(m_position, m_quarenion, m_size);
}

void Map::Render()
{
	m_MapModel.Draw(
		g_camera3D.GetViewMatrix(),
		g_camera3D.GetProjectionMatrix()
	);
}
